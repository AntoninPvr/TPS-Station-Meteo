#include "interrupts.h"
#include "clock.h"

void setupInterrupts() {
    noInterrupts();
    TCCR2A &= 0b11111100; 
    TCCR2B |= 0b11110111; //1024 prescaler
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
        s++;
        if (s>=60) {
            s = 0;
            m++;
            if (m>=60) {
                m = 0;
                h++;
                if (h>=24) {
                    h = 24;
                }
            }
        }
        flag_update_clock = true;
        blink != blink;
    }
}
