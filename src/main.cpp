#include <Arduino.h>
#include <SPI.h>
#include "lcd.h"
#include "interrupts.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
  setupLCD();
  setupInterrupts();
}

void loop() {
  // put your main code here, to run repeatedly:
  writeString("May the forcE", 1, 4);
  writeString("be with you...", 2, 6);
  handlerButton0();
  handlerButton1();
  delay(1000);
}
