#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Servo.h>

#define dhtPin 6
#define dhtType DHT11

#define servoPin 9

DHT_Unified dht(dhtPin, dhtType);
uint32_t delayMS;

Servo gaugeServo;

int temp;
int pos;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  dht.begin();

  gaugeServo.attach(servoPin);

  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  //dht.humidity().getSensor(&sensor);

  delayMS = sensor.min_delay / 1000;
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(delayMS);

  sensors_event_t event;

  dht.temperature().getEvent(&event);
  temp = event.temperature;
  
  Serial.print("Temp : ");
  Serial.print(temp);
  Serial.print(" *C");
  

  /*
    dht.humidity().getEvent(&event);
    Serial.print("Hum : ");
    Serial.print(event.relative_humidity);
    Serial.print(" %");
    Serial.println();
  */

  temp = constrain(temp,0,60);
  pos = map(temp,0,60,180,0);

  gaugeServo.write(pos);

  Serial.print(" | ");
  Serial.print("Position : ");
  Serial.print(pos);
  Serial.println();
}
