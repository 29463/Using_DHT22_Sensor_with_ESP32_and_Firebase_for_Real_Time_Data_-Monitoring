# Using_DHT22_Sensor_with_ESP32_and_Firebase_for_Real_Time_Data_Monitoring




Using DHT22 Sensor with ESP32 and Firebase for Real-Time Data Monitoring
This project demonstrates how to integrate a DHT22 temperature and humidity sensor with an ESP32 and Firebase to monitor environmental conditions. Firebase is used as a cloud platform to store and visualize data in real time.
________________________________________
Features of the System
1.	DHT22 Sensor:
o	Measures temperature and humidity with high accuracy.
o	Outputs digital signals directly.
2.	ESP32:
o	Acts as the microcontroller and Wi-Fi module.
o	Reads data from the DHT22 sensor and sends it to Firebase.
3.	Firebase:
o	Cloud platform for storing and visualizing data.
o	Provides real-time database functionality.
________________________________________
Components Required
1.	ESP32 microcontroller.
2.	DHT22 temperature and humidity sensor.
3.	Jumper wires.
4.	USB cable for programming and power.
5.	Firebase account.
________________________________________
DHT22 Sensor Specifications
1.	Key Features:
o	Measures temperature: -40°C to +80°C.
o	Measures humidity: 0-100% RH.
o	High accuracy: ±0.5°C for temperature, ±2% for humidity.
o	Digital output signal.
o	Sampling rate: 0.5 Hz (1 reading every 2 seconds).
2.	Pin Configuration:
o	VCC: Power input (3.3V or 5V).
o	GND: Ground.
o	DATA: Digital output signal.
________________________________________
Firebase Real-Time Database Setup
1.	Create a Firebase project in the Firebase Console.
2.	Set up a real-time database:
o	Navigate to Database > Create Database.
o	Set the database mode to Test Mode (for development purposes).
3.	Copy the Firebase Database URL.
4.	Add the ESP32 device credentials:
o	Navigate to Project Settings > Service Accounts > Generate New Private Key.
o	Download the JSON file and use its details in the project.
________________________________________
Pin Connections
DHT22 Pin	Connection	ESP32 Pin
VCC	3.3V or 5V	3.3V
GND	Ground	GND
DATA	Digital signal output	GPIO4 (D4)
________________________________________
How It Works
1.	Data Acquisition:
o	The DHT22 sensor measures temperature and humidity and outputs the data digitally.
2.	ESP32 Processing:
o	The ESP32 reads data from the sensor and connects to Firebase via Wi-Fi.
3.	Data Storage:
o	Sensor readings are sent to the Firebase real-time database at regular intervals.
4.	Data Visualization:
o	View the data in the Firebase console or use a custom application for real-time monitoring.
Circuit Diagram
1.	Connect the VCC pin of the DHT22 to the 3.3V pin of the ESP32.
2.	Connect the GND pin of the DHT22 to the GND pin of the ESP32.
3.	Connect the DATA pin of the DHT22 to GPIO4 (D4) of the ESP32.
________________________________________
Results
1.	Real-Time Updates:
o	Temperature and humidity data are updated in the Firebase database in real-time.
2.	Database Visualization:
o	View the data under the path /DHT22/Temperature and /DHT22/Humidity in the Firebase console.
________________________________________
Applications
1.	Weather Monitoring:
o	Measure environmental conditions and store data in the cloud.
2.	IoT Systems:
o	Integrate the system into smart home applications.
3.	Data Analysis:
o	Use collected data for long-term trend analysis.
This project provides a detailed example of how to connect a DHT22 sensor to an ESP32 and Firebase for cloud-based environmental monitoring.

