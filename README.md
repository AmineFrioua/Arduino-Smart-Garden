
# Smart Garden Arduino Project
Welcome to the Smart Garden Arduino Project repository! This project aims to create a fully automated and customizable smart garden system using the power of Arduino microcontrollers and various sensors.

# Getting Started
These instructions will guide you on how to set up and use the Smart Garden Arduino Project on your own garden.

# Prerequisites
To get started with this project, you will need the following:

Arduino board (Uno, Nano, or Mega)
Soil moisture sensor
Light sensor
Temperature and humidity sensor
Water pump or valve
Power source (battery or AC adapter)
Jumper wires
Breadboard (optional)
# Hardware Setup
- Connect the soil moisture sensor to the Arduino board using jumper wires. Connect the VCC pin to 3.3V, GND pin to GND, and the SIG pin to A0.
- Connect the light sensor to the Arduino board using jumper wires. Connect the VCC pin to 3.3V, GND pin to GND, and the SIG pin to A1.
- Connect the temperature and humidity sensor to the Arduino board using jumper wires. Connect the VCC pin to 3.3V, GND pin to GND, and the SIG pin to A2.
- Connect the water pump or valve to the Arduino board using jumper wires. Connect the VCC pin to a digital pin (such as D5) and the GND pin to GND.
- Connect the power source to the Arduino board.
# Software Setup
- Download and install the Arduino IDE on your computer.
- Open the Arduino IDE and go to File > Preferences. Under "Additional Board Manager URLs," enter "https://arduino.esp8266.com/stable/package_esp8266com_index.json" and click OK.
- Go to Tools > Board > Boards Manager. Search for "esp8266" and install the latest version of the ESP8266 board.
- Download the Smart Garden Arduino Project code from this repository and open it in the Arduino IDE.
- In the Arduino IDE, go to Tools > Board and select the ESP8266 board you installed earlier.
- Go to Tools > Port and select the port your Arduino board is connected to.
- Click the upload button to upload the code to your Arduino board.
# Customization

You can customize the Smart Garden Arduino Project to fit your specific needs by modifying the code and adjusting the thresholds for moisture, light, temperature, and humidity levels. You can also add additional sensors or actuators to the system to control other aspects of your garden, such as pH levels or automatic fertilization.

# Built With
Arduino - Microcontroller platform
Soil Moisture Sensor - To measure soil moisture levels
Light Sensor - To measure light levels
Temperature and Humidity Sensor - To measure temperature and humidity levels
Water Pump - To automatically water the plants
