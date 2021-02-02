
void Refresh_V_C_OLED() { //C refreshed separately to get accurate charge current

  pwmsrc = analogRead(A6);
  pwm = map(pwmsrc,0,1023,0,255);
  
  /*V = ( adc.read( A0 )*0.0048875855327468 );
  V = abs(V) + vadj;
  C = (adc.read( A1 ) *0.0048875855327468) - 24.9;
  C = abs(C) + iadj; */
  V = ( analogRead( A0 )*0.0048875855327468 );
  V = abs(V) + vadj;
  // can't read the current during PWM as it always picks up 0 so I have to read the full current and multiply by PWM as that is essentially how the square wave function works anyways
  if (State == 0){
  analogWrite( dschrgpin, 255 );
  C = (((analogRead( A1 )-512) ) *0.048875855327468); 
  //according to datasheet https://www.digikey.ca/en/products/detail/allegro-microsystems/ACS712ELCTR-20A-T/1284607
    //need to convert 0-2.5v as being - A and 2.5-5 as being + Amps, it's why it reads around 2.5 when open (0A)  
  C = abs(C) - abs(iadj);
  C = (C * pwm)/ 255;
  analogWrite( dschrgpin, pwm);
  test="pwm";
  }
  else {
   C = (((analogRead( A1 )-512) ) *0.048875855327468); 
  //according to datasheet https://www.digikey.ca/en/products/detail/allegro-microsystems/ACS712ELCTR-20A-T/1284607
    //need to convert 0-2.5v as being - A and 2.5-5 as being + Amps, it's why it reads around 2.5 when open (0A)  
  C = abs(C) - abs(iadj); 
  test="no pwm";
  }

  oled.clear(); 

  oled.print(Stage);
  
  oled.print(" V:");
  oled.print(V, 2);
  oled.print(" I:");
  oled.println(C, 2);
  
  oled.print((PowerTemp/ 3600  * ( float(pollTime) / 1000 )), 2);
  oled.print("Wh ");
  oled.print((AhTemp/ 3600  * ( float(pollTime) / 1000 )), 2);
  oled.println("Ah");

  oled.print(battype);
  oled.print(" V:");
  oled.print(MinV);
  oled.print("-");
  oled.println(MaxV);

  oled.print("PWM=");
  oled.print(round(pwm/2.55));
  oled.print("% ");
  //oled.print("S_Wh=");
  //oled.print(round(100-(PowerTemp2/PowerTemp*100)));
  //oled.print("% ");
}
