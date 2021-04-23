

void setup() {
  //Wire.begin();
  //Wire.setClock(400000L);
  
  Serial.begin( 115200 ); 
  //Serial.println("on");
  
  analogReference(VDD); //DEFAULT for nano, VDD for nano every
  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

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
  //Serial.println("booting");
  
  display.clearDisplay();
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.println("booting");
  display.display();
  delay(500);

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
  //Serial.println("voltage type is set");
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
//Serial.println("setup end");
}
