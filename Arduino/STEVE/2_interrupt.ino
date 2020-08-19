void testISR () {
rturn=rotary.rotate();

if (buttonmode == 0){
  if (rturn == 1) {
    if (Cycles < 20) {
      Cycles += 1;
    }
    else if (Cycles < 100) {
      Cycles += 10;
    }
    else if (Cycles < 250) {
      Cycles += 25;
    }
    else if (Cycles < 500) {
      Cycles += 50;
    }
    else {
      Cycles += 100;
    }
  }

  else if (rturn == 2) {
    if (Cycles < 20) {
      Cycles -= 1;
    }
    else if (Cycles < 100) {
      Cycles -= 10;
    }
    else if (Cycles < 250) {
      Cycles -= 25;
    }
    else if (Cycles < 500) {
      Cycles -= 50;
    }
    else {
      Cycles -= 100;
    }
  }

  if (Cycles == 0 ) { 
    Cycles = 2;
  }
}

else if (buttonmode == 1) {
  if (rturn == 1) {
    vadj += 0.01;
  }
  else if (rturn == 2) {
    vadj -= 0.01;
  }  
}

else if (buttonmode == 2) {
  if (rturn == 1) {
    iadj += 0.01;
  }
  else if (rturn == 2) {
    iadj -= 0.01;
  }
}

else if (buttonmode == 3) {
  if (rturn == 1) {
    pollTime = pollTime * 10;
  }
  else if (rturn == 2) {
    pollTime = pollTime / 10;
  }
}

};
