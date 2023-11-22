#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <Arduino.h>

#define PIN_B0 2
#define PIN_B1 3

volatile bool flag_update_clock = false;
volatile uint8_t postscaler = 0;

void setupInterrupts();
void button0();
void button1();
ISR(TIMER0_OVF_vect);

#endif //INTERRUPTS_H