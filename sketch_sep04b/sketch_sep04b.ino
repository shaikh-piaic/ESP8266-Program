int pins[8] = {16,5,4,0,2,14,12,13};

void setup() {
  // put your setup code here, to run once:

  for(int i = 0; i<8; i++){
     pinMode(pins[i],OUTPUT); //////////
  }
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i = 0; i<8; i++){
    digitalWrite(pins[i],HIGH);
    Serial.println("Pin Number : ");
    Serial.println(pins[i]);
    delay(500);
    digitalWrite(pins[i],LOW);
    delay(500);
    Serial.println("Done");
  }

  for(int i = 0; i<8; i++){
    digitalWrite(pins[i],HIGH);
  }
  delay(2000);
    for(int i = 0; i<8; i++){
    digitalWrite(pins[i],LOW);
  }
  delay(1000);
}
