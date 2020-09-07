
void Refresh_V_C_OLED() { //C refreshed separately to get accurate charge current

  /*V = ( adc.read( A0 )*0.0048875855327468 );
  V = abs(V) + vadj;
  C = (adc.read( A1 ) *0.0048875855327468) - 24.9;
  C = abs(C) + iadj; */
  V = ( analogRead( A0 )*0.0048875855327468 );
  V = abs(V) + vadj;
  C = (analogRead( A1 ) *0.0048875855327468) -2.44;
  C = abs(C) + iadj;

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
