#include "config.h"
extern int openSetting;

void flip(){
  if (display.getRotation() == 0){
    display.setRotation(2);
  }
  else{
    display.setRotation(0);
  }  
}
void displayConfLoop(){
  display.setCursor(5,5);
  display.print("Press Middle to flip display");
  if(digitalRead(LEFT_BUTTON) == LOW){
    prefs.begin("System", false);
    if (display.getRotation() == 0){
      prefs.putBool("Flipped", false);
    }

    else{
      prefs.putBool("Flipped", true);
    }
    prefs.end();
    openSetting = -1;
    
  }
}