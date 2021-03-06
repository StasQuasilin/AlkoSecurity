#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     LED_BUILTIN

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LOGO_WIDTH    128
#define LOGO_HEIGHT   64

// 'alko_logo', 128x64px
const unsigned char logo [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x3f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x3f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x3f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x3f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x3f, 0x80, 0x00, 0x1f, 0xff, 0x00, 0x1f, 0xff, 0xe0, 0x07, 0xfe, 0x0f, 0xff, 0xff, 0x00, 
  0x00, 0x3f, 0x80, 0x00, 0x1f, 0xff, 0xe0, 0x1f, 0xff, 0xe0, 0x1f, 0xff, 0x0f, 0xff, 0xff, 0x00, 
  0x00, 0x3f, 0x80, 0x00, 0x1f, 0xff, 0xf0, 0x1f, 0xff, 0xe0, 0x3f, 0xff, 0x0f, 0xff, 0xff, 0x00, 
  0x00, 0x3f, 0x80, 0x00, 0x1f, 0xff, 0xf8, 0x1f, 0xff, 0xe0, 0x7f, 0xff, 0x0f, 0xff, 0xff, 0x00, 
  0x00, 0x3f, 0x80, 0x00, 0x1f, 0x83, 0xf8, 0x1f, 0xff, 0xe0, 0xff, 0x0e, 0x0f, 0xff, 0xff, 0x00, 
  0x00, 0x3f, 0x80, 0x00, 0x1f, 0x81, 0xf8, 0x1f, 0x80, 0x00, 0xfc, 0x00, 0x00, 0x1f, 0x80, 0x00, 
  0x00, 0x2f, 0x80, 0x00, 0x1f, 0x80, 0xfc, 0x1f, 0x80, 0x00, 0xf8, 0x00, 0x00, 0x1f, 0x80, 0x00, 
  0x00, 0x2f, 0x80, 0x00, 0x1f, 0x80, 0xfc, 0x1f, 0x80, 0x00, 0xf8, 0x00, 0x00, 0x1f, 0x80, 0x00, 
  0x00, 0x7f, 0xc0, 0x00, 0x1f, 0x80, 0xf8, 0x1f, 0x80, 0x00, 0xfc, 0x00, 0x00, 0x1f, 0x80, 0x00, 
  0x00, 0x6f, 0xc0, 0x00, 0x1f, 0x81, 0xf8, 0x1f, 0x80, 0x00, 0xfe, 0x00, 0x00, 0x1f, 0x80, 0x00, 
  0x00, 0x6f, 0x80, 0x00, 0x1f, 0x87, 0xf0, 0x1f, 0x80, 0x00, 0xff, 0x80, 0x00, 0x1f, 0x80, 0x00, 
  0x00, 0x2f, 0x80, 0x00, 0x1f, 0xff, 0xe0, 0x1f, 0xff, 0xe0, 0x7f, 0xf0, 0x00, 0x1f, 0x80, 0x00, 
  0x00, 0x3f, 0x80, 0x00, 0x1f, 0xff, 0xc0, 0x1f, 0xff, 0xe0, 0x3f, 0xfc, 0x00, 0x1f, 0x80, 0x00, 
  0x00, 0x7f, 0xc0, 0x00, 0x1f, 0xff, 0xe0, 0x1f, 0xff, 0xe0, 0x1f, 0xfe, 0x00, 0x1f, 0x80, 0x00, 
  0x00, 0xff, 0xe0, 0x00, 0x1f, 0xff, 0xf8, 0x1f, 0xff, 0xe0, 0x07, 0xff, 0x00, 0x1f, 0x80, 0x00, 
  0x03, 0xff, 0xf0, 0x00, 0x1f, 0x83, 0xfc, 0x1f, 0x80, 0x00, 0x01, 0xff, 0x80, 0x1f, 0x80, 0x00, 
  0x03, 0xff, 0xf8, 0x00, 0x1f, 0x80, 0xfc, 0x1f, 0x80, 0x00, 0x00, 0x7f, 0x80, 0x1f, 0x80, 0x00, 
  0x07, 0x90, 0x3c, 0x00, 0x1f, 0x80, 0xfc, 0x1f, 0x80, 0x00, 0x00, 0x1f, 0x80, 0x1f, 0x80, 0x00, 
  0x06, 0x30, 0x0c, 0x00, 0x1f, 0x80, 0xfe, 0x1f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x1f, 0x80, 0x00, 
  0x0e, 0x20, 0x26, 0x00, 0x1f, 0x80, 0xfe, 0x1f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x1f, 0x80, 0x00, 
  0x0c, 0x20, 0x06, 0x00, 0x1f, 0x80, 0xfc, 0x1f, 0x80, 0x00, 0x00, 0x1f, 0x80, 0x1f, 0x80, 0x00, 
  0x0c, 0x30, 0x36, 0x00, 0x1f, 0x81, 0xfc, 0x1f, 0x80, 0x00, 0xc0, 0x3f, 0x80, 0x1f, 0x80, 0x00, 
  0x0c, 0x7f, 0xfe, 0x00, 0x1f, 0x83, 0xfc, 0x1f, 0xff, 0xf0, 0xff, 0xff, 0x00, 0x1f, 0x80, 0x00, 
  0x06, 0x7f, 0xfe, 0x00, 0x1f, 0xff, 0xf8, 0x1f, 0xff, 0xf0, 0xff, 0xff, 0x00, 0x1f, 0x80, 0x00, 
  0x06, 0x7f, 0xfe, 0x00, 0x1f, 0xff, 0xf0, 0x1f, 0xff, 0xf0, 0xff, 0xfe, 0x00, 0x1f, 0x80, 0x00, 
  0x06, 0x7f, 0xfe, 0x00, 0x1f, 0xff, 0xe0, 0x1f, 0xff, 0xf0, 0xff, 0xfc, 0x00, 0x1f, 0x80, 0x00, 
  0x06, 0x7f, 0xfe, 0x00, 0x1f, 0xff, 0x00, 0x1f, 0xff, 0xf0, 0x3f, 0xe0, 0x00, 0x1f, 0x80, 0x00, 
  0x06, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x06, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x06, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x06, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x06, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x06, 0x7f, 0xfe, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x06, 0x7f, 0xfe, 0x00, 0x3f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x06, 0x7f, 0xfe, 0x00, 0x7f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x06, 0x7f, 0xfe, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x06, 0x7f, 0xfe, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x06, 0x7f, 0xfe, 0x01, 0xe0, 0x07, 0xf8, 0x3e, 0x1f, 0x07, 0xf0, 0x7f, 0x8f, 0xe0, 0xf0, 0xe0, 
  0x06, 0x7f, 0xfe, 0x01, 0xc0, 0x07, 0xfc, 0x3e, 0x1f, 0x0f, 0xf8, 0x7f, 0x9f, 0xf0, 0xf0, 0xe0, 
  0x06, 0x7f, 0xfe, 0x01, 0xc0, 0x00, 0x1c, 0x3e, 0x3f, 0x1e, 0x38, 0x78, 0x3c, 0x78, 0xf0, 0xe0, 
  0x06, 0x7f, 0xfe, 0x01, 0xc0, 0x00, 0x1e, 0x3f, 0x3f, 0x3c, 0x3c, 0x70, 0x38, 0x38, 0xf0, 0xe0, 
  0x06, 0x7f, 0xfe, 0x01, 0xc0, 0x01, 0xfe, 0x3b, 0x37, 0x3c, 0x1c, 0x70, 0x38, 0x3c, 0xff, 0xe0, 
  0x06, 0x7f, 0xfe, 0x01, 0xc0, 0x07, 0xfe, 0x3b, 0x77, 0x3c, 0x1c, 0x70, 0x38, 0x3c, 0xff, 0xe0, 
  0x0e, 0xff, 0xfe, 0x01, 0xe0, 0x0f, 0x1e, 0x3b, 0xe7, 0x3c, 0x1c, 0x70, 0x38, 0x38, 0xf1, 0xe0, 
  0x0e, 0x7f, 0xfe, 0x00, 0xf0, 0x0f, 0x1e, 0x3b, 0xe7, 0x1c, 0x3c, 0x70, 0x38, 0x38, 0xf0, 0xe0, 
  0x0e, 0x70, 0x66, 0x00, 0xfc, 0x4f, 0x1e, 0x39, 0xe7, 0x1e, 0x78, 0x70, 0x3c, 0x78, 0xf0, 0xe0, 
  0x0f, 0x7f, 0xfe, 0x00, 0x7f, 0xe7, 0xfe, 0x39, 0xc7, 0x0f, 0xf8, 0x70, 0x1f, 0xf0, 0xf0, 0xe0, 
  0x0f, 0xff, 0xfe, 0x00, 0x1f, 0xe7, 0xee, 0x71, 0xc7, 0x07, 0xe0, 0x70, 0x0f, 0xe0, 0xf0, 0xe0, 
  0x07, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x03, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};




