#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <Arduino.h>
#include "clock.h"
#include "buttons.h"
#include "global.h"

#define PIN_B0 2
#define PIN_B1 3

void setupInterrupts();
void button0();
void button1();
ISR(TIMER0_OVF_vect);

#endif //INTERRUPTS_H