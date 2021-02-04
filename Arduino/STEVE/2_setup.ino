

void setup() {
  Wire.begin();
  Wire.setClock(400000L);
  
  Serial.begin( 9600 ); 
  Serial.println("on");
//CODE CRASHING HERE WITH OLED INITIALIZATION. Very strange since this code is old and unchanged, copied from examples...   
#if RST_PIN >= 0
  oled.begin(&Adafruit128x32, I2C_ADDRESS, RST_PIN);
#else // RST_PIN >= 0
  oled.begin(&Adafruit128x32, I2C_ADDRESS);
#endif // RST_PIN >= 0
  // Call oled.setI2cClock(frequency) to change from the default frequency.

  oled.setFont(Adafruit5x7);
  
  analogReference( DEFAULT );

  // Set the trigger to be either a HIGH or LOW pin (Default: HIGH)
  // Note this sets all three pins to use the same state.
  rotary.setTrigger(HIGH);
  // Set the debounce delay in ms  (Default: 2)
  rotary.setDebounceDelay(5);
  // Set the error correction delay in ms  (Default: 200)
  rotary.setErrorDelay(250);
  rturn = rotary.rotate();
  rpush = rotary.pushType(1000); //amount of time for a long push (rpush == 2) vs normal push (rpush == 1)

  pinMode( chrgpin, OUTPUT ); 
  pinMode( chrgon, OUTPUT );
  pinMode( dschrgpin, OUTPUT );

  digitalWrite( chrgpin, LOW ); 
  digitalWrite( chrgon, HIGH ); 
  digitalWrite(dschrgpin, LOW); 
  Serial.println("booting");
  oled.print("booting");

  //set cutoff voltages based on A2, 40k will give 4v, 20k will give 3.33v, and 10k will give 2.5v
  if ( ( analogRead( A2 )*0.0048875855327468 ) < 1 ){
  MaxV = 4.2;
  MinV = 2.9;
  StoreV = 3.87;
  battype = "Li-ion";
  }
   else if ( ( analogRead( A2 )*0.0048875855327468 ) < 2 ){
  MaxV = 3.6;
  MinV = 2.5;
  StoreV = 3;
  battype = "LiFeP04";
  }
   else {
  MaxV = 2.8;
  MinV = 1.8;
  StoreV = 2.5;
  battype = "LTO";
  }
  Serial.println("voltage type is set");
  digitalWrite( chrgon, LOW ); 

/* need to find how to make it that this code does not stall the program if it fails
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
*/
Serial.println("setup end");
}
