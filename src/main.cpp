#include <Arduino.h>
#include <SPI.h>
#include "lcd.h"
#include "interrupts.h"
#include "buttons.h"
#include "clock.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
  setupLCD();
  setupInterrupts();
  writeString("May the forcE", 1, 4);
  writeString("be with you...", 2, 6);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  handlerButton0();
  handlerButton1();
  handlerDisplayClock();
}
