#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "config.h"

int currentCards = 0;
int otherCards = 0;

extern Adafruit_SSD1306 display;

void bjdie() {
  display.clearDisplay();
  display.setCursor(20, 30);
  display.setTextSize(2);
  display.println("Game Over");
  display.setTextSize(1);
  display.setCursor(5, 5);
  display.display();
  currentCards = 0;
  otherCards = 0;
  delay(2000);
}

void bjwin() {
  display.clearDisplay();
  display.setCursor(20, 30);
  display.setTextSize(2);
  display.println("You Win!");
  display.setTextSize(1);
  display.setCursor(5, 5);
  display.println("Dealer had: ");
  display.println(otherCards);
  display.display();
  currentCards = 0;
  otherCards = 0;
  delay(2000);
}

void bjLose() {
  display.clearDisplay();
  display.setCursor(20, 30);
  display.setTextSize(2);
  display.println("You Lose");
  display.setTextSize(1);
  display.setCursor(5, 5);
  display.print("Dealer had: ");
  display.print(otherCards);
  display.display();
  currentCards = 0;
  otherCards = 0;
  delay(2000);
}

void bjLPress(){
  currentCards += random(1,10);
  if (currentCards > 21){
    bjdie();
  }
}

void bjMPress(){

}

void bjRPress(){
  otherCards = random(12,20);
  if (currentCards > otherCards){
    bjwin();
  }
  else{
    bjLose();
  }
}

void blackJackLoop(){
  display.setCursor(5,5);
  display.print("Cards Total ");
  display.print(currentCards);
  display.setCursor(5, 25);
  display.print("Hit (Left) or Stay ");
  display.setCursor(5, 35);
  display.print("(Right)");

  bool leftButtonState = digitalRead(LEFT_BUTTON);
}