
# 🔥 Smoke and Gas Detector – IoT-Based Real-Time Safety System

An IoT-powered Smoke and Gas Detection system that continuously monitors air quality for dangerous gas concentrations and smoke particles, providing **instant mobile alerts**, **buzzer warnings**, and **cloud data logging**.

## 📌 Project Overview

This project uses **NodeMCU ESP8266**, **MQ-2 gas sensor**, and the **Blynk IoT platform** to detect harmful gases like **LPG, Carbon Monoxide (CO), Methane**, and smoke in the environment. When a dangerous concentration is detected, it triggers:

- 🚨 A buzzer alarm  
- 🔴 Red LED indicator  
- 📲 A push notification via Blynk mobile app  

This makes it ideal for **homes, kitchens, industrial spaces**, and **commercial buildings**.

---

## 📷 System Architecture

- **Gas/Smoke Sensor** (MQ-2 or MQ-135)  
- **Microcontroller**: NodeMCU (ESP8266)  
- **Output Devices**: Buzzer, Red & Green LEDs  
- **Cloud**: Blynk IoT Platform  
- **Connectivity**: Wi-Fi  

---

## 🛠️ Features

- Real-time monitoring of air quality
- Mobile alerts via Blynk app
- On-device buzzer and LED indicators
- Configurable thresholds to reduce false alarms
- Low-cost and energy-efficient design
- Compatible with solar or battery power
- Modular and scalable for future upgrades

---

## 🚀 Technologies Used

| Hardware | Software |
|----------|----------|
| NodeMCU ESP8266 | Arduino IDE |
| MQ-2 / MQ-135 Sensor | Blynk IoT App |
| Buzzer, LEDs | Firebase (optional for logging) |
| Breadboard, Resistors, Jumper Wires | C++ Firmware Code |

---

## 🧪 Setup Instructions

1. **Hardware**
   - Connect MQ-2 sensor analog pin to `A0` of NodeMCU.
   - Attach the buzzer to a digital pin (e.g., D5).
   - Wire up Red and Green LEDs with 220Ω resistors.
   - Power the board using USB or external 5V source.

2. **Software**
   - Install [Arduino IDE](https://www.arduino.cc/en/software)
   - Add ESP8266 board support via Board Manager.
   - Install the **Blynk** library.
   - Flash the code from `/code/smoke_gas_detector.ino`.

3. **Blynk Setup**
   - Create a new project in Blynk.
   - Add widgets: `Value Display`, `Notification`.
   - Link your auth token in the Arduino sketch.

---

## 💻 Sample Code Snippet

```cpp
int red_LED_PIN = 7;
int green_LED_PIN = 6;
int buzzer = 5;
int smoke_detector = A0;
int safety_lim = 150;

void setup() {
  pinMode(red_LED_PIN, OUTPUT);
  pinMode(green_LED_PIN, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smoke_detector, INPUT);
  Serial.begin(9600);
}

void loop() {
  int sensor_read = analogRead(smoke_detector);
  Serial.println("Smoke Density: " + String(sensor_read));

  if (sensor_read > safety_lim) {
    digitalWrite(red_LED_PIN, HIGH);
    digitalWrite(green_LED_PIN, LOW);
    tone(buzzer, 9999, 500);
  } else {
    digitalWrite(green_LED_PIN, HIGH);
    digitalWrite(red_LED_PIN, LOW);
    noTone(buzzer);
  }
  delay(50);
}
