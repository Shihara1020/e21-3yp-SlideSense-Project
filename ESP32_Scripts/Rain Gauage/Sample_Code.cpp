const float mmPerPulse = 0.173;  // rain per tip (mm)

float totalRain = 0;
const int sensorPin = 14;  // you can change this (14, 27, 26)

volatile int tipCount = 0;

void IRAM_ATTR countTip() {
  tipCount++;   // interrupt increments tip count
}

void setup() {
  Serial.begin(115200);

  pinMode(sensorPin, INPUT_PULLUP);  // better stability

  // attach interrupt
  attachInterrupt(digitalPinToInterrupt(sensorPin), countTip, FALLING);
}

void loop() {
  static int lastCount = 0;

  if (tipCount != lastCount) {
    totalRain = tipCount * mmPerPulse;

    Serial.print("Rainfall: ");
    Serial.print(totalRain);
    Serial.println(" mm");

    lastCount = tipCount;
  }

  delay(500);
}
