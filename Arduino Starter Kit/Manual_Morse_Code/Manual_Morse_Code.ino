void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(A0, INPUT);
}

int switchVal;

void loop() {
  // put your main code here, to run repeatedly:

  switchVal = analogRead(A0);

  if (switchVal > 700) {
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
  }
  else {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
  }
}
