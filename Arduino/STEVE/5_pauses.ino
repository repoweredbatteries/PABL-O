void startpause() {
unsigned long timer;
Serial.println("startpause function called");
 timer = millis();
  while (millis() < (timer + (pollTime - 100))) {
    buttonpickup();
  }  
};

void shortpause() {
unsigned long timer;
 timer = millis();
  while (millis() < (timer + 100)) {
    buttonpickup();
  }  
};

void restr() {
 unsigned long timer;
    digitalWrite( chrgpin, LOW ); 
    digitalWrite( dschrgpin, LOW );
      timer = millis();
      while (millis() < (timer + 2000)) {
        Refresh_V_C_OLED();
      }  
};

void longrestr() {
 unsigned long timer;
    digitalWrite( chrgpin, LOW ); 
    digitalWrite( dschrgpin, LOW );      
    timer = millis();
      while (millis() < (timer + 10000)) {
        Refresh_V_C_OLED();
      }  
};

void minrestr() {
 unsigned long timer;
    digitalWrite( chrgpin, LOW ); 
    digitalWrite( dschrgpin, LOW );
      timer = millis();
      while (millis() < (timer + 60000)) {
        Refresh_V_C_OLED();
      }  
};

void hrrestr() {
 unsigned long timer;
    digitalWrite( chrgpin, LOW ); 
    digitalWrite( dschrgpin, LOW );
      timer = millis();
      while (millis() < (timer + 3600000)) {
        Refresh_V_C_OLED();
      }  
};

void dayrestr() {
 unsigned long timer;
    digitalWrite( chrgpin, LOW ); 
    digitalWrite( dschrgpin, LOW );
      timer = millis();
      while (millis() < (timer + 86400000)) {
        Refresh_V_C_OLED();
      }  
};
