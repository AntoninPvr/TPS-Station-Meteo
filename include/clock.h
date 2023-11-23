#ifndef CLOCK_H
#define CLOCK_H

#include <Arduino.h>

void displayClock();
void displayClock2();
void intToChar(char *p_char, uint8_t offset, uint8_t val);
void incrementClock();
void buttIncrementClock();
void handlerDisplayClock();

#endif //CLOCK_H