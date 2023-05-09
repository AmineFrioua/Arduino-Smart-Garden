#include <DFRobot_DHT11.h>

#include <DHT.h>
#include <DHT_U.h>

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

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(smokeA0, INPUT);
  pinMode(soilA1, INPUT);
  pinMode(rainA2, INPUT);
  Serial.begin(9600);
      dht.begin();

}
 
void loop() {
   Serial.println(); 
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


  delay(2000);

}