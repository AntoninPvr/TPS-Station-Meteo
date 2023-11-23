#include "interrupts.h"
#include "clock.h"
#include "buttons.h"

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

ISR(TIMER2_OVF_vect) {
    TCNT2 = 131;
    if (postscaler<125) {
        postscaler++;
    }
    else {
        postscaler = 0;
        incrementClock();
        flag_update_clock = true;
        blink = !blink;
    }
}
