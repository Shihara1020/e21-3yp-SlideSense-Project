# SlideSence: AI-Powered IoT Landslide Monitoring System 🏔️⚠️

[![Status](https://img.shields.io/badge/Status-In%20Progress-yellow)](https://github.com/yourusername/SlideSence)
[![Platform](https://img.shields.io/badge/Platform-ESP32%20%7C%20AWS%20IoT-blue)](https://aws.amazon.com/iot/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B%20%7C%20Python-green)](https://github.com/yourusername/SlideSence)
[![License](https://img.shields.io/badge/License-MIT-lightgrey)](LICENSE)

**SlideSence** is an advanced IoT-based early warning system designed to detect landslide-prone conditions and alert communities in real-time. By monitoring soil moisture, rainfall intensity, and ground stability, SlideSence bridges the gap between environmental data and life-saving alerts.



## 📖 Table of Contents
- [Motivation](#-motivation)
- [System Architecture](#-system-architecture)
- [Key Features](#-key-features)
- [Tech Stack](#-tech-stack)
- [Hardware Requirements](#-hardware-requirements)
- [Future Enhancements](#-future-enhancements)



## 💡 Motivation
Landslides often occur suddenly during extreme weather, frequently cutting off the very cellular and internet networks that traditional warning systems rely on. 

**SlideSence addresses:**
* **Connectivity Gaps:** Reliable local communication when the cloud is unreachable.
* **Power Constraints:** Optimized for remote, battery-powered deployments.
* **Latency:** Real-time localized processing for immediate evacuation triggers.



## 🏗 System Architecture



The system operates across four distinct layers to ensure redundancy and reliability:

1.  **Sensor Layer:** ESP32-linked sensors monitoring moisture, tilt, and rainfall.
2.  **Edge Layer:** Local data processing on ESP32 with burst-mode capability during high-risk events.
3.  **Gateway Layer:** A Raspberry Pi acting as a local MQTT broker and Wi-Fi hotspot during network failures.
4.  **Cloud Layer:** AWS/Firebase integration for long-term storage, ML analysis, and global notifications (FCM).



## 🚀 Key Features
* **Hybrid Communication:** Uses MQTT for lightweight data transfer and Firebase (FCM) for push notifications.
* **Multi-Level Alerts:** Three-tier logic system: `NORMAL` | `WARNING` | `DANGER`.
* **Offline Resilience:** Gateway mode allows local device-to-device alerts even if the global internet fails.
* **Power Efficient:** Deep-sleep cycles and solar-ready power management.



## 🛠 Tech Stack
| Component | Technology |
| :--- | :--- |
| **Microcontroller** | ESP32 (C++/Arduino) |
| **Gateway** | Raspberry Pi (Python) |
| **Communication** | MQTT, WebSockets |
| **Cloud/Backend** | Firebase, AWS IoT Core |
| **Analysis** | Python (NumPy, Pandas) |
| **Frontend** | React/Flutter (Mobile & Web) |

## ⚙️ Hardware Components
* **ESP32:** Main processing unit for sensor nodes.
* **Raspberry Pi (3/4):** Central gateway and local server.
* **Sensors:** * Capacitive Soil Moisture Sensor
    * Tipping Bucket Rain Gauge
    * MPU6050 (Accelerometer/Gyroscope for tilt detection)
* **Power:** 18650 Li-ion batteries + 5V Solar panels.



## 📈 Future Enhancements
- [ ] **ML Integration:** Deploying TensorFlow Lite models on the Edge for better prediction accuracy.
- [ ] **LoRaWAN Support:** Expanding range to 10km+ for deep valley deployments.
- [ ] **SMS Fallback:** Integration with Twilio for non-smartphone users.
- [ ] **Public API:** Allowing local authorities to pull real-time environmental data.


## 🤝 Contributing
Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request



## 📄 License
Distributed under the MIT License. See `LICENSE` for more information.
