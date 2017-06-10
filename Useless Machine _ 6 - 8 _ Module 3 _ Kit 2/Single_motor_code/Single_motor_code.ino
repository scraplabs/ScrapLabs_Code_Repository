//BO motor connected to pins 2 & 3

//pin 2 is digital pin giving direction to motor
//LOW - forward & HIGH - backward
#define motorDirPin 2

//pin 3 is digital PWM pin giving speed to motor
//can range between 0(Stop) to 255(Full ahead) in case of forward
//or 255(Stop) to 0(full reverse) in case of backwards
#define motorSpeedPin 3

void setup() {

  //set the motor pins to output mode
  pinMode(motorDirPin, OUTPUT);
  pinMode(motorSpeedPin, OUTPUT);

}

void loop() {

  //run the motor full speed forward
  //give LOW on dir pin - forward
  //give 255 on speed pin for full speed
  digitalWrite(motorDirPin, LOW);
  analogWrite(motorSpeedPin, 255);
  //analogWrite instead of digitalWrite because PWM pin

  //2 seconds of operation in this mode
  delay(2000);

  //run the motor moderate speed forward
  //give LOW on dir pin - forward
  //give 150 on speed pin for moderate speed
  digitalWrite(motorDirPin, LOW);
  analogWrite(motorSpeedPin, 150);
  //analogWrite instead of digitalWrite because PWM pin

  //2 seconds of operation in this mode
  delay(2000);

  //stop the motor
  //give LOW on dir pin - forward
  //give 0 on speed pin for stopping
  digitalWrite(motorDirPin, LOW);
  analogWrite(motorSpeedPin, 0);
  //analogWrite instead of digitalWrite because PWM pin

  //2 seconds of operation in this mode
  delay(2000);

  //run the motor full speed backward
  //give HIGH on dir pin - backward
  //give 0 on speed pin for full speed
  digitalWrite(motorDirPin, HIGH);
  analogWrite(motorSpeedPin, 0);
  //analogWrite instead of digitalWrite because PWM pin

  //2 seconds of operation in this mode
  delay(2000);

  //run the motor moderate speed backward
  //give HIGH on dir pin - backward
  //give 105 on speed pin for moderate speed
  digitalWrite(motorDirPin, HIGH);
  analogWrite(motorSpeedPin, 105);
  //analogWrite instead of digitalWrite because PWM pin

  //2 seconds of operation in this mode
  delay(2000);

  //stop the motor
  //give HIGH on dir pin - backward
  //give 255 on speed pin for stopping
  digitalWrite(motorDirPin, HIGH);
  analogWrite(motorSpeedPin, 255);
  //analogWrite instead of digitalWrite because PWM pin

  //2 seconds of operation in this mode
  delay(2000);

}
