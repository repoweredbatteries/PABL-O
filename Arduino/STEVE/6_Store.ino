
void storageroutine(float pctdschrg ){
  Serial.println("storageroutine launched");
    
 while ( State == 0 ) { //discharge
digitalWrite( chrgpin, LOW );
analogWrite( dschrgpin, pwm );
Refresh_V_C_OLED();
 PowerTemp2 = PowerTemp2 + ( V * C ); //calculate Wh, counted in Ws/ number of polltime in a second, conversion to Wh done at display to retain values
 AhTemp2   = AhTemp2 +  C;
  restr();   
  
  //writetofile;
    
  if ((PowerTemp * pctdschrg) <  PowerTemp2) { //if discharging and fall below minV
    State = 2; //change to charging  
    
     //change to  nothing and hold a minute to let the battery cool a bit
    longrestr();
     }
     
digitalWrite(chrgpin, LOW ); 
analogWrite(dschrgpin, pwm );
shortpause();

Refresh_V_C_OLED();

startpause();
}
}
