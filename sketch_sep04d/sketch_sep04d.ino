#include <ESP8266WiFi.h>

String ssid = "Shaikh's iPhone";
String Pass = "helloworld";

WiFiClient Client;

void setup() {
  // put your setup code here, to run once:
  WiFi.begin(ssid, Pass);
  Serial.begin(9600);

  Serial.println("Connecting to...");
  delay(200);
  Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
  }
  Serial.println("Connected to...");
  Serial.println(ssid);
  Serial.println("Done");
}

void loop() {
  // put your main code here, to run repeatedly:

}
