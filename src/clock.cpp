#include "clock.h"
#include "lcd.h"
#include "interrupts.h"
#include "buttons.h"

void displayClock() {
        char p_clock[9];
        intToChar(p_clock, 0, h);
        p_clock[2] = ':';
        intToChar(p_clock, 3, m);
        p_clock[5] = ':';
        intToChar(p_clock, 6, s);
        writeString(p_clock, 2, Center);
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

void intToChar(char *p_char, uint8_t offset,uint8_t val) {
    uint8_t units = val%10;
    p_char[offset + 1] = '0' + units;
    if(val > 10) {
        p_char[offset + 0] = '0' + val/10 - units;
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

void selectedMask() {
    if(blink) {
        switch (buttonState)
        {
        case 1:
            setLCDPostion(2, 7);
            break;
        case 2:
            setLCDPostion(2, 10);
            break;
        case 3:
            setLCDPostion(2, 13);
            break;
        writeString("  ");
        }
    }
}

void handlerDisplayClock() {
    if(flag_update_clock) {
        flag_update_clock = false;
        displayClock();
        if(buttonState) {
            selectedMask();
        }
    }
}