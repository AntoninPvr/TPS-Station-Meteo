#ifndef CLOCK_H
#define CLOCK_H

#include <Arduino.h>

volatile uint8_t h = 0;
volatile uint8_t m = 0;
volatile uint8_t s = 0;
bool blink = false;

void displayClock(const uint8_t &h, const uint8_t &m, const uint8_t &s);
void displayClock2(const uint8_t &h, const uint8_t &m, const uint8_t &s);
void intToChar(char *p_char, uint8_t offset, const uint8_t val);

#endif //CLOCK_H