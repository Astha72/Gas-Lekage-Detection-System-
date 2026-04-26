# Gas-Lekage-Detection-System-

# 🔥 Gas Leakage Detection System (MQ6 + ESP32)

This project is a **Gas Leakage Detection System** built using **ESP32** and **MQ-6 Gas Sensor**.
It detects LPG/propane gas leakage and alerts using **LED and Buzzer**.

---

## 🚀 Features

* 🔥 Fast gas detection using optimized threshold
* 🔊 Buzzer alert (5 seconds pulse)
* 💡 LED indicator
* 📉 Noise reduction using averaging
* 🧠 Hysteresis logic (prevents false triggers)
* ⚡ Works on ESP32

---

## 🧰 Components Required

* ESP32 Board
* MQ-6 Gas Sensor
* Buzzer
* LED
* Resistor (220Ω)
* Jumper Wires
* Breadboard

---

## ⚙️ Pin Configuration

| Component          | ESP32 Pin |
| ------------------ | --------- |
| MQ-6 Analog Output | GPIO 34   |
| Buzzer             | GPIO 25   |
| LED                | GPIO 26   |

---

## 🔌 Circuit Diagram / Setup

### 🧪 MQ-6 Sensor Setup

![MQ6 Setup](images/mq6_setup.png)

### 💡 LED & Buzzer Connection

![LED Buzzer Setup](images/led_buzzer.png)

---

## 🛠️ Installation & Setup

### 1️⃣ Install Arduino IDE

Download: https://www.arduino.cc/en/software

---

### 2️⃣ Add ESP32 Board

Go to:

```
File → Preferences → Additional Board Manager URLs
```

Paste:

```
https://dl.espressif.com/dl/package_esp32_index.json
```

Then:

```
Tools → Board → Board Manager → Install ESP32
```

---

### 3️⃣ Required Libraries

👉 No external libraries required
(Uses built-in Arduino functions)

---

### 4️⃣ Upload Code

* Select Board: **ESP32 Dev Module**
* Select correct COM Port
* Click Upload

---

## ⏳ Important Step

⚠️ **Sensor Warmup Required**

* After powering ON, wait **20 seconds**
* MQ-6 sensor stabilizes during this time

---

## 📊 Working Logic

* Sensor reads gas values continuously
* If value > threshold → 🚨 GAS DETECTED
* LED turns ON
* Buzzer sounds for 5 seconds
* If gas level drops → ✅ SAFE

---

## 🔧 Code Highlights

* Noise reduction using averaging
* Hysteresis prevents fluctuation
* Timed buzzer control

---

## 📸 Output Example

```
Gas Value: 320
Gas Value: 540
⚠️ GAS DETECTED!
Gas Value: 480
Gas Value: 420
✅ SAFE
```

---

## 📌 Future Improvements

* 📱 Mobile notification (IoT)
* 🌐 WiFi monitoring dashboard
* 📊 Data logging

---

## 👨‍💻 Author

Made with ❤️ by [Your Name]

---

## ⭐ Give a Star

If you like this project, please ⭐ the repo!
