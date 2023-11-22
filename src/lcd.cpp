#include "lcd.h"
#include "bitUtils.h"

void sendLCDCommand(uint8_t command) {
    uint8_t first = firstBit(command);
    uint8_t last = lastBit(command);
    SPI.transfer(0xF8);
    SPI.transfer(first);
    SPI.transfer(last);
}

void sendLCDData(uint8_t data) {
    uint8_t first = firstBit(data);
    uint8_t last = lastBit(data);  
    SPI.transfer(0xFA);
    SPI.transfer(first);
    SPI.transfer(last);
}

void setupLCD() {
    sendLCDCommand(0b00000001); //clear
    sendLCDCommand(0b00101010); //RE=1, N=0, BE=0, REV=0
    sendLCDCommand(0b00001001); //FW=0, BW=0, NW=1
    sendLCDCommand(0b00000110); //BDC=1, BDS=0
    sendLCDCommand(0b00101000); //N=1, RE=0
    sendLCDCommand(0b00001111); //D=1, C=1, B=1
    sendLCDCommand(0b00000001); //clear
    delay(250);
}

void setLCDPostion(uint8_t line, uint8_t column) {
    sendLCDCommand(line*0x20 + column + 0x80);
}

void writeString(char *p_char, uint8_t line, uint8_t column) {
    setLCDPostion(line, column);
    uint8_t i = 0;
    while(p_char[i] != NULL) {
        sendLCDData(p_char[i]);
        i++;
    }
}

void writeString(char *p_char)   {
    uint8_t i = 0;
    while(p_char[i] != NULL) {
        sendLCDData(p_char[i]);
        i++;
    }
}

void writeString(char *p_char, uint8_t line, enum Justification justify) {
    uint8_t size = 0;
    uint8_t offset = 0;
    while(p_char[size] != NULL) {
        size++;
    }
    switch (justify)
    {
    case Left:
        offset = 0;
        break;
    case Right:
        offset = COLUMN_NBR - size;
        break;
    case Center:
        offset = COLUMN_NBR/2 - size/2;
        break;    
    default:
        break;
    writeString(p_char, line, offset);
    }
}