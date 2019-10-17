#include <EEPROM.h>

// include the library code:
#include <LiquidCrystal.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define sensorPin A0
#define LEDPin 9

int sensorValue = 0; //Sensor value to be read from analog pin and stored in EEPROM.

int memoAddressMax = 0;   //Location we want the data to be put.
int memoAddressMin = memoAddressMax + sizeof(int);   //Location we want the data to be put.
int memoMax = 0;
int memoMin = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(LEDPin, OUTPUT);
  
  memoMax = memoMin = analogRead(sensorPin);
  EEPROM.put(memoAddressMax, memoMax);
  EEPROM.put(memoAddressMin, memoMin);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.display();
  lcd.setCursor(0, 0); //Setting the first line of the LCD
  lcd.print("MaxValue: "); //Words to display
  lcd.print(memoMax);
  lcd.setCursor(0, 1); //Setting the first line of the LCD
  lcd.print("MinValue: "); //Words to display
  lcd.print(memoMin);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  
  //Updating the maximum and minimum sensor value readings and save it to the memory 
  if (sensorValue > memoMax){
    memoMax = sensorValue;
    EEPROM.put(memoAddressMax, memoMax);
    lcd.setCursor(10, 0);
    lcd.print(memoMax);
    lcd.print("  ");
    }
  else if (sensorValue < memoMin){
    memoMin = sensorValue;
    EEPROM.put(memoAddressMin, memoMin);
    lcd.setCursor(10, 1);
    lcd.print(memoMin);
    lcd.print("  ");
    }

  //Mapping value to control the brightness of LED
  sensorValue = map(sensorValue, memoMin, memoMax, 0, 255);
  analogWrite(LEDPin, sensorValue);
  
  delay(100);
}
