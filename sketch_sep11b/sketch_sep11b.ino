//DHT11 Code + LED HIGH on 30+ temp.
# include "DHT.h"

# define DHTTYPE DHT11

# define dht_dpin 14

DHT dht(dht_dpin, DHTTYPE);

int led = 2;

void setup(void) {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  dht.begin();
  Serial.begin(9600);
  Serial.println("\n");
  Serial.println("Humidity & Temperature \n\n");
  delay(700);
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  Serial.print("Current Humidity : ");
  Serial.print(h);
  Serial.print("%   ");
  if(t > 30){
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(led,LOW);
  }
  Serial.print("Current Temperature (C): ");
  Serial.print(t);
  Serial.print("C   ");
  Serial.print("Current Temperature (F): ");
  Serial.print(f);
  Serial.println("F   ");
  delay(800);
}
