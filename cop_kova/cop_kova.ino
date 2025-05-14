#include <Servo.h>
Servo sg90;
int trigger = 10;
int echo = 11;
int gled = 6;


long time;
long distance;

void setup() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(gled,OUTPUT);
  Serial.begin(9600);
  sg90.attach(13);
}

void loop() {
  digitalWrite(trigger, 0);
  delayMicroseconds(5);
  digitalWrite(trigger, 1);
  delayMicroseconds(10);
  digitalWrite(trigger, 0);

  time = pulseIn(echo, 1);
  distance = time / 29.1 / 2;

  Serial.print("   ");
  Serial.print("right: ");
  Serial.println(distance);

  if (distance < 30)

  {
    sg90.write(130);
    digitalWrite(gled,1);
  }

  else {
    delay(1000);
    sg90.write(80);
  }
}
