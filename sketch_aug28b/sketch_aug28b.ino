
int LED = 2;

void switchOn() {
  digitalWrite(LED,HIGH);
  delay(2000);

}


void switchOff() {
  digitalWrite(LED,LOW);
  delay(2000);

}


void setup() {
  // put your setup code here, to run once:

  pinMode(LED,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

switchOn();
Serial.println("Light is ON");
switchOff();
Serial.println("Light is OFF");

if(Serial.available()>0){
    Serial.println(char(Serial.read()));
  }

}
