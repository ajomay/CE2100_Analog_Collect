// #############################################################################
//  Led.C
//
//
//
//  Created: 13.11.2019
//  History:
//
//  (C) ce.tron Gesellschaft f?r Hard-& Softwaretechnik mbH
//  Roentgenstrasse 104
//  D-64291 Darmstadt
// #############################################################################

//-------------------------------------------------------------------
//
#include "Led.h"

#include "Hdw.h"


//-------------------------------------------------------------------
//
void LedMorse(unsigned int Light, unsigned int Dark)
{
  HDW_LED_BLINK_MODE_OUTPUT();
  HDW_LED_BLINK_ON();

  delay(Light);
  HDW_LED_BLINK_OFF();
  delay(Dark);
}

//-------------------------------------------------------------------
//
void LedMorseValue(unsigned char Val)
{
  int k;

  for (k = 0; k < 8; k++)
  {
    if ((Val & (0x80 >> k)) != 0)
    {
      LedMorse(500, 500);
    }
    else
    {
      LedMorse(100, 900);
    }
    if (k == 3)
		{
		delay(500);
		}

  }
}

//--------------------------------------------------------------------------------
// Show Flashing
//
void LedFlashes(void)
{
  HDW_LED_BLINK_MODE_OUTPUT();
  HDW_LED_BLINK_OFF();
  delay(500);

  for (int i = 0; i < 5; i++)
  {
    HDW_LED_BLINK_ON();
    delay(100);
    HDW_LED_BLINK_OFF();
    delay(100);
  }
  delay(500);
}

//--------------------------------------------------------------------------------
// Show Rev and Sub as blinkcode on LED.
// Rev, Sub < 16
//
void LedMorseVersion(unsigned char Rev, unsigned char Sub)
{
  LedMorseValue(((Rev & 0x0F) << 4) + (Sub & 0x0F));
}

// #############################################################################
// #############################################################################
// #############################################################################
