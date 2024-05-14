#include "PinDefinitions.h"

void setup() {
  pinMode(deurPin, OUTPUT);
  LedRingSetup();
  RFIDsetup();
  Serial.begin(19200);
  Serial.setTimeout(5);
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
    } else if (input.startsWith("noAccess")) {
      allStatusOff();
      NoAccessFlashes = 7;
    } else if (input.startsWith("idle")) {
      NoAccessFlashes = 0;
      ledRingAccess = false;
      ledRingAddAccess = false;
      ledRingIdle = true;
    } else if (input.startsWith("access")) {
      allStatusOff();
      ledRingAccess = true;
    } else if (input.startsWith("addAccess")) {
      allStatusOff();
      ledRingAddAccess = true;
    }
  }
  printKeypadIfPosible();
  runRFID();

  addAccesKey();
  access();
  noAccess();
  idle();
}
