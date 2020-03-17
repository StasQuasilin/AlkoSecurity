#include <ArduinoJson.h>
#include <WiFiManager.h>
#include <WebSocketsServer.h>

#define AC_SSID "home23"
#define AC_PASS "07022014"
#define ONE_WIRE_BUS D2

const char* ssid = AC_SSID;
const char* password = AC_PASS;

WebSocketsServer webSocket = WebSocketsServer(80);

const uint8_t noClient = -1;
uint8_t clients[4];

void setup() {

  Serial.begin(115200);
  initWebSocket();

  /*
  for (int i = 0; i < 4; i++){
    clients[i] = noClient;
  }
  
  */
}

void loop() {
  webSocket.loop();
  sensorLoop1();
}
/*
void printClients(){
  for (int i = 0; i < 4; i++){
      Serial.printf("\t--> [%u]\n", clients[i]);
  }
}
*/
