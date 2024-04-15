#include <FastLED.h>
#include <Keypad.h>
#define NUM_LEDS 24
#define DATA_PIN 5
CRGB leds[NUM_LEDS];

const byte ROWS = 4;  //four rows
const byte COLS = 4;  //three columns
char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};
byte rowPins[ROWS] = { 9, 8, 7, 6 };      //connect to the row pinouts of the keypad
byte colPins[COLS] = { 13, 12, 11, 10 };  //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


void setup() {
  LedRingSetup();
  Serial.begin(9600);
}

void loop() {
  LedRingCycle();
  printKeypadIfPosible();
}
