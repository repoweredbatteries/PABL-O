
void Refresh_V_C_OLED() { //C refreshed separately to get accurate charge current

  V = ( analogRead( A0 )*0.0048875855327468 );
  V = abs(V) + vadj;
  C = (analogRead( A1 ) *0.048875855327468) - 24.9;
  C = abs(C) + iadj;

  display.clearDisplay();
  display.setCursor(0,0);

  display.print(analogRead( A2 ));
  display.print(F(" "));
  display.print(analogRead( A0 ));
  display.print(F(" "));
  display.println(analogRead( A1 ));

  display.print(Stage);
  display.print(F(" V:"));
  display.print(V, 2);
  display.print(F(" I:"));
  display.println(C, 2);

  display.print((PowerTemp/ 3600  * ( float(pollTime) / 1000 )), 2);
  display.print(F("Wh "));
  display.print((AhTemp/ 3600  * ( float(pollTime) / 1000 )), 2);
  display.println(F("Ah"));

  display.print(battype);
  display.print(F(" V:"));
  display.print(MinV);
  display.print(F("-"));
  display.print(MaxV);
  display.display();
}
