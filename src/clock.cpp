#include "clock.h"
#include "lcd.h"
#include "interrupts.h"

void displayClock(const uint8_t &h, const uint8_t &m, const uint8_t &s) {
        char p_clock[9];
        intToChar(p_clock, 0, h);
        p_clock[2] = ':';
        intToChar(p_clock, 3, m);
        p_clock[5] = ':';
        intToChar(p_clock, 6, s);
        writeString(p_clock, 2, Center);
        flag_update_clock = false;
}

void displayClock2(const uint8_t &h, const uint8_t &m, const uint8_t &s) {
    char p_clock[3];
    intToChar(p_clock, 0, h);
    writeString(p_clock, 2, 7);
    writeString({":"});
    intToChar(p_clock, 0, m);
    writeString(p_clock);
    writeString({":"});
    intToChar(p_clock, 0, s);
    writeString(p_clock);
}

void intToChar(char *p_char, uint8_t offset, const uint8_t val) {
    uint8_t units = val%10;
    p_char[offset + 1] = '0' + units;
    if(val > 10) {
        p_char[offset + 0] = '0' + val/10 - units;
    }
    else {
        p_char[offset + 0] = '0';
    }
}