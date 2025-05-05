#include "config.h"

const char* appNames[] = {
  "Boxes",
  "Blackjack",
  "Calculator",
  "Sleep",
  "Settings"
};

const int appCount = sizeof(appNames) / sizeof(appNames[0]);

void (*gameLoops[])() = {boxesLoop, blackJackLoop, calcLoop, deepSleepLoop, settingsLoop};
void (*LPress[])() = {boxLPress, bjLPress, calcLPress, deepSleepLPress, sLPress};
void (*MPress[])() = {boxMPress, bjMPress, calcMPress, deepSleepMPress, sMPress};
void (*RPress[])() = {boxRPress, bjRPress, calcRPress, deepSleepRPress, sRPress};

char* notification;

int currentApp = -1;