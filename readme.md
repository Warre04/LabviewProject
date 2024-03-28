# RFID slot/deur

## Inputs	
  - RFID lezer
  - keypad
  - Worden gelogd in CSV met huidige timestamp
  - Keypad codes kunnen aangemaakt worden en gekoppeld aan een naam (input csv?)

## Outputs
  - OLED schermpje
  - RGB led ring
  - Servo/magneet?

State machine gebruiken: `{waiting, authenticating, logging, openingDoor, closingDoor}`
		
Als er nog iets bij moet: weersensor & grafiek loggen (DHT-11?)
