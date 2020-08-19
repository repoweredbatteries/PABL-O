void buttonpickup (){
if (areweago == 0) {
  oled.print ("Paused");
}
else {
  if (buttonmode == 1){
    oled.print ("V adj");
  }
  else if (buttonmode == 2){
    oled.print ("I adj");
  }
  else if (buttonmode == 3){
    oled.print ("poll t adj");
    oled.print (pollTime);
  }
}
  rpush = rotary.push();
  
if (rpush == 1 and areweago == 0){
    areweago = 1;
  }
else if (rpush == 1 and areweago == 1){
    if (buttonmode == 0) {
      buttonmode = 1;
    }
    else if (buttonmode == 1) {
      buttonmode = 2;
    }
    else if (buttonmode == 2) {
      buttonmode = 3;
    }
    else if (buttonmode == 3) {
      buttonmode = 0;
    }
}  
};
