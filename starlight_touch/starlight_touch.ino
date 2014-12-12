#include <Adafruit_NeoPixel.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define PIN A0
const int PIN_NUM = 51;   //all LED's numbers
const int baloon_num = 5;

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIN_NUM, PIN, NEO_GRB + NEO_KHZ800);


// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
 // cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);  
  Serial.begin(9600);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
//  long start = millis();
//  long total1 = cs_4_2.capacitiveSensor(30);
  
    //set Light to off
    strip.setPixelColor(PIN_NUM, strip.Color(0,0,0));
    
      int  _max = PIN_NUM - baloon_num ;
       for(int j = 0 ; j < _max ; j++){
        Serial.println(j);
        colorWipe(strip.Color(255,0,0), 5 , j); //Red
        }    

    strip.show();
    delay(500);

    baloonColor(500);
    
    delay(500);
    resetColor();
 }

void resetColor(){

  for(int i = 0 ; i <= PIN_NUM ; i++){
    strip.setPixelColor(i,strip.Color(0,0,0));
  }
  strip.show();

  delay(100);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait , uint8_t num) {

  for(int i = 0 ; i <= PIN_NUM ; i++){
    strip.setPixelColor(i,strip.Color(0,0,0));
  }

  strip.setPixelColor(num,c);
  strip.show();
  delay(30);
}


void baloonColor(uint8_t wait) {
    strip.setPixelColor(PIN_NUM -  baloon_num - 1,strip.Color(0,0,0) );
    srand(1);
    for(int i = 0 ; i < 5 ; i++){
      for(int j = 0 ; j < baloon_num ; j++){
        int baloon_light = PIN_NUM -  j - 1;
        strip.setPixelColor(baloon_light,strip.Color(rand() % 256,rand() % 256,rand() % 256));
        delay(wait);
        strip.show();
      }
    }

}
