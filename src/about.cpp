#include "config.h"
extern int openSetting;

int selectedAOption = 0;
String aboutOptions[]{
  "Exit",
  "nanOS version WIP 0.0.5",
  String("Screen Height: ") + SCREEN_HEIGHT,
  String("Screen Width: ") + SCREEN_WIDTH,
  String(ESP.getChipModel()),
  String("ESP SDK: ") + String(ESP.getSdkVersion()),
  "",
  ""
};

void about(){
  display.fillRect(10, 5, SCREEN_WIDTH - 10, 14, COLOR);
  display.drawRect(10, 24, SCREEN_WIDTH - 10, 14, COLOR);
  display.drawRect(10, 42, SCREEN_WIDTH - 10, 14, COLOR);
  display.setCursor(12, 8);
  display.setTextColor(BLACK);
  display.print(aboutOptions[selectedAOption]);
  display.setCursor(12, 27);
  display.setTextColor(COLOR);
  display.print(aboutOptions[selectedAOption + 1]);
  display.setCursor(12, 46);
  display.print(aboutOptions[selectedAOption + 2]);
}
void aLPress(){
  if(selectedAOption != 0){
    selectedAOption--;
  }
}
void aMPress(){
  if(selectedAOption == 0){
    openSetting = -1;
  }
}
void aRPress(){
  if(selectedAOption < 5){
    selectedAOption++;
  }
}