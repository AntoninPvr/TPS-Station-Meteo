#include "clock.h"
#include "lcd.h"
#include "interrupts.h"
#include "buttons.h"
#include "global.h"

void displayClock() {
        char p_clock[] = "  :  :  ";
        if((buttonState!=3) || (blink)) {
            intToChar(p_clock, 0, h);
        }
        if((buttonState!=2) || (blink)) {
            intToChar(p_clock, 3, m);
        }
        if((buttonState!=1) || (blink)) {
            intToChar(p_clock, 6, s);
        }
        writeString(p_clock, 1, 7);
        flag_update_clock = false;
}

void displayClock2() {
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

void intToChar(char *p_char, uint8_t offset, uint8_t val) {
    uint8_t units = val%10;
    p_char[offset + 1] = '0' + units;
    if(val >= 10) {
        p_char[offset + 0] = '0' + val/10;
    }
    else {
        p_char[offset + 0] = '0';
    }
}

void incrementClock() {
    s++;
    if (s>=60) {
        s = 0;
        m++;
        if (m>=60) {
            m = 0;
            h++;
            if (h>=24) {
                h = 0;
            }
        }
    }
}

void buttIncrementClock() {
    switch(buttonState) {
        case 1:
            s++;
            goto second;
        case 2:
            m++;
            goto minute;
        case 3:
            h++;
            goto hour;
    }
    second:
    if(s>=60) {
        s %= 60;
        m++;
    }
    minute:
    if(m>=60) {
        m %= 60;
        h++;
    }
    hour:
    if(h>=24) {
        h %= 24;
    }
}

void handlerDisplayClock() {
    if(flag_update_clock) {
        flag_update_clock = false;
        displayClock();
    }
}