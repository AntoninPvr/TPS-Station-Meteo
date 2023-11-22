#ifndef LCD_H
#define LCD_H

#include <Arduino.h>
#include <SPI.h>

void sendLCDCommand(uint8_t trame);
void sendLCDData(uint8_t data);
void setupLCD();
void setLCDPostion(uint8_t line, uint8_t column);
void writeString(char *p_char, uint8_t line, uint8_t column);

#endif //LCD_H