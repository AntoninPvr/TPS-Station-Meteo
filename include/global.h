#ifndef GLOBAL_H
#define GLOBAL_H

#include <Arduino.h>

extern volatile uint8_t h;
extern volatile uint8_t m ;
extern volatile uint8_t s ;
extern volatile bool flag_update_clock;
extern volatile uint16_t postscaler;
extern volatile uint8_t postscalerBlink;

extern bool blink;
extern uint8_t buttonState;
extern volatile bool flag_button_pressed_0;
extern volatile bool flag_button_pressed_1;

#endif //GLOBAL_H