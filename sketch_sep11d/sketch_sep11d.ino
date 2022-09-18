// Ultrasonic sensor Basic Code

int trig = 2; //D4 TRIG
int echo = 4; //D2 ECHO


void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  delayMicroseconds(5);


  long duration = pulseIn(echo, HIGH);
  int distance = duration * 0.0343/2; // DISTANCE IN CM


  Serial.print("DURATION : ");
  Serial.println(duration);

  Serial.print("DISTANCE IN (CM) : ");
  Serial.println(distance);


  delay(1000);

}
