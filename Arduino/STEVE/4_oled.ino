
void Refresh_V_C_OLED() { //C refreshed separately to get accurate charge current

  V = ( analogRead( A0 )*0.0048875855327468 );
  V = abs(V) + vadj;
  C = (analogRead( A1 ) *0.048875855327468) - 24.9;
  C = abs(C) + iadj;

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
}
