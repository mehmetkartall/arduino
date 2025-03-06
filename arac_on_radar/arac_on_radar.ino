int trig_left = 8;
int trig_right = 10;
//sync
//sync2
int echo_left = 9;
int echo_right = 11;

long time_left;
long time_right;

long distance_left;
long distance_right;

int buzzer 12;


void setup() {

  pinMode(trig_left, OUTPUT);
  //pinMode(trig_right, OUTPUT);
  pinMode(echo_left, INPUT);
  pinMode(buzzer, OUTPUT);
  //pinMode(echo_right, INPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig_left, 0);
  delayMicroseconds(5);
  digitalWrite(trig_left, 1);
  delayMicroseconds(10);
  digitalWrite(trig_left, 0);

  time_left = pulseIn(echo_left, 1);
  distance_left = time_left / 29.1 / 2;


  /* digitalWrite(trig_right, 0);
  delayMicroseconds(5);
  digitalWrite(trig_right, 1);
  delayMicroseconds(10);
  digitalWrite(trig_right, 0);

  time_right = pulseIn(echo_right, 1);
  distance_right = time_right / 29.1 / 2; */

  Serial.print("left: ");
  Serial.println(distance_left);
  //Serial.print("   ");
  //Serial.print("right: ");
  //Serial.println(distance_right);

  if (distance_left < 25)
    ;
  {
    digitalWrite(buzzer, 1);
  }
  else {
    digitalWrite(buzzer, 0);
  }
}
