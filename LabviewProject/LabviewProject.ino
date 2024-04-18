#include "PinDefinitions.h"

void setup() {
  pinMode(deurPin, OUTPUT);
  LedRingSetup();
  RFIDsetup();
  Serial.begin(19200);
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readString();
    if (input.equals("deurOpen")) {
      digitalWrite(deurPin, HIGH);
    } else if (input.equals("deurToe")) {
      digitalWrite(deurPin, LOW);
    } else if (input.equals("ledAllOff")) {
      LedAllOff();
    } else if (input.startsWith("led:")) {
      LedRing(input.substring(4, 6).toInt(), input.substring(6, 9).toInt());
    } else if (input.startsWith("ledOff:")) {
      LedOff(input.substring(7, 9).toInt());
    }
  }
  printKeypadIfPosible();
  runRFID();
}
