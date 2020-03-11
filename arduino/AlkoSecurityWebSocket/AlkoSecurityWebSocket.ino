//#include "WiFi.h"
#include <WiFiManager.h>
#include <WebSocketsServer.h>


#define AC_SSID "home23"
#define AC_PASS "07022014"


const char* ssid = AC_SSID;
const char* password = AC_PASS;

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
  String r = "" + digitalRead(2);
  for (int i = 0; i < 4; i++){
      uint8_t client = clients[i];
      if (client != noClient){
          webSocket.sendTXT(client, r);
      }
  }
  delay(500);
}

void printClients(){
  for (int i = 0; i < 4; i++){
      Serial.printf("\t--> [%u]\n", clients[i]);
  }
}

void onWebSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {
 
  // Figure out the type of WebSocket event
  switch(type) {
 
    // Client has disconnected
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Disconnected!\n", num);
      clients[num] = noClient;
      printClients();
      break;
 
    // New client has connected
    case WStype_CONNECTED:
      {
        if (num < 4){
          IPAddress ip = webSocket.remoteIP(num);
          Serial.printf("[%u] Connection from ", num);
          Serial.println(ip.toString());
          clients[num] = num;
          printClients();
        }
      }
      break;
 
    // Echo text message back to client
    case WStype_TEXT:
      Serial.printf("[%u] Text: %s\n", num, payload);
      webSocket.sendTXT(num, payload);
      break;
 
    // For everything else: do nothing
    case WStype_BIN:
    case WStype_ERROR:
    case WStype_FRAGMENT_TEXT_START:
    case WStype_FRAGMENT_BIN_START:
    case WStype_FRAGMENT:
    case WStype_FRAGMENT_FIN:
    default:
      break;
  }
}
