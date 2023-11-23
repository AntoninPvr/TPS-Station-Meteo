#ifndef LCD_H
#define LCD_H

#include <Arduino.h>
#include <SPI.h>
#include "bitUtils.h"

#define LINE_NBR 4
#define COLUMN_NBR 20

enum Justification {
    Left,
    Right,
    Center
};

void sendLCDCommand(uint8_t trame);
void sendLCDData(uint8_t data);
void setupLCD();
void setLCDPostion(uint8_t line, uint8_t column);
void writeString(char *p_char, uint8_t line, uint8_t column);
void writeString(char *p_char);
void writeString(char *p_char, uint8_t line, enum Justification justify);
void clearLCD();

#endif //LCD_H