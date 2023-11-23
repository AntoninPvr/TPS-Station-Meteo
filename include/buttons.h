#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>

uint8_t buttonState = 0;

volatile bool flag_button_pressed_0 = false; //volatile to avoid compiler optimization
volatile bool flag_button_pressed_1 = false;

void handlerButton0();
void handlerButton1();

#endif //BUTTONS_H