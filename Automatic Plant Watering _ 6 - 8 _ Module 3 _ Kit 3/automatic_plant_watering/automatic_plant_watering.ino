//the voltage reading to be taken from pin A0
#define sensPin A0

//only one pin for pump as we dont need to reverse it
#define pumpPin 3

//LED pin
#define led 13

//declaring variable to store sensor value later;
int sensVal;

//declaring variable to store state of pump later
//true -> pump ON
//false -> pump OFF
//assuming pump is OFF initially
bool pumpState = false;

void setup() {

  pinMode(sensPin, INPUT);
  pinMode(pumpPin, OUTPUT);
  pinMode(led, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  sensVal = analogRead(sensPin);

  Serial.print("Sensor Value : ");
  Serial.print(sensVal);
  Serial.print(" | ");

  if (sensVal <= 400) {

    pumpState = true;
    digitalWrite(led, HIGH);
  }

  else if (sensVal >= 600) {

    pumpState = false;
    digitalWrite(led, LOW);
  }

  else {

    //nothing to do here
  }

  Serial.print("Pump State : ");
  Serial.print(pumpState);
  Serial.println();

  if (pumpState == true) {

    //pump ON for 1 sec
    analogWrite(pumpPin, 200);
    delay(1000);

    //pump OFF for 10 sec to let water seep in
    analogWrite(pumpPin, 0);
    delay(10000);

    /*
    set pumpState to OFF again
    if water isnt sufficient it will be set back to
    true when loop repeats
    */
    pumpState = false;
  }
}
