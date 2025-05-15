#include "config.h"

int xp;
int level;
int progress;
int barWidth;

void xpInit() {
  prefs.begin("System", true);
  xp = prefs.getInt("XP", -1);
  prefs.end();

  if (xp < 0) {
    xp = 0;
    prefs.begin("System", false);
    prefs.putInt("XP", xp);
    prefs.end();
  }

  level = xp / 1000;
  progress = xp % 1000;
  barWidth = (SCREEN_WIDTH - 20) * progress / 1000;
}

int getXP(){
  return xp;
}

void xpLoop(){
  display.setCursor(10, 0);
  display.print("Level ");
  display.print(level);
  display.setCursor(10, 10);
  display.print(1000 - progress);
  display.print("xp to next level");
  display.drawRect(10, 20, SCREEN_WIDTH - 20, 15, COLOR);
  display.fillRect(10, 20, barWidth, 15, COLOR);
  Serial.print(xp);
}

void giveXP(int amount){
  xp += amount;
  Serial.print(xp);
  prefs.begin("System", false);
  prefs.putInt("XP", xp);
  prefs.end();
  level = xp / 1000;
  progress = xp % 1000;
  barWidth = (SCREEN_WIDTH - 20) * progress / 1000;
}
void xpLPress(){
  
}

void xpMPress(){
}

void xpRPress(){
  
}
