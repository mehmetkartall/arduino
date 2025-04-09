int trigger = 10;
int echo = 11;

long time;
long distance;

void setup() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
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
}
