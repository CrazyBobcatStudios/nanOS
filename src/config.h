#pragma once
#ifndef CONFIG_H
#define CONFIG_H
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <Preferences.h>
#include <esp_now.h>

extern Adafruit_SSD1306 display;
extern Preferences prefs;

//Change this code as needed
const int LEFT_BUTTON = 20;
const int MIDDLE_BUTTON = 8;
const int RIGHT_BUTTON = 9;
const int I2C_SDA = 6;
const int I2C_SCL = 7;

extern const char* wifissid;
extern const char* wifipassword;

//change to suit your screen
const int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 64;

//primary color
const uint16_t COLOR = WHITE;
//secondary color used on multicolor displays
const uint16_t SECONDARY = WHITE;

//Shared variables

extern const char* notification;

constexpr const char* appNames[] = {
  "Boxes",
  "Blackjack",
  "Snek",
  "Calculator",
  "XP",
  "Customization",
  "Sleep",
  "Settings"
};

constexpr int appCount = sizeof(appNames) / sizeof(appNames[0]);

extern int order[];

extern int currentApp;

extern void (*gameLoops[])();
extern void (*LPress[])();
extern void (*MPress[])();
extern void (*RPress[])();

extern void menuLoop();
extern void menuLPress();
extern void menuMPress();
extern void menuRPress();

extern void boxesLoop();
extern void boxLPress();
extern void boxMPress();
extern void boxRPress();

extern void blackJackLoop();
extern void bjLPress();
extern void bjMPress();
extern void bjRPress();

extern void snekLoop();
extern void SnekLPress();
extern void SnekMPress();
extern void SnekRPress();

extern void settingsLoop();
extern void sLPress();
extern void sMPress();
extern void sRPress();

extern void calcLoop();
extern void calcLPress();
extern void calcMPress();
extern void calcRPress();

extern void deepSleepLoop();
extern void deepSleepLPress();
extern void deepSleepMPress();
extern void deepSleepRPress();

extern void xpLoop();
extern void xpLPress();
extern void xpMPress();
extern void xpRPress();

extern void personalizationLoop();
extern void personalizationLPress();
extern void personalizationMPress();
extern void personalizationRPress();

extern void giveXP(int amount);

#endif