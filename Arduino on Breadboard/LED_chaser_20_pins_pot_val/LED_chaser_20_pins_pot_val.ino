void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  
  for (int i = 2; i < 19; i++) {
    pinMode(i, OUTPUT);
  }
  
  pinMode(19,INPUT);
}

int i = 2;
int potval;

void loop() {
  // put your main code here, to run repeatedly:
  
  potval = analogRead(A5);
  
  Serial.println(potval);
  
  digitalWrite(i, HIGH);
  delay(potval);
  digitalWrite(i, LOW);

  i++;
  if (i == 19) {
    i = 2;
  }
}
