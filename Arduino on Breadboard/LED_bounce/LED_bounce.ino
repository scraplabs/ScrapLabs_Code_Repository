void setup() {
  // put your setup code here, to run once:
  for (int i = 2; i < 20; i++) {
    pinMode(i, OUTPUT);
  }
}

int i = 2;

void loop() {
  // put your main code here, to run repeatedly:
  for (int j = 0; j < i; j++) {
    digitalWrite(i, HIGH);
    delay(50);
    digitalWrite(i, LOW);
    delay(50);

  }
  i++;
  if (i == 20) {
    i = 2;
  }
}
