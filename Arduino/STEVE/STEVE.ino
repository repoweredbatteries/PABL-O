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
*charge
*IR calc - Sag (aka delta V) = DCIR (in ohms) x load (in amps).
*Charge
*fast discharge
*pause
*mid discharge
*pause
*slow discharge
*pause
*charge
*
*
*state V A
*total Ah fast Wh slow Wh (indicate the packs ability at high discharge???)
*grade IR
*
*Add that A2 now reads for voltages split between 10k/10k 10k/20k and 10k/40k for battery type
*Add a switch on A3 for either recording the data or not.. or ALWAYS record, but don't crash when there is no SD card
*rotary indexer increases cycles? button? I say rotary indexer and then it can pickup settings until the areweago state is changed
*/
