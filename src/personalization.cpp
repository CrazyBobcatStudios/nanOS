#include "config.h"
extern int order[];

int selectedMenuItem = 0;

void personalizationLoop(){
  display.fillRect(10, 5, SCREEN_WIDTH - 10, 14, COLOR);
  display.drawRect(10, 24, SCREEN_WIDTH - 10, 14, COLOR);
  display.drawRect(10, 42, SCREEN_WIDTH - 10, 14, COLOR);
  display.setCursor(12, 8);
  display.setTextColor(BLACK);
  display.print(appNames[order[selectedMenuItem]]);
  display.setCursor(12, 27);
  display.setTextColor(COLOR);
  display.print(appNames[order[selectedMenuItem + 1]]);
  display.setCursor(12, 46);
  display.print(appNames[order[selectedMenuItem + 2]]);
}

void personalizationLPress(){
  selectedMenuItem--;
}

void personalizationMPress(){
  
}

void personalizationRPress(){
  selectedMenuItem++;
}