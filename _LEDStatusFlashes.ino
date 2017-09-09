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

void LEDStatusFlashes(byte pin, byte timeBlink, unsigned int intervalLEDStatus, byte state)
{
  #define timeLED 10

  static long timeLEDStatus;
  static byte timeBlinked;
  static bool ledStatus;

  pinMode(pin, OUTPUT);

  if (millis() - timeLEDStatus > intervalLEDStatus)
  {
    ledStatus     = true;
    timeBlinked   = 1;
    timeLEDStatus = millis();
  }

  long checkTime = millis() - (timeLEDStatus + timeBlinked*timeLED*30);

  if (ledStatus && (checkTime > 0))
  {
    timeBlinked++;
    if (timeBlinked > timeBlink)
    {
      timeBlinked = 0;
      ledStatus   = false;
    }
    digitalWrite(pin, state);
    delay(timeLED);
    digitalWrite(pin, !state);
  }
  else
  {
    digitalWrite(pin, !state);
  }
}

