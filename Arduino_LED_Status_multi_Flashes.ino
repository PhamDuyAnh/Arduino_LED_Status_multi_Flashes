/***************************************************************
 * Pham Duy Anh - CKD - phamduyanh@gmail.com
 * Create: 08-09-2017
 * Update: 09-09-2017
 * Forum:  http://forum.cncprovn.com/forums/80-Arduino
 * 
 * This function will flash a LED with cycles
 *                                                         state             (stat flashing led, HIGHT or LOW);
 *             *     *     *<----------------------------- timeBlink         (the number of times the leds flash in one cycle)
 *          ->| |<---------------------------------------- timeLED           (time led flash, ms)
 *          ->| |                                      |<- intervalLEDStatus (time of a cycle, ms)
 * Led on      _     _     _
 * Led off  __| |___| |___| |__________________________|
 * 
 * Example:
 *   void loop()
 *   {
 *     LEDStatusFlashes(13, 2, 2000, 1);
 *   }
 * 
 * Attention:
 *   The cycle will not be accurate if the loop() time is too large
 **************************************************************/
 
#define portLED PORTB
#define pinLED  5       //pin 13
#define portChk PORTB
#define pinChk  4       //pin 12

void setup()
{
  Serial.begin(115200);
  pinMode(12, OUTPUT);
}

void loop()
{
  bitWrite(portChk, pinChk, !bitRead(portChk, pinChk));
  LEDStatusFlashes(13, 1, 2000, 1);
}
