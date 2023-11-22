#include <interrupts.h>

#define PIN_B0 2
#define PIN_B1 3

volatile bool flag_button_pressed_0 = false;
volatile bool flag_button_pressed_1 = false;
volatile uint8_t postscaler = 0;

void setupInterrupts() {
    noInterrupts();
    TCCR2A &= 0b11111100;
    TCCR2B |= 0b11110111;
    TIMSK2 |= 0b00000001;
    
    pinMode(PIN_B0, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(PIN_B0), button0, FALLING);
    pinMode(PIN_B1, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(PIN_B1), button1, FALLING);
    interrupts();
}

void button0() {
    flag_button_pressed_0 = true;
}

void button1() {
    flag_button_pressed_1 = true;
}

void handlerButton0() {
    if(flag_button_pressed_0) {
        Serial.println("button 0 pressed");
        flag_button_pressed_0 = false;
    }
}

void handlerButton1() {
    if(flag_button_pressed_1) {
        Serial.println("button 1 pressed");
        flag_button_pressed_1 = false;
    }
}

ISR(TIMER2_OVF_vect) {
    TCNT2 = 131;
    if (postscaler<125) {
        postscaler++;
    }
    else {
        postscaler = 0;
        Serial.println("Message Timer");
    }
}
