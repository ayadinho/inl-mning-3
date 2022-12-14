#include "header.h"
/*****************************************************************************************************
* delay_ms: H�r �ndras det talen du har skrivit i led_blink och i main avg�rs de hur l�ng delayen �r
*******************************************************************************************************/
void delay_ms(const uint16_t delay_time_ms)
{
	for (uint16_t i = 0; i < delay_time_ms; ++i)
	{
		_delay_ms(1);
	}

	return;
}

/*****************************************************************************************************
* led_blink: H�r har vi kodat vilken ordning lamporna ska blinka i.
*******************************************************************************************************/
void led_blink(const uint16_t delay_time_ms)
{

	if (diod == LED_STATE_BLINK)
	{
		LED3_OFF;
		LED1_ON;
		delay_ms(delay_time_ms);
		LED1_OFF;
		LED2_ON;
		delay_ms(delay_time_ms);
		LED2_OFF;
		LED3_ON;
		delay_ms(delay_time_ms);

		return;
	}
}
/*********************************************************************************************************************
*Static incline: Detta �r en kod som l�ses en g�ng sedan kopieras till setup. F�rdelen �r att koden l�ses av snabbare.
***********************************************************************************************************************/

static inline void init_ports(void);
static inline void init_interrupts(void);


led_state_t diod = LED_STATE_OFF;
/*********************************************************************************************************************
*setup: I setup s� s�ger vi till koden vilka portar som skall anv�ndas.
***********************************************************************************************************************/
void setup()
{
	init_interrupts();
	init_ports();

	return;
}
/*********************************************************************************************************************
*init_ports: H�r har tilldelat vilka portar knapparna lamporna ska tillh�ra.
***********************************************************************************************************************/
static inline void init_ports()
{
	DDRB = (1 << LED1) | (1 << LED2) | (1 << LED3);
	PORTB = (1 << NEXT_BUTTON);

	return;
}
/*********************************************************************************************************************
*init_interrupts: H�r �r det asembel kod f�r att interrupten skall fungera men �ven ifall de ska vara,
* en stigande eller fallande flank.
***********************************************************************************************************************/
static inline void init_interrupts()
{
	asm("SEI"); 
	PCICR = (1 << PCIE0);
	PCMSK0 = (1 << NEXT_BUTTON);

	EICRA = (1 << ISC00) | (1 << ISC01); 
	EIMSK = (1 << INT0);

	return;
}
