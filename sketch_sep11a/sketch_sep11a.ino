//DHT11 Code
# include "DHT.h"

# define DHTTYPE DHT11

# define dht_dpin 5

DHT dht(dht_dpin,DHTTYPE);

void setup(void) {
  // put your setup code here, to run once:
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
  Serial.print("Current Temperature : ");
  Serial.print(t);
  Serial.println("C   ");
  Serial.print(f);
  Serial.println("F   ");
  delay(800);
}
