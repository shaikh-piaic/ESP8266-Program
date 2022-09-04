
int LED = 2;

void switchOn() {
  digitalWrite(LED,HIGH);
  Serial.println("Light ON");
//  delay(2000);

}


void switchOff() {
  digitalWrite(LED,LOW);
  Serial.println("Light OFF");
//  delay(2000);

}


void setup() {
  // put your setup code here, to run once:

  pinMode(LED,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  int data;
  if(Serial.available() > 0 ){
     data = Serial.read();
  
  Serial.println(data);
  if(data == 49){
    switchOn();
  }
  if(data == 50){
    switchOff();
  }
  }     


}
