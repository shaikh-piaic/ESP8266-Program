// Ultrasonic sensor Basic Code

int tran = 2; //D4 TRIG
int rec = 4; //D2 ECHO


void setup() {
  // put your setup code here, to run once:
  pinMode(trans, OUTPUT);
  pinMode(rec, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trans, LOW);
  delayMicroseconds(5);
  digitalWrite(trans, HIGH);
  delayMicroseconds(10);
  digitalWrite(trans, LOW);
  delayMicroseconds(5);


  long duration = pulseIn(rec, HIGH);
  int distance = duration * 0.0343; // DISTANCE IN CM


  Serial.print("DURATION : ");
  Serial.print(duration);

  Serial.print("DISTANCE IN (CM) : ");
  Serial.print(distance);


  delay(1000);

}
