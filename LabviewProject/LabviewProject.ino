#include <FastLED.h>
#define NUM_LEDS 24
#define DATA_PIN 5
CRGB leds[NUM_LEDS];

void setup() { 

     FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS); 
}

void loop() { 
  for (int i=0;i<=NUM_LEDS;i++){
    leds[i] = CRGB::Green;
  }
  
  FastLED.show();
  delay(500);
    for (int i=0;i<=NUM_LEDS;i++){
  leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(500);
}
