#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 1

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  strip.begin();
  strip.setBrightness(10);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Some example procedures showing how to display to the pixels:
  policeFlash(strip.Color(0, 255, 0), 50); // Red
  bluerainbow(50);
  circleMotion(50);

  greenPoliceFlash(50);
  greenrainbow(50);
  greencircleMotion();
  //rainbowCycle(50);
}

// Red and Blue Lights with white flash
void policeFlash(uint32_t c, uint8_t wait) {
  for (uint16_t j=0; j<10; j++) {
    delay(wait);
    for(uint16_t i=0;i<strip.numPixels(); i++) {
      if (i%4 == 0) {
        strip.setPixelColor(i, strip.Color(0, 0, 255));
      }
      else if (i%4 == 3) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));
      }
      else if (j % 2 == 0) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));
      }
    }
    strip.show();
    delay(300);
    strip.clear();
  }
}

void greenPoliceFlash(uint8_t wait) {
  for (uint16_t j=0; j<10; j++) {
    delay(wait);
    for(uint16_t i=0;i<strip.numPixels(); i++) {
      if (i%4 == 0) {
        strip.setPixelColor(i, strip.Color(0, 255, 0));
      }
      
      else if (i%4 == 3) {
        strip.setPixelColor(i, strip.Color(0, 0, 255));
      }
      
      else if (j % 2 == 0) {
        strip.setPixelColor(i, strip.Color(255, 255, 255));
      }
    }
    strip.show();
    delay(300);
    strip.clear();
  }
}

//blue red white circle
void bluerainbow(uint8_t wait) {
  uint16_t i, j;

  for (uint16_t i=0; i<20; i++) {
    delay(100);
    for (uint16_t j=0; j<strip.numPixels(); j++) {
      if (i % 3 == 0) {
        if (j % 4 == 0) {
        strip.setPixelColor(j, strip.Color(0, 0, 255));
        }
      }
      
      else if (i % 3 == 1) {
        if (j % 4 == 3) {
          strip.setPixelColor(j, strip.Color(0, 255, 0));
        }
      }
      else if (i % 3 == 2) {
        if (j% 4 == 2) {
          strip.setPixelColor(j, strip.Color(255, 255, 0));
        }
      }
    }
    strip.show();
    delay(100);
    strip.clear();
  }
}

void circleMotion(uint8_t wait) {
  uint16_t i, j;

  for (uint16_t i=0; i<20; i++) {
    delay(100);
    for (uint16_t j=0; j<strip.numPixels(); j++) {
      if (i % 3 == 0) {
        if (j % 4 == 0) {
        strip.setPixelColor(j, strip.Color(0, 255, 0));
        }
      }
      
      else if (i % 3 == 1) {
        if (j % 4 == 3) {
          strip.setPixelColor(j, strip.Color(0, 0, 255));
        }
      }
      else if (i % 3 == 2) {
        if (j% 4 == 2) {
          strip.setPixelColor(j, strip.Color(255, 255, 255));
        }
      }
    }
    strip.show();
    delay(100);
    strip.clear();
  }
}

void greenrainbow(uint8_t wait) {
  
  for (uint16_t j = 0; j < 3; j++) {
      for (uint16_t i = 0; i < strip.numPixels(); i++) {
          if (i%4 == 3) {
            strip.setPixelColor(i, strip.Color(0, 255, 0));
            strip.show();
          }
          else if (i%4 == 0) {
            strip.setPixelColor(i, strip.Color(0, 0, 255));
            strip.show();
          }
          delay(50);
      }
      strip.clear();
    }
}

void greencircleMotion() {
  for (uint16_t j = 0; j < 3; j++) {
      for (uint16_t i = 0; i < strip.numPixels(); i++) {
          if (i%4 == 2) {
            strip.setPixelColor(i, strip.Color(255, 0, 0));
            strip.show();
          }
          else if (i%4 == 0) {
            strip.setPixelColor(i, strip.Color(0, 255, 0));
            strip.show();
          }
          delay(50);
      }
      strip.clear();
    }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
