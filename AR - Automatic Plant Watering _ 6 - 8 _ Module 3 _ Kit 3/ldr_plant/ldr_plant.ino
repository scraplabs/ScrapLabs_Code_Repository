void setup() {
  pinMode(A5, INPUT); //settimg the input pin fir the LDR sensor
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {
  Serial.println(analogRead(A5));// Reading the values from the sensor
  if (analogRead(A5 < 3))
    analogWrite(2, HIGH);
}
