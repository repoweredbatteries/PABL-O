#include <SD.h>
#include <SPI.h>
#include <Wire.h>
#include <SimpleRotary.h>
//#include <Oversampling.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
/*
 *  fet states: low has an LED on and turns off the FET
 *  create code that tracks how much is charged and discharged and uses it to apply the formula (or part of it) automatically to grade the pack
 *  instead of a pot for continuous choices, maybe use a digital port and either 1 or 1000 cycles? Two digital pots combined for binary options of 1, 10, 100, or 1000????
 */


//volatile byte State = LOW; //another way to make the status var
boolean areweago=1, State = 0, dischargestep = 1; //state is charge state, areweago is the pause / resume state where 0 is paused
float V = 0, C = 0;
float vadj = 0, iadj = -0.06058, vend = 0, vday = 0;
int   pollTime = 10000, t23v1 = 0, PctCapacity, PctCapacityAh, pwmsrc;
float PowerTemp = 0, AhTemp = 0, PowerTemp2 = 0, AhTemp2 = 0; //Measured and derived values
float MaxV = 3.55, MinV = 2, StoreV = 3;
byte chrgpin = 5, dschrgpin = 9, chrgon = 7, pwm = 0; 
byte rturn, rpush, buttonmode = 0; //states 1 and 2 are CW and CCW rotation
String Grade = "XXX", battype = "LiFeP04", test, Stage;

// rotary encoder call; Pin A, Pin B, Button Pin
SimpleRotary rotary(2,3,4);

//Oversampling adc(10, 11, 2); //Adc Bytes 10 or 12, Oversampeling Bytes 11-18, 2 Is avaraging count. for now oversampling readings hang, so try again later
