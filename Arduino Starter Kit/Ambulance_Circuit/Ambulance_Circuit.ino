

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  analogWrite(11, 150);
  delay(200);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  analogWrite(11, 250);
  delay(200);
}
