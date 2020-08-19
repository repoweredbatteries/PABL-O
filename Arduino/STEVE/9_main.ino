

void loop(  ) {
int k = 0;
int i = 0;

while (areweago == 1){
while ( Times < Cycles) {
  
 
 while ( State == 0 ) { //discharge
    digitalWrite( relay1pin, LOW );
    digitalWrite( relay2pin, HIGH );
  while (i < (10000 / pollTime)) {//while not enough checks have been run
     i = i + 1;
   Refresh_V_C_OLED();
   PowerD +=  ( V * C );
   writetofile();
   startpause();
  }

  i = 0;
    restr();
    
  if ( ( analogRead( A0 )*0.0048828125 ) < MinV ) { //if discharging and fall below 2v
    State = 1; //change to charging  
    PowerC = 0;  
    
     //change to  nothing and hold a minute to let the battery cool a bit
    longrestr();
    k=0;
    while (k < (10000 / pollTime)) { //small routine to delay by 10 seconds while running the startpause to find interrupts
      k += 1;
      startpause();
     }
    digitalWrite( relay1pin, LOW );
    digitalWrite( relay2pin, LOW );
  }
  else { //return relays to charging state
      digitalWrite( relay1pin, LOW );
      digitalWrite( relay2pin, HIGH );
      Refresh_V_C_OLED();
      }
 }

while ( State == 1 ) { //whilecharging 
    digitalWrite( relay1pin, LOW );//make sure actually charge to avoid accidental overdischarge bug I have not yet pinpointed
    digitalWrite( relay2pin, LOW );
  while (i < (10000 / pollTime)) {//while not enough checks have been run
  i = i + 1;
    Refresh_V_C_OLED(); //gets charging voltage
    PowerC = PowerC + ( V * C ); //calculate Wh, counted in Ws/ number of polltime in a second, conversion to Wh done at display to retain values
    writetofile();
    startpause();
  }
    i = 0;
    restr();

    if ( ( analogRead( A0 )*0.0048828125 ) > MaxV ) { //and full
      State = 0; //change to discharging
      Times += 1;
      PowerD = 0;

      digitalWrite( relay1pin, LOW );
      digitalWrite( relay2pin, HIGH );
      Refresh_V_C_OLED();
      }
    else { //return relays to charging state
      digitalWrite( relay1pin, LOW );
      digitalWrite( relay2pin, LOW );
      Refresh_V_C_OLED(); // gets charging voltage
      }
  }
  startpause();
}//closes while in number of cycles
}//closes the areweago check
//Make sure the device doesn't just discharge itself when it is done or paused
  restr(); //keep doing the cycle number check and control the refresh rate
}//closes loop
