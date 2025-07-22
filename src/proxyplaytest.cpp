#include "config.h"

extern int openSetting;
int selectedPPSetting = 0;
String settingsPPOptions[]{
  "Exit",
  "Your MAC Address",
  "Refresh",
  "",
  ""
};

uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

int foundDeviceIndex = 3;
const char* expectedMsg = "ProxyPlayCompat";

void onReceiveData(const uint8_t *mac, const uint8_t *incomingData, int len) {
  if (len == strlen(expectedMsg) && memcmp(incomingData, expectedMsg, len) == 0) {
    char macStr[18];
    snprintf(macStr, sizeof(macStr),
             "%02X:%02X:%02X:%02X:%02X:%02X",
             mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    Serial.print("Compatible device found: ");
    Serial.println(macStr);

    if (foundDeviceIndex < 5) {
      settingsPPOptions[foundDeviceIndex++] = String(macStr);
    }
  } else {
    Serial.println("Received unknown or invalid ESP-NOW message");
  }
}

void ppOpen(){
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW init failed!");
    return;
  }
  esp_now_register_recv_cb(onReceiveData);
}


void pptRefresh(){
  settingsPPOptions[1] = WiFi.macAddress();
  settingsPPOptions[3] = "";
  settingsPPOptions[4] = "";
  foundDeviceIndex = 3;

  const char* msg = "ProxyPlayCompat";
  esp_now_send(broadcastAddress, (uint8_t*)msg, strlen(msg));
}


void ppTestLoop(){
  display.fillRect(10, 5, SCREEN_WIDTH - 10, 14, COLOR);
  display.drawRect(10, 24, SCREEN_WIDTH - 10, 14, COLOR);
  display.drawRect(10, 42, SCREEN_WIDTH - 10, 14, COLOR);
  display.setCursor(12, 8);
  display.setTextColor(BLACK);
  display.print(settingsPPOptions[selectedPPSetting]);
  display.setCursor(12, 27);
  display.setTextColor(COLOR);
  display.print(settingsPPOptions[selectedPPSetting + 1]);
  display.setCursor(12, 46);
  display.print(settingsPPOptions[selectedPPSetting + 2]);
}

void ppTestLPress(){
  if(selectedPPSetting != 0){
    selectedPPSetting--;
  }
}

void ppTestMPress(){
  if(selectedPPSetting == 0){
    openSetting = -1;
  }
  if(selectedPPSetting == 2 || selectedPPSetting == 1){
    pptRefresh();
  }
}

void ppTestRPress(){
  if(selectedPPSetting < 2){
    selectedPPSetting++;
  }
}