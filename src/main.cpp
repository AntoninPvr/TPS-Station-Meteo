#include <Arduino.h>
#include <SPI.h>
#include "lcd.h"
#include "interrupts.h"
#include "buttons.h"
#include "clock.h"
#include "global.h"

volatile uint8_t h = 0;
volatile uint8_t m = 0;
volatile uint8_t s =0;
volatile bool flag_update_clock = false;

bool blink = false;
uint8_t buttonState = 0;
volatile bool flag_button_pressed_0 = false;
volatile bool flag_button_pressed_1 = false;
volatile uint8_t postscaler = 0;

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
