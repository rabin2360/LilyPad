/*
SparkFun Inventor's Kit
Example sketch 01

BLINKING A LED

  Turn an LED on for one second, off for one second,
  and repeat forever.

Hardware connections:

  Most Arduinos already have an LED and resistor connected to
  pin 13, so you may not need any additional circuitry.

  But if you'd like to connect a second LED to pin 13, or use
  a different pin, follow these steps:

    Connect the positive side of your LED (longer leg) to Arduino
    digital pin 13 (or another digital pin, don't forget to change
    the code to match).
  
    Connect the negative side of your LED (shorter leg) to a 
    330 Ohm resistor (orange-orange-brown). Connect the other side
    of the resistor to ground.

    pin 13 _____ + LED - _____ 330 Ohm _____ GND
	
    (We always use resistors between the Arduino and and LEDs
    to keep the LEDs from burning out due to too much current.)

This sketch was written by SparkFun Electronics,
with lots of help from the Arduino community.
This code is completely free for any use.
Visit http://learn.sparkfun.com/products/2 for SIK information.
Visit http://www.arduino.cc to learn about the Arduino.

Version 2.0 6/2012 MDG
*/


#include <Adafruit_NeoPixel.h>


Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, 8, NEO_GRB + NEO_KHZ800);
int leftSwitch = 0;

void setup()
{
  Serial.begin(9600);

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  pinMode(0, INPUT);
  digitalWrite(0, HIGH);
  pinMode(10, OUTPUT);

}


void loop()
{
  if (digitalRead(leftSwitch) == LOW)
  {
    Serial.print("inside low");
  //colorWipe(strip.Color(0, 255, 0), 500); // Green
  //colorWipe(strip.Color(0, 0, 255), 500); // Blue

    for(int i = 0; i<3; i++)
    {
      digitalWrite(10, HIGH);   // Turn on the LED  
      delay(500);
      digitalWrite(10, LOW);
      delay(500);
    }
  }

  /*if(digitalRead(leftSwitch) == HIGH)
  {
    Serial.print("inside high");
    //digitalWrite(10, LOW);    // Turn off the LED
    //colorWipe(strip.Color(255, 0, 0), 500); // Red
  
  }*/
  
  /*digitalWrite(10, HIGH);    // Turn on the LED
  
  delay(500);              // Wait for one second
  
  digitalWrite(10, LOW);    // Turn off the LED
  
  delay(500);              // Wait for one second
*/

}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}
