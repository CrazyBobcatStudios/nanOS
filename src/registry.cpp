#include "config.h"

const char* appNames[] = {
  "Boxes",
  "Blackjack",
  "Calculator",
  "XP",
  "Customization",
  "Sleep",
  "Settings"
};

const int appCount = sizeof(appNames) / sizeof(appNames[0]);

void (*gameLoops[])() = {boxesLoop, blackJackLoop, calcLoop, xpLoop, personalizationLoop, deepSleepLoop, settingsLoop};
void (*LPress[])() = {boxLPress, bjLPress, calcLPress, xpLPress, personalizationLPress,deepSleepLPress, sLPress};
void (*MPress[])() = {boxMPress, bjMPress, calcMPress, xpMPress, personalizationMPress,deepSleepMPress, sMPress};
void (*RPress[])() = {boxRPress, bjRPress, calcRPress, xpRPress, personalizationRPress,deepSleepRPress, sRPress};

const char* notification;

const char* wifissid = "ssid";
const char* wifipassword = "password";

int currentApp = -1;