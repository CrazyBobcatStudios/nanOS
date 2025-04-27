#include "config.h"
extern int openSetting;

void displayConfLoop(){
    display.setCursor(5,5);
    display.print("Press Middle to flip display");
    if(digitalRead(MIDDLE_BUTTON) == LOW){
        if (display.getRotation() == 0){
            display.setRotation(180);
        }
        else{
            display.setRotation(0);
        }
    }
    if(digitalRead(LEFT_BUTTON) == LOW){
        openSetting = -1;
    }
}