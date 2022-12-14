#include "header.h"

/*********************************************************************************************************************
*fsm_update: Här visas det vad det händer när du trycker på knappen sedan vilka tillstånd som är tilldelat för lamporna
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
*fsm_set_output: Här används det i main för att eftersom koden ska förstå vilken tillstånd som den skall skicka ut.
***********************************************************************************************************************/

void fsm_set_output(void)
{
	LEDS_OFF;

	if (diod == LED_STATE_OFF)LEDS_OFF;
	else if (diod == LED_STATE_BLINK) led_blink();


	return;
}