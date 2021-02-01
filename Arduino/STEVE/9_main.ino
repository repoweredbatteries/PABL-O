void loop(  ) {
Serial.println("loop begin");
Refresh_V_C_OLED();

startpause();
int k=0;

while (areweago == 0){
buttonpickup ();
}

//start with a charge to be full
State = 1;
Stage = "C1";
Serial.println("turn on DC-DC");
digitalWrite( chrgon, HIGH );
chargeroutine ();

dischargestep = 1;
State = 0;
Stage = "D1";
digitalWrite( chrgon, LOW );
dischargeroutine();

State = 1;
Stage = "C2";
Serial.println("turn on DC-DC");
digitalWrite( chrgon, HIGH );
chargeroutine ();

noload ();
State = 0;
Stage = "IR";
digitalWrite( chrgon, LOW );
storageroutine (0.2);
//implement IR test here
storageroutine (0.7);


//MaxV = StoreV;
//digitalWrite( chrgon, HIGH );
//chargeroutine ();

//compute grade here based on collected data, 
//capacity as %, <70% D, 75%, C, 80% B, 85% A, >89% A+
//7.26 is nominal wh capacity
//time to 3v, do math on sag and such... use empirical data collected to find out which vsag indicated issues
//closes the areweago check
//Make sure the device doesn't just discharge itself when it is done or paused
  noload ();
//  State = 2;
//  vend = 99; //flag that all is done and now waiting for an hour to let the battery stabilize to measure end voltage
//  hrrestr();//wait 2 hours. In testing, saw a voltage bounce-back during that subsequent hour.
//  hrrestr();
//  vend = ( analogRead( A0 )*0.004883 );
//  vday = 99;
//  dayrestr();
//  vday = ( analogRead( A0 )*0.004883 );
//  State = 3;

//  Refresh_V_C_OLED();

int neverend = 1;
while (neverend == 1) {longrestr();};

}//closes loop

//change to do only 2 currents, wait 24h and check voltage change?
