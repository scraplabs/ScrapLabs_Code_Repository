
//switch is connected to digital pin number 10
#define switchPin 10

//initiallizing variable to store the switch input values later
int switchVal;

void setup() {
  
  //set the switchPin to input mode
  pinMode(switchPin, INPUT);
  
  //initiallize the Serial communication with PC
  Serial.begin(9600);
  //the baud rate of Serial communication is 9600
}

void loop() {
  
  //read values
  switchVal = digitalRead(switchPin);
  
  //print the values on Serial monitor
  Serial.println(switchVal);
}
