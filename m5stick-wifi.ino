#include "WiFi.h"
#include <M5StickC.h>

const char* ssid = "HackedNetwork";
const char* password =  "12345678";

void setup() {
  Serial.begin(115200);
  // Initialize the M5StickC object
  M5.begin();
  Wire.begin(0,26);
  M5.Lcd.setRotation(3);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0, 2);
  WiFi.begin(ssid, password);
  // Setting the hostname
  WiFi.setHostname("shower-pipe");

  M5.Lcd.println("Start WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting ..");
  }

  // Write info in serial logs.
  Serial.print("Connected to the WiFi network. IP: ");
  Serial.println(WiFi.localIP());

  // Write info in LCD.
  M5.Lcd.println("Now Connected");
  M5.Lcd.println(WiFi.localIP());
}

void loop() {}
