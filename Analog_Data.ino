#include <EEPROM.h>

#define sensorPin A0

int sensorValue = 0;     //Sensor value to be read from analog pin and stored in EEPROM.
int sensorAddress = 0;   //Location we want the data to be put.

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  //Uncommon the next line if wanting to regulate the data size to be one byte!
  //sensorValue = map(sensorValue, 0,1023,0,255);
  EEPROM.put(sensorAddress, sensorValue);
  Serial.print(sensorValue);
}
