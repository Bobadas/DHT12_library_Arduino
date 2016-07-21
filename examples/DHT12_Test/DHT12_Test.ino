//Test library for DHT12 sensors.
//Write by Bobadas.

#include <DHT12.h>
#include <Wire.h>     //The DHT12 uses I2C comunication.
DHT12 dht12;          //Preset scale CELSIUS and ID 0x5c.
/*
For configuration library:
DHT12 dht12("Scale temperature","ID device for I2C");
On "Scale temperature" you can select the preset scale:
CELSIUS, FAHRENHEIT or KELVIN.
And on "ID device", you can put ID sensor, on DHT12
normally is 0x5c.
Examples:
  DHT12 dht12;
The preset scale is CELSIUS and ID is 0x5c.
  DHT12 dht12(KELVIN);
the preset scale is KELVIN and ID is 0x5c.
  DHT12 dht12(FAHRENHEIT,0x53);
The preset scale is FAHRENHEIT and ID is 0x53.
*/

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Prueba de libreria DHT12:");
}

void loop() {
  Serial.print("Temperatura: ");
  Serial.print(dht12.readTemperature());
//Read temperature with preset scale.
  Serial.print("*C  Humedad: ");
  Serial.print(dht12.readHumidity());
//Read humidity.
  Serial.println("%RH");
  Serial.print("Temperatura: ");
  Serial.print(dht12.readTemperature(FAHRENHEIT));
//Read temperature as forced fahrenheit.
  Serial.println("*F");
  Serial.print("Temperatura: ");
  Serial.print(dht12.readTemperature(KELVIN));
//Read termperature as forced kelvin.
  Serial.println("*K");

  delay(5000);
}

/*
if it delivers the values 0.01, 0.02 or 0.03, you are
giving us the error that has had in reading:
0.01: DHT12 is not connected or the ID does not exist.
0.02: There have been a problem with communication.
0.03: Checksum error (bad connections, check the wires). 
*/
