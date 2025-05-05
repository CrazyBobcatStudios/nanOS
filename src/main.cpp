#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "config.h"
#include "center.h"

#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int ntime = -1;
bool lastLeftButtonState = HIGH;
bool lastMiddleButtonState = HIGH;
bool lastRightButtonState = HIGH;
bool wokeFromDeepSleep = false;

const unsigned long comboWindow = 200;

const unsigned char logo[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xf0, 0x3f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x0f, 0xff, 0xf0, 0x3f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x70, 0x38, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x70, 0x38, 0x00, 0x00, 0xff, 0xe1, 0xff, 0x83, 
  0xff, 0x8e, 0x00, 0x70, 0x38, 0x00, 0x00, 0xff, 0xe1, 0xff, 0x83, 0xff, 0x8e, 0x00, 0x70, 0x3f, 
  0xff, 0xc0, 0xe0, 0x61, 0x81, 0x83, 0x81, 0x8e, 0x00, 0x70, 0x3f, 0xff, 0xc0, 0xe0, 0x61, 0xff, 
  0x83, 0x81, 0x8e, 0x00, 0x70, 0x00, 0x01, 0xc0, 0xe0, 0x61, 0xff, 0x83, 0x81, 0x8e, 0x00, 0x70, 
  0x00, 0x01, 0xc0, 0xe0, 0x61, 0x81, 0x83, 0x81, 0x8e, 0x00, 0x70, 0x00, 0x01, 0xc0, 0xe0, 0x61, 
  0x81, 0x83, 0x81, 0x8f, 0xff, 0xf0, 0x3f, 0xff, 0xc0, 0xe0, 0x61, 0x81, 0x83, 0x81, 0x8f, 0xff, 
  0xf0, 0x3f, 0xff, 0xc0
};

void setup() {
  
  Wire.begin(I2C_SDA, I2C_SCL);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  
  if (esp_sleep_get_wakeup_cause() != ESP_SLEEP_WAKEUP_UNDEFINED) {
    wokeFromDeepSleep = true;
  }
  
  display.setTextColor(COLOR);
  pinMode(LEFT_BUTTON, INPUT_PULLUP);
  pinMode(MIDDLE_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);
  Serial.begin(9600);
  
  if (!wokeFromDeepSleep) {
    display.clearDisplay();
    display.drawBitmap(SCREEN_WIDTH/2 - 41, SCREEN_HEIGHT/2 - 6, logo, 82, 12, COLOR);
    display.display();
    delay(2000);
    display.clearDisplay();
  }

  delay(50);
}
void loop(){
  Serial.println("not sleeping");
  if (currentApp == -1){
    menuLoop();
  }

  else{
    gameLoops[currentApp]();
  }

  if (digitalRead(LEFT_BUTTON) == LOW && digitalRead(MIDDLE_BUTTON) == LOW && digitalRead(RIGHT_BUTTON) == LOW){
    currentApp = -1;
  }


  bool leftButtonState = digitalRead(LEFT_BUTTON);
  
  if (lastLeftButtonState == HIGH && leftButtonState == LOW) {
    if(currentApp == -1){
      menuLPress();
    }
    else{
      LPress[currentApp]();
    }
  }
  
  lastLeftButtonState = leftButtonState;

  bool middleButtonState = digitalRead(MIDDLE_BUTTON);
  
  if (lastMiddleButtonState == HIGH && middleButtonState == LOW) {
    if(currentApp == -1){
      menuMPress();
    }
    else{
      MPress[currentApp]();
    }
  }
  
  lastMiddleButtonState = middleButtonState;

  bool rightButtonState = digitalRead(RIGHT_BUTTON);
  
  if (lastRightButtonState == HIGH && rightButtonState == LOW) {
    if(currentApp == -1){
      menuRPress();
    }
    else{
      RPress[currentApp]();
    }
  }
  
  lastRightButtonState = rightButtonState;

  if (notification != NULL){
    display.fillRect(16, 0, centerw(16), 16, SECONDARY);
    display.setCursor(17, 5);
    display.setTextColor(BLACK);
    display.print(notification);
    display.setTextColor(COLOR);
    display.display();
    if (ntime == -1){
      ntime = 20;
    }
    if (ntime == 0){
      notification = NULL;
      ntime = -1;
    }
    else{
      ntime--;
    }
  }


  display.display();
  delay(50);
  display.clearDisplay();
}