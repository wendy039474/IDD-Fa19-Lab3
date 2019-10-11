# Data Logger (and using cool sensors!)

*A lab report by Wen-Ying Lee(Rei).*

## Part A.  Writing to the Serial Monitor
 
**a. Based on the readings from the serial monitor, what is the range of the analog values being read?**
 
0-1023.
 
**b. How many bits of resolution does the analog to digital converter (ADC) on the Arduino have?**

Arduino has 10-bit ADC onboard, as haveing the ability to detect the range 1024 = 2^10 discrete analog levels.

## Part B. RGB LED

**How might you use this with only the parts in your kit? Show us your solution.**

Since my kit does not come with resistors, I can choose to use potentiometer, photo cell, or force-sensitive resistor to connect the three legs of the RBG LED.

<img src="/RGB LED Connection.jpeg">

## Part C. Voltage Varying Sensors 
 
### 1. FSR, Flex Sensor, Photo cell, Softpot

**a. What voltage values do you see from your force sensor?**

FSR will have higher resistance when being pressed and lower resistance when not being pressed.

With the circuit, we can get the value of 1023 when being pressed, which mean 5V, and get the value of 0 when not being pressed, which mean 0V.

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)**

Semi-linear in certain range of force and have really high error rate. Below is a figure from adafruit that can easier to tell the curve of the function.

<img src="/resistanceforce.jpg">

**c. Can you change the LED fading code values so that you get the full range of output voltages from the LED when using your FSR?**

Mapping the reading range we can get from FSR (0-1023) to the range of controlling LED (0-255).

**d. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**

For FSR, I used 100K Ω resistor to roughly get the range of 0~1021.

For Flex Sensor, with 100K Ω resistor, it can have the range around 300~650.

For Photo Cell, when using 1K Ω resistor, I can roughly get the range of 200~750.

I don't have a softpot in my kit :(((

**e. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)**

All of then should theoretically have linear relationship but all come with error rates.

### 2. Accelerometer
 
**a. Include your accelerometer read-out code in your write-up.**

[Accelerometer](//github.com/wendy039474/IDD-Fa19-Lab3/blob/master/Accel_LCD_LED.ino)

## Optional. Graphic Display

**Take a picture of your screen working insert it here!**

## Part D. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**

**b. Why is the code here all in the setup() functions and not in the loop() functions?**

**c. How many byte-sized data samples can you store on the Atmega328?**

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**

**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**

### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**

### 3. Create your data logger!
 
**a. Record and upload a short demo video of your logger in action.**
