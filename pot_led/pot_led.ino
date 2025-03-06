#define LED 3
#define POT A0

int potValue = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(POT, INPUT);
  Serial.begin(9600);
}

void loop() {
  potValue = analogRead(POT);
  potValue = map(potValue, 0, 1023, 0, 255);
  analogWrite(LED,potValue);
}