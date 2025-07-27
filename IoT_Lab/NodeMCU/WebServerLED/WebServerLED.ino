#include <ESP8266WiFi.h>

const char* ssid = "Virus#404";
const char* password = "password2";

const int led = D4;

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());  

  server.begin();
}

void loop() {
    WiFiClient client = server.available();

    String request = client.readStringUntil('\r');
    if (request.indexOf("/ON") > 0) digitalWrite(led, HIGH);
    else if(request.indexOf("/OFF") > 0) digitalWrite(led, LOW);

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println();
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<a href = \"/ON\"><button>TURN ON</button></a>");
    client.println("<a href = \"/OFF\"><button>TURN OFF</button></a>");  
    client.println("</html>");      
    client.stop();
}
