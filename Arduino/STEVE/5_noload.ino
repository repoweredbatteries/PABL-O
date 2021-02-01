
void noload ( ) {
  //change to no load
digitalWrite( chrgpin, LOW ); 
digitalWrite( chrgon, LOW );
analogWrite(dschrgpin, 0); 
}
