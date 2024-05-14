void printKeypadIfPosible() {
  char key = keypad.getKey();
  if (key) {
    Serial.print("key");
    Serial.println(key);
  }
}