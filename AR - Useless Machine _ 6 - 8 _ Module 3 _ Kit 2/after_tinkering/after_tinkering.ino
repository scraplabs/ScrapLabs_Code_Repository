
//switch is connected to digital pin number 10
#define switchPin 10

//BO motor connected to pins 2 & 3
#define motorDirPin 2

//pin 3 is digital PWM pin giving speed to motor
#define motorSpeedPin 3

//initiallizing variable to store the switch input values later
int switchVal;

void setup() {

  //set the motor pins to output mode
  pinMode(motorDirPin, OUTPUT);
  pinMode(motorSpeedPin, OUTPUT);

  //set the switchPin to input mode
  pinMode(switchPin, INPUT);
}

void loop() {

  //read values
  switchVal = digitalRead(switchPin);

  if (switchVal == 1) {

    digitalWrite(motorDirPin, LOW);
    analogWrite(motorSpeedPin, 200);

    //need to find out bby trial and error
    delay(300);

    digitalWrite(motorDirPin, HIGH);
    analogWrite(motorSpeedPin, 55);

    delay(300);

    //make the motor stationery
    digitalWrite(motorDirPin, LOW);
    analogWrite(motorSpeedPin, 0);
  }

  else {
    //do nothing
  }
}


