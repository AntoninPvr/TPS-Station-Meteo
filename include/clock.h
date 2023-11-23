#ifndef CLOCK_H
#define CLOCK_H

#include <Arduino.h>

extern volatile uint8_t h = 0;
extern volatile uint8_t m = 0;
extern volatile uint8_t s = 0;
bool blink = false;

void displayClock();
void displayClock2();
void intToChar(char *p_char, uint8_t offset, uint8_t val);
void incrementClock();
void buttIncrementClock();
void selectedMask();
void handlerDisplayClock();

#endif //CLOCK_H