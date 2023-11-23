#include "buttons.h"


void handlerButton0() {
    if(flag_button_pressed_0) {
        Serial.println("button 0 pressed");
        flag_button_pressed_0 = false;
        if(buttonState) {
            buttIncrementClock();
        }
    }
}

void handlerButton1() {
    if(flag_button_pressed_1) {
        Serial.println("button 1 pressed");
        buttonState++;
        if(buttonState > 3) {
            buttonState = 0;
        }
        flag_button_pressed_1 = false;
        Serial.print("Bs: ");
        Serial.println(buttonState);
    }
}
