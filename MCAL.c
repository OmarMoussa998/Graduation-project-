
#include "MCAL.h"

void ICU_init()
{
	DDRB &= ~(1 << PIND6);										// Set capture pin as input
	TCCR1B |= (1 << ICES1) | (1 << CS10);						// Rising edge trigger, no prescaler
	TIMSK |= (1 << TICIE1);										// Enable input capture interrupt
	TIFR = (1<<ICF1);											/* clear ICP flag (Input Capture flag) */
}

void ICU_Read( uint32_t* first , uint32_t* second , uint32_t* third )
{
	TIFR = (1<<ICF1);				// clear ICP flag (Input Capture flag)
	TCCR1B = 0x41;					// rising edge, No prescaler
	while ((TIFR&(1<<ICF1)) == 0);

	*first = ICR1;						// take value of capture register
	TIFR = (1<<ICF1);				// clear ICP flag (Input Capture flag)
	
	TCCR1B = 0x01;				   // falling edge, No prescaler

	while ((TIFR&(1<<ICF1)) == 0);

	*second = ICR1;						// take value of capture register
	TIFR = (1<<ICF1);				// clear ICP flag (Input Capture flag)
	
	TCCR1B = 0x41;					// rising edge, No prescaler
	while ((TIFR&(1<<ICF1)) == 0);
	*third = ICR1;						// take value of capture register
	TIFR = (1<<ICF1);				// clear ICP flag (Input Capture flag)

	TCCR1B = 0;				        // stop the timer
	
}