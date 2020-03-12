#include <ArduinoJson.h>

#include <WiFiManager.h>
#include <WebSocketsServer.h>
#include <OneWire.h>

#define AC_SSID "home23"
#define AC_PASS "07022014"
#define SENSOR_PIN 2

const char* ssid = AC_SSID;
const char* password = AC_PASS;

OneWire ds(SENSOR_PIN);

WebSocketsServer webSocket = WebSocketsServer(80);
const uint8_t noClient = -1;
uint8_t clients[4];

void setup() {

  for (int i = 0; i < 4; i++){
    clients[i] = noClient;
  }

  randomSeed(analogRead(0));
  
  Serial.begin(115200);
  Serial.println("Connecting");
  WiFiManager wifiManager;
  wifiManager.setDebugOutput(true);
  wifiManager.autoConnect(ssid, password);
  
  while ( WiFi.status() != WL_CONNECTED ) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  webSocket.begin();
  webSocket.onEvent(onWebSocketEvent);
}

void loop() {
  webSocket.loop();
  sensorLoop();
  
  delay(300);
}

void printClients(){
  for (int i = 0; i < 4; i++){
      Serial.printf("\t--> [%u]\n", clients[i]);
  }
}
