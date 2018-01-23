#define lmotordir 2
#define lmotorspeed 3
#define rmotordir 4
#define rmotorspeed 5


void setup() {
  // put your setup code here, to run once:
  pinMode(lmotordir, OUTPUT);
  pinMode(lmotorspeed, OUTPUT);
  pinMode(rmotordir, OUTPUT);
  pinMode(rmotorspeed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(lmotordir, LOW);
  analogWrite(lmotorspeed, 200);
  digitalWrite(rmotordir, LOW);
  analogWrite(rmotorspeed, 200);

}
