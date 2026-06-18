#include <Arduino.h>
#include <Servo.h>

// ===== SOS =====
int startButton = 2;
int stopButton = 3;

int ledPin = 13;
int buzzerPin = 8;

bool recording = false;

// ===== SNATCH =====
int potPin = A0;
Servo lockServo;

int lastValue = 0;
bool locked = false;

// ===== RECORDING TIMER =====
unsigned long lastRecordPrint = 0;

// ===== GEOFENCING =====
unsigned long startTime;
bool breached = false;
unsigned long lastLocationUpdate = 0;

// fake coordinates
float lat = 18.5204;
float lon = 73.8567;

void setup() {
  pinMode(startButton, INPUT_PULLUP);
  pinMode(stopButton, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  lockServo.attach(9);
  lockServo.write(0);

  Serial.begin(9600);

  startTime = millis();

  // 🟢 Initial location
  Serial.print("📍 Current Location: ");
  Serial.print(lat, 4);
  Serial.print(" N, ");
  Serial.print(lon, 4);
  Serial.println(" E");

  Serial.println("🟢 Status: Safe Zone");
}

void loop() {

  unsigned long currentTime = millis();

  // =========================
  // 📍 GEOFENCING
  // =========================

  // After 20 sec → breach
  if (!breached && currentTime - startTime >= 20000) {
    breached = true;

    lat += 0.0010;
    lon += 0.0010;

    Serial.println("🚨 ALERT! Boundary Breached!");
    Serial.print("📍 Location: ");
    Serial.print(lat, 4);
    Serial.print(" N, ");
    Serial.print(lon, 4);
    Serial.println(" E");

    lastLocationUpdate = currentTime;
  }

  // Every 40 sec → update location
  if (breached && currentTime - lastLocationUpdate >= 40000) {
    lastLocationUpdate = currentTime;

    lat += 0.0005;
    lon += 0.0005;

    Serial.println("📡 Updating Location...");
    Serial.print("📍 Location: ");
    Serial.print(lat, 4);
    Serial.print(" N, ");
    Serial.print(lon, 4);
    Serial.println(" E");
  }

  // =========================
  // 🔘 START BUTTON
  // =========================
  if (digitalRead(startButton) == LOW) {
    if (!recording) {
      recording = true;

      Serial.println("🚨 SOS ACTIVATED!");
      Serial.println("🎤 Audio Recording Started...");
      Serial.println("🎥 Video Recording Started...");
      Serial.println("📡 Sending alert...");

      tone(buzzerPin, 1000, 300);
      delay(300);
    }
  }

  // =========================
  // 🔘 STOP BUTTON
  // =========================
  if (digitalRead(stopButton) == LOW) {
    if (recording) {
      recording = false;

      Serial.println("🛑 Recording Stopped!");
      Serial.println("💾 Data Saved");
      Serial.println("📤 Sent to relatives");

      tone(buzzerPin, 500, 300);
      delay(300);
    }
  }

  // =========================
  // 🎥 RECORDING MODE
  // =========================
  if (recording) {
    digitalWrite(ledPin, HIGH);

    if (millis() - lastRecordPrint >= 1000) {
      lastRecordPrint = millis();
      Serial.println("📀 Recording...");
    }

  } else {
    digitalWrite(ledPin, LOW);
  }

  // =========================
  // 🚨 SNATCH DETECTION
  // =========================
  int currentValue = analogRead(potPin);
  int difference = abs(currentValue - lastValue);

  if (difference > 200 && !locked) {

    locked = true;

    Serial.println("🚨 SNATCH DETECTED!");
    Serial.println("🔒 Auto Lock Activated!");

    lockServo.write(90);
    digitalWrite(ledPin, HIGH);
  }

  lastValue = currentValue;
}