#include "config.h"
#include <WiFi.h>
extern void displayConfLoop();
extern void flip();

extern void about();
extern void aLPress();
extern void aMPress();
extern void aRPress();


extern void rwLoop();
extern void rwLPress();
extern void rwMPress();

extern void ppTestLoop();
extern void ppTestLPress();
extern void ppTestMPress();
extern void ppTestRPress();

int selectedSetting = 0;
int openSetting = -1;

const char* settingsOptions[]{
  "About",
  "Display",
  "ProxyPlay",
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
    ppTestLoop();
  }
  if(openSetting == 3){
    rwLoop();
  }
  if(openSetting == 4){
    ESP.restart();
  }
}

void sLPress(){
  if (openSetting == -1 && selectedSetting != 0){
    selectedSetting--;
  }

  if(openSetting == 0){
    aLPress();
  }

  if(openSetting == 2){
    ppTestLPress();
  }

  if(openSetting == 3){
    rwLPress();
  }
}

void sMPress(){
  if(openSetting == -1){
    openSetting = selectedSetting;
  }
  else{
    if(openSetting == 0){
      aMPress();
    }
    if(openSetting == 2){
      ppTestMPress();
    }
    if(openSetting == 3){
      rwMPress();
    }
    if(openSetting == 1){
      flip();
    }
  }
}

void sRPress(){
  if (openSetting == -1 && selectedSetting < settingsCount - 3){
    selectedSetting++;
  }
  if(openSetting == 0){
    aRPress();
  }
  if(openSetting == 3){
    rwLPress();
  }
  if(openSetting == 2){
    ppTestRPress();
  }
}