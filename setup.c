#include "header.h"
/*****************************************************************************************************
* delay_ms: Här ändras det talen du har skrivit i led_blink och i main avgörs de hur lång delayen är
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
* led_blink: Här har vi kodat vilken ordning lamporna ska blinka i.
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
*Static incline: Detta är en kod som läses en gång sedan kopieras till setup. Fördelen är att koden läses av snabbare.
***********************************************************************************************************************/

static inline void init_ports(void);
static inline void init_interrupts(void);


led_state_t diod = LED_STATE_OFF;
/*********************************************************************************************************************
*setup: I setup så säger vi till koden vilka portar som skall användas.
***********************************************************************************************************************/
void setup()
{
	init_interrupts();
	init_ports();

	return;
}
/*********************************************************************************************************************
*init_ports: Här har tilldelat vilka portar knapparna lamporna ska tillhöra.
***********************************************************************************************************************/
static inline void init_ports()
{
	DDRB = (1 << LED1) | (1 << LED2) | (1 << LED3);
	PORTB = (1 << NEXT_BUTTON);

	return;
}
/*********************************************************************************************************************
*init_interrupts: Här är det asembel kod för att interrupten skall fungera men även ifall de ska vara,
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
