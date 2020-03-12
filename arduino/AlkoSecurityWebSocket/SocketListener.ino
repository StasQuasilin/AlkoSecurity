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
