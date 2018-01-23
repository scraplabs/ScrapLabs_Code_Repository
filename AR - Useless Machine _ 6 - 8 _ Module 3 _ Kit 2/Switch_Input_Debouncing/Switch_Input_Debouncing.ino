
//switch is connected to digital pin number 10
#define switchPin 10

//initiallizing variable to store the switch input values later
int switchVal;

//initiallizing sum to use in debouncing
int sum;

//initiallizing boolean to help in debouncing
bool switchState;

void setup() {

  //set the switchPin to input mode
  pinMode(switchPin, INPUT);

  //initiallize the Serial communication with PC
  Serial.begin(9600);
  //the baud rate of Serial communication is 9600
}

void loop() {

  //assume switch if OFF initially
  switchState = false;
  sum = 0;

  //read 50 values
  for (int i = 0; i < 50; i++) {

    switchVal = digitalRead(switchPin);
    sum = sum + switchVal;
  }

  sum = sum / 50;

  if (sum == 1) {

    switchState = true;
  }
  else {

    switchState = false;

  }

  //print the values on Serial monitor
  Serial.println(switchState);
}
