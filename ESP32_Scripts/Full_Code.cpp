#include <Arduino.h>
#include <TinyGPS++.h>

HardwareSerial SerialGPS(2);
TinyGPSPlus gps;

// ===== PINS =====
#define MOISTURE1 34
#define MOISTURE2 35
#define MOISTURE3 32
#define RAIN_PIN 27

// Rain counter
volatile int rainCount = 0;

// Interrupt for rain gauge
void IRAM_ATTR rainPulse() {
  rainCount++;
}

void setup() {
  Serial.begin(9600);

  // GPS
  SerialGPS.begin(9600);

  // Moisture pins
  pinMode(MOISTURE1, INPUT);
  pinMode(MOISTURE2, INPUT);
  pinMode(MOISTURE3, INPUT);

  // Rain gauge
  pinMode(RAIN_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(RAIN_PIN), rainPulse, FALLING);

  Serial.println("System Started...");
}

void loop() {

  // ===== GPS READ =====
  while (SerialGPS.available()) {
    gps.encode(SerialGPS.read());
  }

  float lat = 0.0, lng = 0.0;

  if (gps.location.isValid()) {
    lat = gps.location.lat();
    lng = gps.location.lng();
  }

  // ===== MOISTURE READ =====
  int m1 = analogRead(MOISTURE1);
  int m2 = analogRead(MOISTURE2);
  int m3 = analogRead(MOISTURE3);

  // ===== RAIN VALUE =====
  int rain = rainCount;

  // ===== PRINT DATA =====
  Serial.println("====== SENSOR DATA ======");

  Serial.print("GPS Lat: ");
  Serial.println(lat, 6);

  Serial.print("GPS Lng: ");
  Serial.println(lng, 6);

  Serial.print("Moisture 1: ");
  Serial.println(m1);

  Serial.print("Moisture 2: ");
  Serial.println(m2);

  Serial.print("Moisture 3: ");
  Serial.println(m3);

  Serial.print("Rain Count: ");
  Serial.println(rain);

  Serial.println("------------------------");

  delay(2000);
}
