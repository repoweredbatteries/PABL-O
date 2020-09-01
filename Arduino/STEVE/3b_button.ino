void buttonpickup (){
if (areweago == 0) {
  oled.print ("Paused");
}

  rpush = rotary.push();
  
if (rpush == 1 and areweago == 0){
    areweago = 1;
  }
};
