#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL35SJ7I046"
#define BLYNK_TEMPLATE_NAME "Demo"

#include <Servo.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
Servo servo;

char auth[] = "XXXXXXXXXXXX";//Enter your Blynk auth token
char ssid[] = "Optimistic";  //Enter your WIFI name
char pass[] = "00000000";    //Enter your WIFI password

BLYNK_WRITE(V0){
  servo.write(param.asInt());
}
void setup() {
  Serial.begin(9600);
  servo.attach(D1);
  Blynk.begin(auth, ssid, pass);
}
 
void loop() {
  Blynk.run();
}
