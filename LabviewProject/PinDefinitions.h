#ifndef PIN_DEFINITIONS_H
#define PIN_DEFINITIONS_H
//included Librarys
#include <FastLED.h>
#include <Keypad.h>
#include <SPI.h>
#include <MFRC522.h>

//Door Lock System
#define deurPin 3 //door pin number

//Circular LED array
#define NUM_LEDS 24 //amount of LEDs in the circular LED array
#define DATA_PIN 8 //Datapin from the circular LED array
CRGB leds[NUM_LEDS]; //the array of LEDs

//KeyPad
#define ROWS 4  //Row amount
#define COLS 3  //Collums amount
char keys[ROWS][COLS] = { //KeyPad layout
  { '1', '2', '3'},
  { '4', '5', '6' },
  { '7', '8', '9' },
  { '*', '0', '#' }
};
byte rowPins[ROWS] = { A3, A4, A5, 7 };  //Pins used for the rows of the Keypad    
byte colPins[COLS] = { A0, A1, A2 };  // pins used for the cols of the keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS); // create Keypad


#define SS_PIN 10  // Definieer de Slave Select Pin
#define RST_PIN 9  // Definieer de Reset Pin

MFRC522 mfrc522(SS_PIN, RST_PIN); 

//Global Var for LEDRING modes
int NoAccessFlashes=0;
bool ledRingIdle=false;
bool ledRingAccess=false;
bool ledRingAddAccess=false;



#endif