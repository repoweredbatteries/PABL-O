
void Refresh_V_C_OLED() { //C refreshed separately to get accurate charge current
  V = ( adc.read( A0 )*0.0048875855327468 );
  V = abs(V) + vadj;
  C = (adc.read( A1 ) *0.0048875855327468) - 24.9;
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

if (((PowerTemp/ 3600  * ( float(pollTime) / 1000 )), 2) < 10) {
  if (((PowerTemp/ 3600  * ( float(pollTime) / 1000 )), 2) > 5.2) {
    oled.print("! ");
  }
  else {oled.print(" ");};
  oled.print(PctCapacity, 0);
  oled.print("%");
  oled.print((AhTemp/ 3600  * ( float(pollTime) / 1000 )), 2);
  oled.print("Ah");
  if (AhTemp > 1.43) {
    oled.print("! ");
  }
  else {oled.print(" ");};
  oled.print(PctCapacityAh, 0);
  oled.println("%");
}

if (((PowerTemp/ 3600  * ( float(pollTime) / 1000 )), 2) > 10) {
  if (((PowerTemp/ 3600  * ( float(pollTime) / 1000 )), 2) > (5.2*8)) {
    oled.print("! ");
  }
  else {oled.print(" ");};
  oled.print((PctCapacity/8), 0);
  oled.print("%");
  oled.print((AhTemp/ 3600  * ( float(pollTime) / 1000 )), 2);
  oled.print("Ah");
  if (AhTemp > (1.43*8)) {
    oled.print("! ");
  }
  else {oled.print(" ");};
  oled.print((PctCapacityAh/8), 0);
  oled.println("%");
}

  oled.print("Type: ");
  oled.print(battype);
  oled.print(" V:");
  oled.print(MinV);
  oled.print("-");
  oled.print(MaxV);

}
