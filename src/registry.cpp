#include "config.h"

const char* appNames[] = {
  "Boxes",
  "Blackjack",
  "Calculator",
  "Settings"
};

const int appCount = sizeof(appNames) / sizeof(appNames[0]);

void (*gameLoops[])() = {boxesLoop, blackJackLoop, calcLoop, settingsLoop};
void (*LPress[])() = {boxLPress, bjLPress, calcLPress, sLPress};
void (*MPress[])() = {boxMPress, bjMPress, calcMPress, sMPress};
void (*RPress[])() = {boxRPress, bjRPress, calcRPress, sRPress};

char* notification;

int currentApp = -1;