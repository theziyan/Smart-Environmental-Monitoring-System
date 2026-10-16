#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
Serial.begin(9600);
dht.begin();

Serial.println("================================");
Serial.println(" SMART ENVIRONMENTAL MONITOR ");
Serial.println("================================");
Serial.println("Starting sensor...");
delay(2000);
}

void loop() {
float humidity = dht.readHumidity();
float temperature = dht.readTemperature();

if (isnan(humidity) || isnan(temperature)) {
Serial.println("Error: Sensor reading failed!");
delay(2000);
return;
}

Serial.print("Temperature: ");
Serial.print(temperature);
Serial.println(" °C");

Serial.print("Humidity: ");
Serial.print(humidity);
Serial.println(" %");

if (temperature >= 35) {
Serial.println("ALERT: High temperature!");
}

if (humidity >= 70) {
Serial.println("ALERT: High humidity!");
}

Serial.println("--------------------------------");
delay(2000);
}
