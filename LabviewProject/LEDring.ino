void LedRingSetup(){
      FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS); 
      LedAllOff();
}

void LedRing(int ledPin, int color) {
    leds[ledPin].setHue(color);
    FastLED.show();
}
void LedRingAllOn(int color){
  for (int i = 0; i<NUM_LEDS;i++){
    leds[i].setHue(color);
  }
  FastLED.show();

}

void LedOff(int ledPin){
      leds[ledPin] = CRGB::Black;
      FastLED.show();
}
void LedAllOff(){
  for (int i = 0; i<NUM_LEDS;i++){
    leds[i] = CRGB::Black;
  }
  FastLED.show();

}