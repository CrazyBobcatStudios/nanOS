#include "config.h"
extern int openSetting;

void about(){
    display.setTextColor(COLOR);
    display.setCursor(0,0);
    display.println("nanOS version 0.0.1");
    display.println("Screen Height " + String(SCREEN_HEIGHT));
    display.println("Screen Width " + String(SCREEN_WIDTH));
    display.printf("%s revision %d\n", ESP.getChipModel(), ESP.getChipRevision());
    display.printf("ESP SDK: %s", ESP.getSdkVersion());
    if(digitalRead(LEFT_BUTTON) == LOW){
        openSetting = -1;
    }
}