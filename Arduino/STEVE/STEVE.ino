/*
 * Pins for analogue are
 *A0 voltage read 
 *A1 current read
 *A2 voltage control for charging and discharging cutoffs
 *A3 TMP1 / AUX1 - for ambient temp
 *A4 OLED_SDA
 *A5 OLED_SLC
 *A6 Discharge PWM control through pot
 *A7 TMP2 / AUX2 - near battery
 *D5 is charge control
 *D7 is the dc-dc enable
 *D9 is the discharge enable
 *
 *auto calibrate current by setting 0 (iadj) based on when there is no load - to get a proper reading, must reset the arduino after plugging in power
 *
 *TODO
 *
 *
*add IR calc - Sag (aka delta V) = DCIR (in ohms) x load (in amps)
*do a comparison of total fast discharge Wh vs slow discharge Wh (indicate the packs ability at high discharge???)
*do a comparison of charge and discharge capacity to indirectly measure heat loss?
*grade IR
*
*Add a switch on A3 for either recording the data or not.. or ALWAYS record, but don't crash when there is no SD card
*Current reads 2.44A when open, but has a sensible value when under load. Figure out a way to "hide" 2.44 when no load? not very important
*/
