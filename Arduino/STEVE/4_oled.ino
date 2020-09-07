
void Refresh_V_C_OLED() { //C refreshed separately to get accurate charge current

  /*V = ( adc.read( A0 )*0.0048875855327468 );
  V = abs(V) + vadj;
  C = (adc.read( A1 ) *0.0048875855327468) - 24.9;
  C = abs(C) + iadj; */
  V = ( analogRead( A0 )*0.0048875855327468 );
  V = abs(V) + vadj;
  C = (((analogRead( A1 )-512) ) *0.048875855327468); 
  //according to datasheet https://www.digikey.ca/en/products/detail/allegro-microsystems/ACS712ELCTR-20A-T/1284607
    //need to convert 0-2.5v as being - A and 2.5-5 as being + Amps, it's why it reads around 2.5 when open (0A)  
  C = abs(C) - abs(iadj);

  oled.clear(); 
  
  if (State == 1) {
    oled.print("C ");    
  }
  else if (State == 0) {
    oled.print("D ");
  }
  else if (State == 2) {
    oled.print("F ");
  }
  
  oled.print("V: ");
  oled.print(V, 2);
  oled.print(" C: ");
  oled.println(C, 2);
  oled.print((PowerTemp/ 3600  * ( float(pollTime) / 1000 )), 2);
  oled.print("Wh");

  int pwm = analogRead(A6);
  pwm = map(pwm,0,1023,0,255);

  oled.print((AhTemp/ 3600  * ( float(pollTime) / 1000 )), 2);
  oled.println("Ah");

  oled.print(battype);
  oled.print(" V:");
  oled.print(MinV);
  oled.print("-");
  oled.print(MaxV);


}
