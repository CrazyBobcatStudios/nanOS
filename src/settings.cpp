#include "config.h"
#include <WiFi.h>
extern void about();
extern void displayConfLoop();

int selectedSetting = 0;
int openSetting = -1;
int settingsBelow = 0;

const char* settingsOptions[]{
  "About",
  "Display",
  "Power Off",
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

}

void sLPress(){
  if (selectedSetting != 0){
    selectedSetting--;
  }
}

void sMPress(){
  openSetting = selectedSetting;
}

void sRPress(){
  if (selectedSetting != settingsCount - 3){
    selectedSetting++;
  }
}