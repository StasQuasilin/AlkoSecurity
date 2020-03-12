void dataSend(String data){
  for (int i = 0; i < 4; i++){
      uint8_t client = clients[i];
      if (client != noClient){
          webSocket.sendTXT(client, data);
      }
  }
}
