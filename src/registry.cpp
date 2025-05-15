#include "config.h"

const char* appNames[] = {
  "Boxes",
  "Blackjack",
  "Calculator",
  "XP",
  "Sleep",
  "Settings"
};

const int appCount = sizeof(appNames) / sizeof(appNames[0]);

void (*gameLoops[])() = {boxesLoop, blackJackLoop, calcLoop, xpLoop, deepSleepLoop, settingsLoop};
void (*LPress[])() = {boxLPress, bjLPress, calcLPress, xpLPress, deepSleepLPress, sLPress};
void (*MPress[])() = {boxMPress, bjMPress, calcMPress, xpMPress, deepSleepMPress, sMPress};
void (*RPress[])() = {boxRPress, bjRPress, calcRPress, xpRPress, deepSleepRPress, sRPress};

char* notification;

int currentApp = -1;