#include "config.h"
#include <WiFi.h>
extern void about();
extern void displayConfLoop();
extern void flip();

int selectedSetting = 0;
int openSetting = -1;
int settingsBelow = 0;

const char* settingsOptions[]{
  "About",
  "Display",
  "Airplane Mode",
  "Factory Reset",
  "Reboot",
  "",
  ""
};

const int settingsCount = sizeof(settingsOptions) / sizeof(settingsOptions[0]);

void settingsLoop(){
  if (openSetting == -1){
    display.fillRect(10, 5, SCREEN_WIDTH - 10, 14, COLOR);
    display.drawRect(10, 24, SCREEN_WIDTH - 10, 14, COLOR);
    display.drawRect(10, 42, SCREEN_WIDTH - 10, 14, COLOR);
    display.setCursor(12, 8);
    display.setTextColor(BLACK);
    display.print(settingsOptions[selectedSetting]);
    display.setCursor(12, 27);
    display.setTextColor(COLOR);
    display.print(settingsOptions[selectedSetting + 1]);
    display.setCursor(12, 46);
    display.print(settingsOptions[selectedSetting + 2]);
  }
  
  if (openSetting == 0){
    about();
  }
  if (openSetting == 1){
    displayConfLoop();
  }
  if(openSetting == 2){
    prefs.begin("System");
    if(prefs.getBool("Airplane") == false){
      prefs.putBool("Airplane", true);
    }
    else{
      prefs.putBool("Airplane", false);
    }
  }
  if(openSetting == 3){
    prefs.begin("System", false);
    prefs.clear();
    prefs.end();
  }
  if(openSetting == 4){
    ESP.restart();
  }
}

void sLPress(){
  if (selectedSetting != 0){
    selectedSetting--;
  }
}

void sMPress(){
  if(openSetting == -1){
    openSetting = selectedSetting;
  }
  if(openSetting == 1){
    flip();
  }
}

void sRPress(){
  if (selectedSetting != settingsCount - 3){
    selectedSetting++;
  }
}