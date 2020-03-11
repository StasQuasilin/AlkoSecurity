#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include <WiFiUdp.h>

#define AC_SSID "home23"
#define AC_PASS "07022014"
#define AP_PORT 8888

const char* autoConnectSSID = AC_SSID;
const char* autoConnectPass = AC_PASS;
unsigned int localPort = AP_PORT;
char packetBuffer[UDP_TX_PACKET_MAX_SIZE + 1];

WiFiServer server(80);
WiFiUDP Udp;

String inputBuffer;

void setup() {
  Serial.begin(115200);
  WiFiManager wifiManager;
  wifiManager.setDebugOutput(false);
  wifiManager.autoConnect(autoConnectSSID, autoConnectPass);
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());

  Serial.printf("UDP server on port %d\n", localPort);
  Udp.begin(localPort);
}

void loop() {
  
  int packetSize = Udp.parsePacket();
  if(packetSize)
  {
    Serial.print("Received packet of size ");
    Serial.println(packetSize);
    Serial.print("From ");
    IPAddress remote = Udp.remoteIP();
    for (int i = 0; i < 4; i++)
    {
      Serial.print(remote[i], DEC);
      if (i < 3)
      {
        Serial.print(".");
      }
    }
    Serial.print(", port ");
    Serial.println(Udp.remotePort());

    // read the packet into packetBuffer
    Udp.read(packetBuffer,UDP_TX_PACKET_MAX_SIZE);
    Serial.print("Contents: ");
    Serial.println(packetBuffer);
    
    //char reply[packetBuffer.length() + 1];
    //packetBuffer.toCharArray(reply, packetBuffer.length() + 1);
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    Udp.write(packetBuffer);
    Udp.endPacket();
  }

}
