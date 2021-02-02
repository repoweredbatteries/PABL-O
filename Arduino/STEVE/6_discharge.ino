
void dischargeroutine( ){
  Serial.println("dischargerouting launched");
    
 while ( State == 0 ) { //discharge
digitalWrite( chrgpin, LOW );
analogWrite( dschrgpin, pwm );
Refresh_V_C_OLED();
 PowerTemp = PowerTemp + ( V * C ); //calculate Wh, counted in Ws/ number of polltime in a second, conversion to Wh done at display to retain values
 AhTemp   = AhTemp +  C;
  restr();   
  
  //writetofile;
    
  if ( ( analogRead( A0 )*0.0048875855327468 ) < MinV ) { //if discharging and fall below minV
    restr();
    if ( ( analogRead( A0 )*0.0048875855327468 ) < MinV ) { //if discharging and fall below minV
      State = 1; //change to charging  
      longrestr();
    }
    }
     
digitalWrite(chrgpin, LOW ); 
analogWrite(dschrgpin, pwm );
shortpause();

Refresh_V_C_OLED();

startpause();
}
}
