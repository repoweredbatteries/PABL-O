void setup() {

  Serial.begin( 9600 );

  attachInterrupt(digitalPinToInterrupt(2), testISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), testISR, CHANGE);
  
  analogReference( DEFAULT );

  // Set the trigger to be either a HIGH or LOW pin (Default: HIGH)
  // Note this sets all three pins to use the same state.
  rotary.setTrigger(HIGH);
  // Set the debounce delay in ms  (Default: 2)
  rotary.setDebounceDelay(5);
  // Set the error correction delay in ms  (Default: 200)
  rotary.setErrorDelay(250);
  rturn = rotary.rotate();
  rpush = rotary.pushType(1); //amount of time for a long push (rpush == 2) vs normal push (rpush == 1)

  // SD Card Initialization
  if ( SD.begin(  ) )
  {
    Serial.println( F ("SD card is ready to use." ) );
    myFile = SD.open( "test.txt", FILE_WRITE );
    myFile.print( "State, Times, V, I" );         
    myFile.close(  ); // close the file
  } else
  {
    Serial.println( F ("SD card initialization failed" ) );
    return;
  }
//start in discharge mode
  State = 0;

  pinMode( relay1pin, OUTPUT ); 
  digitalWrite( relay1pin, LOW ); //use NO of relay 1
  pinMode( relay2pin, OUTPUT );
  digitalWrite( relay2pin, HIGH ); //set to use NC of relay 2 if relay 1 switches

#if RST_PIN >= 0
  oled.begin(&Adafruit128x32, I2C_ADDRESS, RST_PIN);
#else // RST_PIN >= 0
  oled.begin(&Adafruit128x32, I2C_ADDRESS);
#endif // RST_PIN >= 0
  // Call oled.setI2cClock(frequency) to change from the default frequency.
oled.setFont(Adafruit5x7);
};
