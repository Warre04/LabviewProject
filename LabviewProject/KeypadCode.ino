void printKeypadIfPosible(){
    char key = keypad.getKey();
  
  if (key){
    Serial.println(key);
  }
}