void initDisplay(){
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
  }
  //display.clearDisplay(); 
  //display.setTextSize(1); 
  display.setTextColor(SSD1306_WHITE);
  
  displayWarm();
}

void writeText(String text){
  display.clearDisplay();
  display.setCursor(1,2);
  display.setTextSize(1);
  display.println(text);
  display.display();
}

void drawData(uint8_t sensorsCount, DynamicJsonDocument doc){
  display.clearDisplay();

  display.setCursor(0,0);
  display.setTextSize(1);

  display.println("IP: " + address);
  display.print(rssi);
  display.println(" dB");
  
  display.setCursor(1,16);
  
  
  if(sensorsCount > 0){
    
    JsonArray arr = doc.as<JsonArray>();
    for (int i=0; i<arr.size(); i++) {
      display.setTextSize(1);
      String rom = arr[i]["rom"].as<String>();
      display.print(rom.substring(rom.length() - 4));
      
      display.setTextSize(2);
      float value = arr[i]["temperature"].as<float>();
      display.print(" ");
      display.print(value);  
      display.println("oC");  
    }
  } else {
    display.setTextSize(2);
    display.println(utf8rus("Нi одного датчика,"));
    display.println(utf8rus("блять!"));
  }
  display.display();
}

String utf8rus(String source)
{
  int i,k;
  String target;
  unsigned char n;
  char m[2] = { '0', '\0' };
 
  k = source.length(); i = 0;
 
  while (i < k) {
    n = source[i]; i++;
 
    if (n >= 0xBF){
      switch (n) {
        case 0xD0: {
          n = source[i]; i++;
          if (n == 0x81) { n = 0xA8; break; }
          if (n >= 0x90 && n <= 0xBF) n = n + 0x2F;
          break;
        }
        case 0xD1: {
          n = source[i]; i++;
          if (n == 0x91) { n = 0xB7; break; }
          if (n >= 0x80 && n <= 0x8F) n = n + 0x6F;
          break;
        }
      }
    }
    m[0] = n; target = target + String(m);
  }
return target;
}


void displayWarm(){
  display.clearDisplay();

  display.drawBitmap(
    (display.width()  - LOGO_WIDTH ) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    logo, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
  delay(5000);
}
