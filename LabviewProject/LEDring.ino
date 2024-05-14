void LedRingSetup() {
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  LedAllOff();
}

void LedRing(int ledPin, int color) {
  leds[ledPin].setHue(color);
  FastLED.show();
}
void LedRingAllOn(int color) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].setHue(color);
  }
  FastLED.show();
}

void LedOff(int ledPin) {
  leds[ledPin] = CRGB::Black;
  FastLED.show();
}
void LedAllOff() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}

void noAccess() {
  static bool ledOn = false;
  static unsigned long prevMillis = 0;
  unsigned long currMillis = millis();
  if (currMillis - prevMillis >= 200 && NoAccessFlashes > 0) {
    prevMillis = millis();
    if (ledOn == false) {
      LedRingAllOn(0);
      ledOn = true;
    } else {
      LedAllOff();
      ledOn = false;
      NoAccessFlashes--;
    }
  }
}

void idle() {
  static unsigned long prevMillis = 0;
  static int LED = 0;
  static int Color = 0;
  unsigned long currMillis = millis();
  if (currMillis - prevMillis >= 35 && ledRingIdle) {
    prevMillis=millis();
    LedRing(LED, Color);
    LED++;
    if (LED == 24) {
      LED = 0;
      Color += 5;
    }
    if (Color > 255) {
      Color = 0;
    }
  }
}

void access() {
  static unsigned long prevMillis = 0;
  static int LED = 0;
  static bool AllLedOn = false;
  unsigned long currMillis = millis();
  if (currMillis - prevMillis >= 30 && ledRingAccess) {
    prevMillis=millis();
    if (AllLedOn == false) {
      LedRing(LED, 96);
      LED++;
      if (LED == 24) {
        LED = 0;
        AllLedOn = true;
      }
    } else {
      LedOff(LED);
      LED++;
      if (LED == 24) {
        LED = 0;
        AllLedOn = false;
        ledRingAccess = false;
      }
    }
  }
}

void addAccesKey() {
  static unsigned long prevMillis = 0;
  static int LED = 0;
  static bool ledOn = false;
  unsigned long currMillis = millis();
  if (currMillis - prevMillis >= 50 && ledRingAddAccess) {
    prevMillis=millis();
    if (ledOn == false) {
      LedRing(LED, 192);
      LedRing(23 - LED, 192);
      LED++;
      if (LED == 12) {
        LED = 0;
        ledOn=true;
      }
    }else{
      LedOff(LED);
      LedOff(23 - LED);
      LED++;
      if (LED == 12) {
        LED = 0;
        ledOn=false;
        ledRingAddAccess = false;
      }
    }
  }
}

void allStatusOff() {
  NoAccessFlashes = 0;
  ledRingIdle = false;
  ledRingAccess = false;
  ledRingAddAccess = false;
  LedAllOff();
  delay(10);
}