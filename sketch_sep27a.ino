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
