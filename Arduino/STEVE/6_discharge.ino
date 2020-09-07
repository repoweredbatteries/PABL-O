
void dischargeroutine( ){
  Serial.println("dischargerouting launched");
    
 while ( State == 0 ) { //discharge
digitalWrite( chrgpin, LOW ); //discharge 1
analogWrite( dschrgpin, pwm ); //discharge 1
Refresh_V_C_OLED();
 PowerTemp = PowerTemp + ( V * C ); //calculate Wh, counted in Ws/ number of polltime in a second, conversion to Wh done at display to retain values
 AhTemp   = AhTemp +  C;
  restr();   
  
  //writetofile;
    
  if ( ( analogRead( A0 )*0.0048875855327468 ) < MinV ) { //if discharging and fall below minV
    State = 1; //change to charging  
    
     //change to  nothing and hold a minute to let the battery cool a bit
    longrestr();
     }
     
digitalWrite( chrgpin, LOW ); //discharge 1
analogWrite( dschrgpin, pwm ); //discharge 1
shortpause();

Refresh_V_C_OLED();
PctCapacity = (PowerTemp/ 3600  * ( float(pollTime) / 1000 ))/7.26*100;
PctCapacityAh = (PowerTemp/ 3600  * ( float(pollTime) / 1000 ))/2.2*100;

startpause();
}
}
