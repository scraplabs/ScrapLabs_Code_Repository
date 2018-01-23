#define switchPin A0
//one terminal of switch on Vcc. other on pin A0

#define pumpPin 12
//one terminal of Pump is grounded. Other on pin 12

int switchInput;
bool switchState = false;
bool pumpState = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);
  pinMode(pumpPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = true;

  for (int i = 0; i < 50; i++) {

    switchInput = analogRead(switchPin);
    if (switchInput != 1023) {
      switchState = false;
    }
    delay(5);
  }

  if (switchState == true) {

    digitalWrite(pumpPin, HIGH);
  }
  else {

    digitalWrite(pumpPin, LOW);
  }
}
