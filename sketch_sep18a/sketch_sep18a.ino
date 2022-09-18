#include <PubSubClient.h>
#include <stdlib.h>
#include <ESP8266WiFi.h>
const char* ssid = "SSUET Wireless";
const char* password = "";
const char* mqtt_server = "broker.mqtt-dashboard.com";

char pub_str[100];


unsigned long previousMillis = 0;

const long interval = 60 * 1000;



WiFiClient espClient;
PubSubClient client(espClient);
void setup_wifi()
{

  delay(10);

  Serial.print("connecting to");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print("-.");
  }

  Serial.println();
  Serial.println("WiFi Connected");
  Serial.println("WiFi got IP");
  Serial.println();
  Serial.println(WiFi.localIP());
}

void callback(String topic, byte* payload, unsigned int length)
{
  Serial.print("Message arrived : ");
  Serial.print(topic);
  Serial.print(" : ");
  String messageTemp;
  for (int i = 0; i < length; i++)
  {
    //         Serial.println((char)payload[i]);
    messageTemp += (char)payload[i];
  }

  Serial.print(messageTemp);

  if (topic == "Shaikh'sInc") {

    if (messageTemp == "on") {
      digitalWrite(2, LOW);
    }
    else if (messageTemp == "off") {
      digitalWrite(2, HIGH);
    }
  }
  Serial.println();
}

void reconnect()
{

  while (!client.connected()) {
    Serial.println("Attempting MQTT connection");
    if (client.connect("Shaikh's Inc."))  //Added Client Name
    {
      Serial.println("Connected");
      client.publish("karachi/millis", "Connected!"); //(topic,msg)
      client.subscribe("Shaikh'sInc"); // (topic)
      client.subscribe("karachi/millis");
      Serial.print("subscribed!");
    }
    else
    {
      Serial.print("Failed, rc = ");
      Serial.print(client.state());
      Serial.println("Waiting for 5 seconds to try again");
      delay(5000);
    }
  }
}

void setup()
{

  pinMode(2, OUTPUT);
  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, 1883);  // Always 1883 port number   (server,port)
  client.setCallback(callback);
  reconnect();
}

void loop()
{

  if (!client.connected())
  {
    Serial.print("disconnected");
    reconnect();
    //      Serial.print("disconnected");
  }

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    sprintf(pub_str, "%11d", currentMillis);
    sprintf(pub_str, "%s", "SHAIKH");
    client.publish("karachi/millis", pub_str);
    delay(1000);
  }
  client.loop();
}
