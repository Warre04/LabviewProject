void RFIDsetup() {
  SPI.begin();         // Start SPI-bus
  mfrc522.PCD_Init();  // Initieer MFRC522
}
void runRFID() {
  // Kijk of er een nieuwe kaart aanwezig is
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    // Print de NUID van de kaart
    Serial.print("RFID");
    for (byte i = 0; i < mfrc522.uid.size; ++i) {
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
    }
    Serial.println();
    mfrc522.PICC_HaltA();  // Halt PICC
  }
}
