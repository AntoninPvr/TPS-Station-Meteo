#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <Arduino.h>

void setupInterrupts();
void button0();
void button1();
void handlerButton0();
void handlerButton1();
ISR(TIMER0_OVF_vect);

#endif //INTERRUPTS_H