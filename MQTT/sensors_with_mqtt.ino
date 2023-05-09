#include <ArduinoMqttClient.h>
#include <WiFiNINA.h>
#include <DHT.h>
#include <DHT_U.h>
#include "arduino_secrets.h"

#define DHTPIN 2
#define DHTTYPE DHT11 
 int smokeA0 = A0;
 int soilA1 = A1;
 int rainA2 = A2;
const int rainMin = 0;     // sensor minimum
const int rainMax = 1024;  // sensor maximum
DHT dht(DHTPIN, DHTTYPE);
// Your threshold value
int sensorThres = 100;

char ssid[] = SECRET_SSID;     // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);
const long interval = 8000;
unsigned long previousMillis = 0;
int count = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(smokeA0, INPUT);
  pinMode(soilA1, INPUT);
  pinMode(rainA2, INPUT);
  Serial.begin(9600);
    while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // attempt to connect to Wifi network:
  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(ssid);
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    // failed, retry
    Serial.print(".");
    delay(5000);
  }

  Serial.println("You're connected to the network");
  Serial.println();

  Serial.print("Attempting to connect to the MQTT broker: ");
  Serial.println(BROKER);

  if (!mqttClient.connect(BROKER, PORT)) {
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());

    while (1);
  }

  Serial.println("You're connected to the MQTT broker!");
  Serial.println();
  }
  dht.begin();
}
 
void loop() {
  int smoke_level = analogRead(smokeA0);
  int soil_moisture = analogRead(soilA1); 
  int rain_level = analogRead(rainA2); 

  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();

  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.println(" *C ");

  Serial.print("Humidity = ");
  Serial.print(h);
  Serial.println(" %\t");

  Serial.print("Smoke detector: ");
  Serial.println(smoke_level);

  Serial.print("Soil Moisture: ");
  Serial.println(soil_moisture);

  Serial.print("rain detector: ");
  Serial.println(rain_level);

  Serial.print("Sending message to topic: ");
  Serial.println(TEMP_TOPIC);
  Serial.println(t);

  Serial.print("Sending message to topic: ");
  Serial.println(HUM_TOPIC);
  Serial.println(h);

    Serial.print("Sending message to topic: ");
    Serial.println(SOIL_TOPIC);
    Serial.println(soil_moisture);

  Serial.print("Sending message to topic: ");
  Serial.println(GAZ_TOPIC);
  Serial.println(smoke_level);

  Serial.print("Sending message to topic: ");
  Serial.println(RAIN_TOPIC);
  Serial.println(rain_level);


  delay(2000);

}