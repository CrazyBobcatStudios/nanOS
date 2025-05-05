#include "config.h"
#include "driver/gpio.h"
#include "esp_sleep.h"

void deepSleepLoop(){
  esp_sleep_enable_gpio_wakeup();
  gpio_wakeup_enable(static_cast<gpio_num_t>(LEFT_BUTTON), GPIO_INTR_LOW_LEVEL);
  gpio_wakeup_enable(static_cast<gpio_num_t>(MIDDLE_BUTTON), GPIO_INTR_LOW_LEVEL);
  gpio_wakeup_enable(static_cast<gpio_num_t>(RIGHT_BUTTON), GPIO_INTR_LOW_LEVEL);
  display.clearDisplay();
  display.display();
  Serial.println("Gong to sleep...");
  delay(100);
  esp_light_sleep_start();
  Serial.println("woke up");
}

void deepSleepLPress(){
    
}

void deepSleepMPress(){
    
}

void deepSleepRPress(){
    
}