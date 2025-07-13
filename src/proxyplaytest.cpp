#include "config.h"

extern int openSetting;
int selectedPPSetting = 0;
const char* settingsPPOptions[]{
  "Exit",
  "Refresh",
  "",
  ""
};

void pptRefresh(){
  
}

void ppTestLoop(){
  display.fillRect(10, 5, SCREEN_WIDTH - 10, 14, COLOR);
  display.drawRect(10, 24, SCREEN_WIDTH - 10, 14, COLOR);
  display.drawRect(10, 42, SCREEN_WIDTH - 10, 14, COLOR);
  display.setCursor(12, 8);
  display.setTextColor(BLACK);
  display.print(settingsPPOptions[selectedPPSetting]);
  display.setCursor(12, 27);
  display.setTextColor(COLOR);
  display.print(settingsPPOptions[selectedPPSetting + 1]);
  display.setCursor(12, 46);
  display.print(settingsPPOptions[selectedPPSetting + 2]);
}

void ppTestLPress(){
  
}

void ppTestMPress(){
  Serial.println("ppTestMPress called");
  if(selectedPPSetting == 0){
    Serial.println("Going back to settings");
    openSetting = -1;
  }
}

void ppTestRPress(){
  
}