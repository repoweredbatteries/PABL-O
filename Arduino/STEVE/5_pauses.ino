void startpause() {
unsigned long timer;
 timer = millis();
  while (millis() < (timer + pollTime)) {
    buttonpickup();
  }  
};

void restr() {
 unsigned long timer;
    digitalWrite( relay1pin, HIGH ); //change to  nothing state as here the NC goes to center tap of relay 2 and
      timer = millis();
      while (millis() < (timer + 2000)) {
        Refresh_V_C_OLED();
      }  
};

void longrestr() {
 unsigned long timer;
    digitalWrite( relay1pin, HIGH ); //change to  nothing state as here the NC goes to center tap of relay 2 and
      timer = millis();
      while (millis() < (timer + 10000)) {
        Refresh_V_C_OLED();
      }  
};

void minrestr() {
 unsigned long timer;
    digitalWrite( relay1pin, HIGH ); //change to  nothing state as here the NC goes to center tap of relay 2 and
      timer = millis();
      while (millis() < (timer + 60000)) {
        Refresh_V_C_OLED();
      }  
};

void hrrestr() {
 unsigned long timer;
    digitalWrite( relay1pin, HIGH ); //change to  nothing state as here the NC goes to center tap of relay 2 and
      timer = millis();
      while (millis() < (timer + 3600000)) {
        Refresh_V_C_OLED();
      }  
};
