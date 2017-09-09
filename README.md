# Arduino_LED_Status_multi_Flashes
This function will flash a LED with cycles

 * Author: Pham Duy Anh - CKD - phamduyanh@gmail.com
 * Create: 08-09-2017
 * Update: 09-09-2017
 * Forum:  http://forum.cncprovn.com/forums/8
 
          .                                                       state             (stat flashing led, HIGHT or LOW);
          .           *     *     *<----------------------------- timeBlink         (the number of times the leds flash in one cycle)
          .        ->| |<---------------------------------------- timeLED           (time led flash, ms)
          .        ->| |                                      |<- intervalLEDStatus (time of a cycle, ms)
          Led on      _     _     _
          Led off  __| |___| |___| |__________________________|
 
 # Example:
    //LEDStatusFlashes(byte pin, byte timeBlink, unsigned int intervalLEDStatus, byte state)
    void loop()
    {
      LEDStatusFlashes(13, 2, 2000, 1);
    }
  
 # Attention:
    The cycle will not be accurate if the loop() time is too large
