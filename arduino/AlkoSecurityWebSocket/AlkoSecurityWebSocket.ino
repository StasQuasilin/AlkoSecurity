#include <ArduinoJson.h>
#include <SPI.h>
#include <Wire.h>
#include <OneWire.h>
#include <WiFiManager.h>
#include <WebSocketsServer.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define AC_SSID "BestСамогон"
#define AC_PASS "07022014"
#define ONE_WIRE_BUS D3

const char* ssid = AC_SSID;
const char* password = AC_PASS;

WebSocketsServer webSocket = WebSocketsServer(80);

const uint8_t noClient = -1;
uint8_t clients[4];
long rssi;
String address;

void setup() {
  //Serial.begin(9600);
  initDisplay();
  initWebSocket();
  
}

void loop() {
  updateRSSI();
  sensorLoop1();
  webSocket.loop();
}
