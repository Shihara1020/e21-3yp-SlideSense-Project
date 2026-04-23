const int sensorPin = 14;

void setup() {
  Serial.begin(115200);
  pinMode(sensorPin, INPUT);
}

void loop() {
  int state = digitalRead(sensorPin);
  Serial.println(state);
  delay(200);
}
