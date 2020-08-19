void Refresh_V_C_OLED() {
   V = ( analogRead( A0 )*0.0048828125 );
   V = abs(V) + vadj;
   C = (analogRead( A1 ) *0.048828125) - 24.9;
   C = abs(C) + iadj;
   //-0.04 and -0.1 being on the abs instead of the measurement helps buffer the jitter

  oled.clear();
  // first row
  oled.print("Cycles: ");
  oled.print(Cycles - 1);
  oled.print(" Done: ");
  oled.println(Times - 1); //-1 because first discharge is to set the slate

 if (State == 0){
  oled.println("Discharging at ");
  }

  else {
  oled.println("Charging at ");    
  }
  oled.print(C, 2);
  oled.print("A ");
  oled.print(V, 2);
  oled.println("V");
  
  oled.print("C:");
  oled.print((PowerC / 3600  * ( float(pollTime) / 1000 )), 3);
  oled.print("Wh D:");
  oled.print((PowerD / 3600  * ( float(pollTime) / 1000 )), 3);
  Serial.println(PowerD);
  oled.println("Wh");

buttonpickup();
};
