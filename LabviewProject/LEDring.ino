void LedRingSetup(){
      FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS); 
}

void LedRingCycle() {
  for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB::Green;
    FastLED.show();
    delay(5);
    leds[i] = CRGB::Black;
    FastLED.show();
  }
}