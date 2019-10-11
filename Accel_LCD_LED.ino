// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Basic demo for accelerometer readings from Adafruit LIS3DH
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

// I2C
Adafruit_LIS3DH lis = Adafruit_LIS3DH();

//RBG LED pins, need to be PWM pins
#define RLED 10
#define GLED 9
#define BLED 6

void setup(void) {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.display();

  #ifndef ESP8266
    while (!Serial);     // will pause Zero, Leonardo, etc until serial console opens
  #endif

  Serial.begin(9600);
  lcd.setCursor(0, 0); //Setting the first line of the LCD
  lcd.print("LIS3DH test!"); //Words to display  


  if (! lis.begin(0x18)) {   // change this to 0x19 for alternative i2c address
    while (1);
  }
  
  lis.setRange(LIS3DH_RANGE_4_G);   // 2, 4, 8 or 16 G!

  //Setting LED pins
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);  
}

void loop() {
  
  lis.read();      // get X Y and Z data at once
  /* Or....get a new sensor event, normalized */ 
  sensors_event_t event; 
  lis.getEvent(&event);
  
  /* Display the results (acceleration is measured in m/s^2) */
  lcd.clear();
  lcd.print("X/Y/Z (m/s^2)"); //Words to display  
  lcd.setCursor(0, 1);
  lcd.print(event.acceleration.x);
  lcd.print("/");
  lcd.print(event.acceleration.y);
  lcd.print("/");
  lcd.print(event.acceleration.z); 
  setColor(abs(event.acceleration.x*100), abs(event.acceleration.y*100), abs(event.acceleration.z*10));  //set color
  delay(200); 
}

void setColor(int red, int green, int blue){
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(RLED, red);
  analogWrite(GLED, green);
  analogWrite(BLED, blue);  
}
