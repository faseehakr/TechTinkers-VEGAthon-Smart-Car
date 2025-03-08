#include <DFRobot_DHT11.h>


#define BT_SERIAL Serial1 
#define DHT11_PIN 8

DFRobot_DHT11 dht11; 

void setup() {
  BT_SERIAL.begin(9600); 
  Serial.begin(115200); 
  dht11.begin(DHT11_PIN); 
}

void loop() {
  
  delay(2000);

  float temperature = dht11.readTemperature(); 
  float humidity = dht11.readHumidity();

  if (temperature == DHT11_ERROR || humidity == DHT11_ERROR) {
    BT_SERIAL.println("Failed to read from DHT11 sensor!");
    return;
  }

  BT_SERIAL.print("Temperature: ");
  BT_SERIAL.print(temperature);
  BT_SERIAL.print(" °C, Humidity: ");
  BT_SERIAL.print(humidity);
  BT_SERIAL.println(" %");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}
