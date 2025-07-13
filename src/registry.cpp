#include "config.h"

void (*gameLoops[])() = {boxesLoop, blackJackLoop, snekLoop, calcLoop, xpLoop, personalizationLoop, deepSleepLoop, settingsLoop};
void (*LPress[])() = {boxLPress, bjLPress, SnekLPress, calcLPress, xpLPress, personalizationLPress, deepSleepLPress, sLPress};
void (*MPress[])() = {boxMPress, bjMPress, SnekMPress, calcMPress, xpMPress, personalizationMPress, deepSleepMPress, sMPress};
void (*RPress[])() = {boxRPress, bjRPress, SnekRPress, calcRPress, xpRPress, personalizationRPress, deepSleepRPress, sRPress};

const char* notification; 


int currentApp = -1;