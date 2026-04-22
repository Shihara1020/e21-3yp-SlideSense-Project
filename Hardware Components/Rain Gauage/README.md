# 🌧️ Arduino Tipping Bucket Rain Gauge

It measures rainfall by counting the number of times a bucket tips due to collected water and displays the result on an LCD screen.

The system uses a **Hall effect sensor and magnet** to detect each tip and calculates total rainfall based on calibrated values.



## ⚙️ How It Works

* Rainwater is collected through a funnel.
* Water fills one side of a **tipping bucket mechanism**.
* When the bucket reaches a certain weight, it tips.
* A **magnet attached to the bucket** passes near a Hall effect sensor.
* The Arduino detects this and increments rainfall count.
* Each tip corresponds to a fixed amount of rainfall (e.g., mm).
* The total rainfall is shown on the LCD display.



## 🧰 Components Required

* Arduino (UNO / Nano / compatible)
* Hall effect sensor
* Small magnet
* steel
* self-locking nuts
* Washers
* Flat aluminum profile
* 3-wire cable
* 3D printed parts (bucket, frame, funnel)



## 🛠️ Tools Required

* Soldering iron
* Wrenches
* 3D printer
* Computer with Arduino IDE



## 🖨️ 3D Printing

* Material: PLA (works, but PETG is recommended for outdoor use)
* Print all parts from provided `.stl` files
* Ensure proper alignment and smooth movement of the bucket



## 🔌 Circuit Connections

* Hall Sensor VCC → Arduino 5V
* Hall Sensor GND → Arduino GND
* Hall Sensor OUT → Arduino Digital Pin (e.g., D2)
* LCD SDA → A4 (UNO)
* LCD SCL → A5 (UNO)




## 📏 Calibration

Each tip equals a fixed rainfall amount. To calibrate:

1. Pour a known amount of water.
2. Count number of tips.
3. Calculate:

   ```
   calibrationFactor = total_water(mm) / number_of_tips
   ```



## Output

* Real-time rainfall displayed on LCD
* Can be extended to:

  * Store data
  * Send to cloud (IoT)
  * Trigger alerts




