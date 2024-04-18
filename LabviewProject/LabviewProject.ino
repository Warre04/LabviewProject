#include <FastLED.h>
#include <Keypad.h>
#include <SPI.h>
#include <MFRC522.h>

#define NUM_LEDS 24
#define DATA_PIN 8
CRGB leds[NUM_LEDS];

const byte ROWS = 4;  //four rows
const byte COLS = 3;  //three columns
char keys[ROWS][COLS] = {
  { '1', '2', '3'},
  { '4', '5', '6' },
  { '7', '8', '9' },
  { '*', '0', '#' }
};
byte rowPins[ROWS] = { A3, A4, A5, 7 };      //connect to the row pinouts of the keypad
byte colPins[COLS] = { A0, A1, A2 };  //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

#define SS_PIN 10  // Definieer de Slave Select Pin
#define RST_PIN 9  // Definieer de Reset Pin

MFRC522 mfrc522(SS_PIN, RST_PIN); // Creëer MFRC522 instantie

void setup() {
  LedRingSetup();
  RFIDsetup();
  Serial.begin(19200);
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readString();
    if(input="led"){
      LedRing(2,42);
    }
  }
  printKeypadIfPosible();
  runRFID();
}
