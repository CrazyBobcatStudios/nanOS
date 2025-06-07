#include "config.h"

void (*gameLoops[])() = {boxesLoop, blackJackLoop, calcLoop, xpLoop, personalizationLoop, deepSleepLoop, settingsLoop};
void (*LPress[])() = {boxLPress, bjLPress, calcLPress, xpLPress, personalizationLPress, deepSleepLPress, sLPress};
void (*MPress[])() = {boxMPress, bjMPress, calcMPress, xpMPress, personalizationMPress, deepSleepMPress, sMPress};
void (*RPress[])() = {boxRPress, bjRPress, calcRPress, xpRPress, personalizationRPress, deepSleepRPress, sRPress};

const char* notification;


int currentApp = -1;