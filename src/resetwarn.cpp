#include "config.h"

int selectedRWOption = 0;
extern int openSetting;

void rwLoop(){
  if (selectedRWOption == 0){
    display.setCursor(0,0);
    display.setTextColor(COLOR);
    display.print("Are you sure you want to reset?\nThis action cannot be undone");
    display.fillRect(5, 35, (SCREEN_WIDTH/2 - 10), SCREEN_HEIGHT - 40, COLOR);
    display.setTextColor(BLACK);
    display.setCursor(20, 45);
    display.print("No");
    display.setTextColor(COLOR);
    display.setCursor(85, 45);
    display.print("Yes");
    display.drawRect((SCREEN_WIDTH/2) + 10, 35, SCREEN_WIDTH/2 - 15, SCREEN_HEIGHT - 40, COLOR);
  }
  else{
    display.setCursor(0,0);
    display.setTextColor(COLOR);
    display.print("Are you sure you want to reset?\nThis action cannot be undone");
    display.drawRect(5, 35, (SCREEN_WIDTH/2 - 10), SCREEN_HEIGHT - 40, COLOR);
    display.setTextColor(COLOR);
    display.setCursor(20, 45);
    display.print("No");
    display.setTextColor(BLACK);
    display.setCursor(85, 45);
    display.fillRect((SCREEN_WIDTH/2) + 10, 35, SCREEN_WIDTH/2 - 15, SCREEN_HEIGHT - 40, COLOR);
    display.print("Yes");
  }
}

void rwLPress(){
  if(selectedRWOption == 1){
    selectedRWOption = 0;
  }
  else{
    selectedRWOption = 1;
  }
}

void rwMPress(){
  if(selectedRWOption == 1){
    selectedRWOption = 0;
  }
  else{
    openSetting = -1;
  }
}