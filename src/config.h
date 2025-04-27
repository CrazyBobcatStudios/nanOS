#ifndef CONFIG_H
#define CONFIG_H
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <Preferences.h>
extern Adafruit_SSD1306 display;

//Change this code as needed
const int LEFT_BUTTON = 20;
const int MIDDLE_BUTTON = 8;
const int RIGHT_BUTTON = 9;
const int I2C_SDA = 6;
const int I2C_SCL = 7;

//change to suit your screen
const int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 64;

//change both if your display is single colored
const uint16_t COLOR = WHITE;
//used on multicolor displays
const uint16_t SECONDARY = WHITE;

//Shared variables

extern char* notification;

extern int currentApp;
extern const char* appNames[];
extern const int appCount;
extern void (*gameLoops[])();
extern void (*LPress[])();
extern void (*MPress[])();
extern void (*RPress[])();

extern void menuLoop();
extern void boxesLoop();
extern void blackJackLoop();
extern void settingsLoop();
extern void calcLoop();

extern void menuLPress();
extern void boxLPress();
extern void bjLPress(); 
extern void sLPress();
extern void calcLPress();

extern void menuMPress();
extern void boxMPress();
extern void bjMPress(); 
extern void sMPress();
extern void calcMPress();

extern void menuRPress();
extern void boxRPress();
extern void bjRPress(); 
extern void sRPress();
extern void calcRPress();

#endif