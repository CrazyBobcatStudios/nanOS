#include "config.h"
extern int order[];

int selectedMenuItem = 0;
int reordering = 0;
int pickedUpIndex;

void personalizationLoop(){
  if (reordering == 0){
    display.fillRect(10, 5, SCREEN_WIDTH - 10, 14, COLOR);
    display.drawRect(10, 24, SCREEN_WIDTH - 10, 14, COLOR);
    display.drawRect(10, 42, SCREEN_WIDTH - 10, 14, COLOR);
    display.setCursor(12, 8);
    display.setTextColor(BLACK);
    display.print(appNames[order[selectedMenuItem]]);
    display.setCursor(12, 27);
    if(selectedMenuItem + 1 < appCount){
      display.setTextColor(COLOR);
      display.print(appNames[order[selectedMenuItem + 1]]);
    }
    if(selectedMenuItem + 2 < appCount){
      display.setCursor(12, 46);
      display.print(appNames[order[selectedMenuItem + 2]]);
    }
  }
  else{
    display.drawRect(10, 5, SCREEN_WIDTH - 10, 14, COLOR);
    display.fillRect(10, 24, SCREEN_WIDTH - 10, 14, COLOR);
    display.drawRect(10, 42, SCREEN_WIDTH - 10, 14, COLOR);
    if (selectedMenuItem > 0) {
      display.setCursor(12, 8);
      display.setTextColor(COLOR);

      int topIndex = selectedMenuItem - 1;
      if (topIndex == pickedUpIndex) {
        topIndex += (pickedUpIndex < selectedMenuItem) ? 1 : -1;
      }

      if (topIndex >= 0 && topIndex < appCount) {
        display.print(appNames[order[topIndex]]);
      }
    }
    
    display.setCursor(12, 27);
    display.setTextColor(BLACK);
    display.print(appNames[order[pickedUpIndex]]);

    if (selectedMenuItem + 1 < appCount) {
      display.setCursor(12, 46);
      display.setTextColor(COLOR);

      int bottomIndex = selectedMenuItem + 1;
      if (bottomIndex == pickedUpIndex) {
        bottomIndex += (pickedUpIndex > selectedMenuItem) ? -1 : 1;
      }

      if (bottomIndex < appCount) {
        display.print(appNames[order[bottomIndex]]);
      }
  }
  }
}

void personalizationLPress(){
  if(selectedMenuItem > 0){
    selectedMenuItem--;
  }
}

void personalizationMPress(){
  if (reordering == 0){
    pickedUpIndex = selectedMenuItem;
    reordering = 1;
  }
  else{
    if (pickedUpIndex != selectedMenuItem) {
      int temp = order[pickedUpIndex];

      if (pickedUpIndex < selectedMenuItem) {
        for (int i = pickedUpIndex; i < selectedMenuItem; i++) {
          order[i] = order[i + 1];
        }
      } else {
        for (int i = pickedUpIndex; i > selectedMenuItem; i--) {
          order[i] = order[i - 1];
        }
      }

      order[selectedMenuItem] = temp;
    }

    reordering = 0;
    prefs.begin("app-order", false);
    for (int i = 0; i < appCount; i++) {
      prefs.putInt(String(i).c_str(), order[i]);
    }
    prefs.end();
  }
}

void personalizationRPress(){
  if(selectedMenuItem < appCount - 1){
    selectedMenuItem++;
  }
}