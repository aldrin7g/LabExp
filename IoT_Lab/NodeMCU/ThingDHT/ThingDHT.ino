#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
#include <DHT.h>

DHT dht(D1, DHT11);
WiFiClient client;
float temperature, humidity;

unsigned long channel_id = 2464797;
const char* api_key = "XXXXXXXXXXXXX";

const char* ssid = "Virus#404";
const char* password = "password2";

void setup() {
  Serial.begin(115200);
  dht.begin();
  
  WiFi.begin(ssid,password);
  while(WiFi.status()!= WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected!\n");

  ThingSpeak.begin(client);
}

void loop() {

  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  if(isnan(temperature)||isnan(humidity)){
    Serial.println("Check Sensor!");
    return;
  }

  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);
  ThingSpeak.writeFields(channel_id,api_key);
}
