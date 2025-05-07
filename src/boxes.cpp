#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "config.h"

int box_on_screen = 0;
int16_t box_y = 0;
int16_t box_x = 0;
int16_t guy_x = 42;

int holding = 0;
int score = 0;
int dead = 0;

extern Adafruit_SSD1306 display;

const unsigned char box[] PROGMEM = {
  0xff, 0xff,
  0xc0, 0x3,
  0xa0, 0x5,
  0x90, 0x9,
  0x88, 0x11,
  0x84, 0x21,
  0x82, 0x41,
  0x81, 0x81,
  0x81, 0x81,
  0x82, 0x41,
  0x84, 0x21,
  0x88, 0x11,
  0x90, 0x9,
  0xa0, 0x5,
  0xc0, 0x3,
  0xff, 0xff
};

const unsigned char guy[] PROGMEM = {
  0x7e,
  0x42,
  0x42,
  0x42,
  0x42,
  0x7e,
  0x3c,
  0x3c,
  0x5a,
  0x5a,
  0x5a,
  0x18,
  0x18,
  0x24,
  0x42,
  0x81
};

void die() {
  display.clearDisplay();
  display.setCursor(20, 30);
  display.setTextSize(2);
  display.println("Game Over");
  display.setTextSize(1);
  box_on_screen = 0;
  box_x = 0;
  box_y = 0;
  guy_x = 42;
  score = 0;
  display.setCursor(5, 5);
  display.print("Score: ");
  display.print(score);
  display.display();
}

void move(){
  if (guy_x == 42) {
    guy_x = 85;
  } else {
    guy_x = 42;
  }
  }

  void boxLPress(){
    move();
}
void boxMPress(){
  move();
}

void boxRPress(){
  move();
}

void boxesLoop() {

  display.drawBitmap(guy_x, 48, guy, 8, 16, COLOR);
  if (box_on_screen == 1) {
    box_y += floor(score / 5) + 1;
    display.drawBitmap(box_x, box_y, box, 16, 16, COLOR);
  }


  if (box_on_screen == 0) {
    box_y = 0;
    if (random(2)) {
      box_x = 42;
      display.drawBitmap(box_x, box_y, box, 16, 16, COLOR);
    } else {
      box_x = 85;
      display.drawBitmap(box_x, box_y, box, 16, 16, COLOR);
    }
    box_on_screen = 1;
  }


  display.setTextSize(1);
  display.setCursor(5, 5);
  display.print("Score: ");
  display.print(score);

  if (box_y >= 64) {
    box_on_screen = 0;
    score++;
  }
  if (box_y >= 45 && box_x == guy_x && box_on_screen == 1) {
    dead = 1;
    die();
    delay(1000);
    dead = 0;
  }
}
