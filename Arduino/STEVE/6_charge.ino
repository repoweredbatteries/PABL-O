

void chargeroutine ( ) { 
  int i;
while ( State == 1 ) { //whilecharging 
    digitalWrite( chrgpin, HIGH );
    digitalWrite( dschrgpin, LOW );
  while (i < (10000 / pollTime)) {//while not enough checks have been run
  i = i + 1;
  shortpause();
    Refresh_V_C_OLED(); //gets charging voltage
    startpause();
  }
    i = 0;
    restr();
    
    //writetofile;
    
    if ( ( analogRead( A0 )*0.0048875855327468 ) > MaxV ) { //and full
      State = 0; //change to discharging      
      Refresh_V_C_OLED();
      }
    else { //return relays to charging state
      digitalWrite( chrgpin, HIGH );
      digitalWrite( dschrgpin, LOW );
      Refresh_V_C_OLED(); // gets charging voltage
      }
  }
}
