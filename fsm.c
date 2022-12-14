#include "header.h"

/*********************************************************************************************************************
*fsm_update: H�r visas det vad det h�nder n�r du trycker p� knappen sedan vilka tillst�nd som �r tilldelat f�r lamporna
***********************************************************************************************************************/
void fsm_update(void)
{
	switch (diod)
	{
		case LED_STATE_OFF:
		{
			if (NEXT_BUTTON_PRESSED)
			{
				diod = LED_STATE_BLINK;
			}

			break;
		}
		case LED_STATE_BLINK:
		{
			if (NEXT_BUTTON_PRESSED)
			{
				diod = LED_STATE_OFF;
			}
			break;
		}
	}

}

/*********************************************************************************************************************
*fsm_set_output: H�r anv�nds det i main f�r att eftersom koden ska f�rst� vilken tillst�nd som den skall skicka ut.
***********************************************************************************************************************/

void fsm_set_output(void)
{
	LEDS_OFF;

	if (diod == LED_STATE_OFF)LEDS_OFF;
	else if (diod == LED_STATE_BLINK) led_blink();


	return;
}