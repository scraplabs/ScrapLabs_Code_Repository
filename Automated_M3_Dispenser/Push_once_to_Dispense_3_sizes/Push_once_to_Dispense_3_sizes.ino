#define smallSwitchPin A0
#define mediumSwitchPin A1
#define largeSwitchPin A2
//one terminal of switch on Vcc. other on pin A0/A1/A2

#define pumpPin 12
//one terminal of Pump is grounded. Other on pin 12

int smallSwitchInput;
int mediumSwitchInput;
int largeSwitchInput;

bool smallSwitchState = false;
bool mediumSwitchState = false;
bool largeSwitchState = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(smallSwitchPin, INPUT);
  pinMode(mediumSwitchPin, INPUT);
  pinMode(largeSwitchPin, INPUT);

  pinMode(pumpPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 50; i++) {
    smallSwitchInput = analogRead(smallSwitchPin);
    mediumSwitchInput = analogRead(mediumSwitchPin);
    largeSwitchInput = analogRead(largeSwitchPin);

    if (smallSwitchInput == 1023) {
      smallSwitchState = true;
    }
    else {
      smallSwitchState = false;
    }

    if (mediumSwitchInput == 1023) {
      mediumSwitchState = true;
    }
    else {
      mediumSwitchState = false;
    }
    if (largeSwitchInput == 1023) {
      largeSwitchState = true;
    }
    else {
      largeSwitchState = false;
    }
    delay(5);
  }

  if (smallSwitchState == true) {

    digitalWrite(pumpPin, HIGH);
    delay(3000);
    digitalWrite(pumpPin, LOW);

  }

  else if (mediumSwitchState == true) {

    digitalWrite(pumpPin, HIGH);
    delay(5000);
    digitalWrite(pumpPin, LOW);

  }

  else if (largeSwitchState == true) {

    digitalWrite(pumpPin, HIGH);
    delay(7000);
    digitalWrite(pumpPin, LOW);

  }

  else {

    digitalWrite(pumpPin, LOW);
  }
}
