#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

bool motion = true; //true - clockwise | false - anti-clockwise

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  if (motion == true) {
    pos++;
  }
  if (motion == false) {
    pos--;
  }
  myservo.write(pos);
  delay(10);
  Serial.println(pos);

  if (pos == 180) {
    motion = false;
  }
  if (pos == 0) {
    motion = true;
  }
}
