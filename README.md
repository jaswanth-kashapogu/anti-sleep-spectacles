# 🕶️ Anti-Sleep Detection Spectacles

An IoT-based wearable safety device designed to detect driver drowsiness and prevent accidents. Built with an Arduino Uno, this project monitors eye movement and triggers an alarm if the user falls asleep.

## 🚀 How It Works
The system uses an eye-blink/IR sensor mounted on a spectacle frame. The microcontroller continuously monitors the sensor state using non-blocking time tracking (`millis()`). 
* If the user's eyes close, a timer starts.
* If the eyes remain closed for **more than 2 seconds** (2000ms), a buzzer is activated to wake the user.
* The system instantly resets the alarm once the user opens their eyes.

## 🛠️ Hardware & Wiring
* **Microcontroller:** Arduino Uno
* **Sensor:** Eye Blink / IR Sensor -> Connected to **Digital Pin 2**
* **Actuator:** 5V Buzzer -> Connected to **Digital Pin 8**

## 💻 The Code
The core logic is written in C++ for the Arduino environment. It utilizes a state-machine approach rather than standard `delay()` functions, ensuring the processor is never blocked and can handle real-time sensor polling. 

## 📸 Project Showcase
*(Drop a photo of your spectacles here! Rename your photo to `project.jpg` and uncomment the line below)*
---
**Built by Jaswanth Raj** | 
*Vibe Coder | Building at the intersection of AI, Cybersecurity, and Embedded Systems. From networking concepts to wiring Arduino circuits*