
void buttonpickup (){
if (areweago == 0) {
  display.clearDisplay();
  display.setCursor(0,0);
  display.print(F("Paused "));
  display.display();
}

  rpush = rotary.push();
  
if (rpush == 1 and areweago == 0){
    areweago = 1;
  }
};
