#include <OneWire.h>

OneWire ds(ONE_WIRE_BUS);

DynamicJsonDocument doc(1024);

void sensorLoop1(){
  
  byte i;
  byte present = 0;
  byte type_s;
  byte data[12];
  byte addr[8];

  float celsius;

  if ( !ds.search(addr)) {
    String data;
    serializeJson(doc, data);
    Serial.println(data);
    dataSend(data);
    doc.clear();
    ds.reset_search();
    delay(250);
    return;
  }
  
  JsonObject obj = doc.createNestedObject();

  String rom;  
  for( i = 0; i < 8; i++) {
    rom = rom + String(addr[i], HEX);
  }
  
  obj["rom"] = rom;

  if (OneWire::crc8(addr, 7) != addr[7]) {
    return;
  }

  // первый байт определяет чип
  switch (addr[0]) {
    case 0x10:
      obj["chip"] = "DS18S20";
      type_s = 1;
      break;
    case 0x28:
      obj["chip"] = "DS18B20";
      type_s = 0;
      break;
    case 0x22:
      obj["chip"] = "DS1822";    
      type_s = 0;
      break;      
    default:
      obj["chip"] = "Not a DS18x20 family device.";    
      return;
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44); // начинаем преобразование, используя ds.write(0x44,1) с "паразитным" питанием
  delay(1000); // 750 может быть достаточно, а может быть и не хватит

  // мы могли бы использовать тут ds.depower(), но reset позаботится об этом
  present = ds.reset();
  ds.select(addr);
  ds.write(0xBE);
  
  for ( i = 0; i < 9; i++) { // нам необходимо 9 байт
    data[i] = ds.read();
  }
  
  // конвертируем данный в фактическую температуру
  // так как результат является 16 битным целым, его надо хранить в
  // переменной с типом данных "int16_t", которая всегда равна 16 битам,
  // даже если мы проводим компиляцию на 32-х битном процессоре
  int16_t raw = (data[1] << 8) | data[0];

  if (type_s) {
    raw = raw << 3; // разрешение 9 бит по умолчанию
    if (data[7] == 0x10) {
      raw = (raw & 0xFFF0) + 12 - data[6];
    }
  } else {
    
    byte cfg = (data[4] & 0x60);
    // при маленьких значениях, малые биты не определены, давайте их обнулим
    if (cfg == 0x00) raw = raw & ~7; // разрешение 9 бит, 93.75 мс
    else if (cfg == 0x20) raw = raw & ~3; // разрешение 10 бит, 187.5 мс
    else if (cfg == 0x40) raw = raw & ~1; // разрешение 11 бит, 375 мс
    //// разрешение по умолчанию равно 12 бит, время преобразования - 750 мс
    
  }

  celsius = (float)raw / 16.0;
  obj["temperature"] = celsius;
}
