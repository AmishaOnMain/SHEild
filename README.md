# 🛡️ Smart Safety Band for Women (SHEild)

## 📌 Project Overview

The Smart Safety Band is an IoT-based wearable safety prototype designed to enhance personal security through emergency alerts, geofencing, and snatch detection mechanisms. The system provides instant SOS activation, simulated location tracking, emergency recording functionality, and an automatic locking mechanism to prevent unauthorized removal.

---

## 🎯 Problem Statement

In emergency situations, users may not have sufficient time to contact family members or authorities. This project aims to provide a wearable safety solution that can automatically trigger alerts, monitor location, and secure the device when suspicious activity is detected.

---

## ✨ Features

### 🚨 SOS Emergency Activation
- One-click emergency activation using a push button.
- Simulates:
  - Audio recording
  - Video recording
  - Alert transmission to relatives
- Buzzer notification for confirmation.

### 🎥 Recording System
- Recording status displayed on Serial Monitor.
- LED indicator remains ON during recording.
- Recording can be stopped using a dedicated button.
- Simulates data saving and sharing.

### 📍 Geofencing
- Monitors whether the user remains inside a predefined safe zone.
- Detects boundary breaches.
- Generates alerts and location updates.
- Simulated GPS coordinate tracking.

### 🔒 Snatch Detection
- Detects sudden movement or forceful removal attempts.
- Automatically activates lock mechanism.
- Prevents unauthorized removal of the wearable.

### 🔔 Alert System
- LED-based visual alerts.
- Buzzer-based audio notifications.
- Serial Monitor emergency logs.

---

## 🛠 Hardware Components

| Component | Quantity |
|------------|-----------|
| Arduino UNO | 1 |
| Push Button (Start) | 1 |
| Push Button (Stop) | 1 |
| Servo Motor | 1 |
| Buzzer | 1 |
| LED | 1 |
| 220Ω Resistor | 1 |
| Potentiometer | 1 |
| Jumper Wires | As Required |

---

## 📂 Project Structure

```text
final-demo/
│
├── .pio/
├── .vscode/
├── include/
├── lib/
├── src/
│   └── main.cpp
│
├── test/
├── .gitignore
├── diagram.json
├── platformio.ini
└── wokwi.toml
```

---

## 🔌 Pin Configuration

| Component | Arduino Pin |
|------------|-------------|
| Start Button | D2 |
| Stop Button | D3 |
| LED | D13 |
| Buzzer | D8 |
| Servo Motor | D9 |
| Potentiometer | A0 |

---

## ⚙️ Software Requirements

- PlatformIO
- Visual Studio Code
- Wokwi Simulator
- Arduino Framework
- Servo Library

---

## 🔄 System Workflow

### Normal Mode
- Device initializes in a safe zone.
- Current coordinates are displayed.
- Sensors are continuously monitored.

### SOS Mode
When the Start Button is pressed:

1. SOS is activated.
2. Audio recording starts.
3. Video recording starts.
4. Alert is generated.
5. Buzzer confirmation is triggered.
6. Recording status is updated every second.

### Stop Mode
When the Stop Button is pressed:

1. Recording stops.
2. Data is saved.
3. Emergency information is shared.
4. Confirmation tone is generated.

### Geofencing Mode
- Simulates boundary breach after a predefined interval.
- Generates emergency alert.
- Updates location coordinates periodically.

### Snatch Detection Mode
- Detects sudden sensor-value changes.
- Activates servo-based lock.
- Generates emergency notification.
- Turns ON LED indicator.

---

## 📍 Simulated GPS Coordinates

### Initial Location

```text
Latitude  : 18.5204 N
Longitude : 73.8567 E
```

### Sample Breach Location

```text
Latitude  : 18.5214 N
Longitude : 73.8577 E
```

---

## 🧪 Simulation Environment

The project is simulated using **Wokwi** and includes:

- Arduino UNO
- Servo Motor
- Potentiometer
- LED
- Buzzer
- Push Buttons

The simulation demonstrates the complete functionality of the Smart Safety Band prototype.

---

## 🚀 How to Run the Prototype

### Method 1: Run Using Wokwi (Recommended)

#### Step 1: Copy the Project Files

Create the following files:

```text
final-demo/
│
├── src/
│   └── main.cpp
│
├── diagram.json
├── platformio.ini
└── wokwi.toml
```

#### Step 2: Paste the Code

1. Open `src/main.cpp`
2. Copy the Arduino source code.
3. Paste it into `main.cpp`.
4. Save the file.

#### Step 3: Add Circuit Configuration

1. Open `diagram.json`
2. Copy the provided Wokwi circuit configuration.
3. Paste and save the file.

#### Step 4: Configure PlatformIO

Ensure `platformio.ini` contains:

```ini
[env:uno]
platform = atmelavr
board = uno
framework = arduino
lib_deps =
    arduino-libraries/Servo
```

#### Step 5: Start Simulation

1. Open Visual Studio Code.
2. Install:
   - PlatformIO Extension
   - Wokwi for VS Code Extension
3. Open the project folder.
4. Click the **Wokwi Start Simulation** button.

The simulation will launch with all connected components.

---

## 🎮 Prototype Usage Guide

### 🚨 SOS Activation

**Action:**
Press the **Green Start Button**

**Expected Output:**

```text
SOS ACTIVATED!
Audio Recording Started...
Video Recording Started...
Sending alert...
```

Additional actions:

- Buzzer beeps
- LED turns ON
- Recording status appears every second

```text
Recording...
Recording...
Recording...
```

---

### 🛑 Stop Recording

**Action:**
Press the **Red Stop Button**

**Expected Output:**

```text
Recording Stopped!
Data Saved
Sent to relatives
```

Additional actions:

- Confirmation buzzer sound
- LED turns OFF

---

### 📍 Geofencing Demonstration

After approximately **20 seconds**:

```text
ALERT! Boundary Breached!
Location: 18.5214 N, 73.8577 E
```

The system automatically simulates a safe-zone breach.

Every **40 seconds** afterward:

```text
Updating Location...
Location: ...
```

Location updates continue automatically.

---

### 🔒 Snatch Detection Demonstration

**Action:**

Rotate the potentiometer rapidly.

**Expected Output:**

```text
SNATCH DETECTED!
Auto Lock Activated!
```

Additional actions:

- Servo rotates to 90°
- Lock mechanism activates
- LED remains ON

---

## 📺 Demonstration Flow

1. Start Simulation.
2. Observe initial GPS location.
3. Press Start Button.
4. Verify SOS activation.
5. Observe recording logs.
6. Rotate potentiometer quickly.
7. Verify snatch detection and servo lock.
8. Wait for geofence breach alert.
9. Press Stop Button.
10. Verify recording termination and data-saving logs.

---

## 🧪 Sample Serial Monitor Output

```text
Current Location: 18.5204 N, 73.8567 E
Status: Safe Zone

SOS ACTIVATED!
Audio Recording Started...
Video Recording Started...
Sending alert...

Recording...
Recording...
Recording...

SNATCH DETECTED!
Auto Lock Activated!

ALERT! Boundary Breached!
Location: 18.5214 N, 73.8577 E

Updating Location...
Location: 18.5219 N, 73.8582 E

Recording Stopped!
Data Saved
Sent to relatives
```

---

## 📊 Expected Outcomes

- Improved personal safety
- Faster emergency response
- Real-time monitoring capability
- Automated threat detection
- Enhanced wearable security

---

## 👩‍💻 Author

**Amisha Patel**

B.Tech Computer Science Engineering

---

## 📜 License

This project is developed for educational and academic purposes only.

© 2026 Amisha Patel. All Rights Reserved.
