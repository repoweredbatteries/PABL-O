#include <SSD1306Ascii.h>
#include <SSD1306AsciiAvrI2c.h>
#include <SSD1306AsciiSoftSpi.h>
#include <SSD1306AsciiSpi.h>
#include <SSD1306AsciiWire.h>
#include <SSD1306init.h>

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C

// Define proper RST_PIN if required.
#define RST_PIN -1

SSD1306AsciiAvrI2c oled;

#include <SD.h>
#include <SPI.h>
#include <Wire.h>
#include <SimpleRotary.h>


File myFile;
//volatile byte State = LOW; //another way to make the status var
//float State = 0; //start in discharge state
boolean State, areweago=1; //state is charge state, areweago is the pause / resume state where 0 is paused
float V = 0, C = 0, vadj = 0, iadj = -0.06058;
volatile int   Cycles = 1000;
int   Times = 0, pollTime = 10000;
float PowerC = 0, PowerD = 0; //Measured and derived values
float MaxV = 3.55, MinV = 2.1;
byte relay1pin = 5, relay2pin = 6; //use 3 and 4 because 2 and 3 only can be used for interrupt, and 0 and 1 seem to have special functions too
byte rturn, rpush, buttonmode = 0; //states 1 and 2 are CW and CCW rotation

// rotary encoder call; Pin A, Pin B, Button Pin
SimpleRotary rotary(2,3,4);
