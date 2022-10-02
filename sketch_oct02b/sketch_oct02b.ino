int led = 2;
int btn = 4;


void setup() {
  pinMode(led,OUTPUT);
  pinMode(btn,INPUT_PULLUP);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  int data = digitalRead(btn);
  Serial.println("Data is");
  Serial.println(data);
  if(data==0){
    digitalWrite(led,HIGH);
  }else{
    digitalWrite(led,LOW);
  }
  delay(1000);
  // put your main code here, to run repeatedly:

}
