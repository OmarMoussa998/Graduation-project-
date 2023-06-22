
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include "HAL.h"
#include "MCAL.h"





int main ( )
{
	uint32_t first , second, third , high , period;
	char frequency[14], duty_cy[7] ;
	
	LCD_Init();
	

	ICU_init();

	PORTD = 0xFF;		/* Turn on Pull-UP resistor */
	

	while(1)
	{

		ICU_Read ( &first , &second , &third );
		

		if((first<second) && (second<third))					/* check for valid condition, to avoid timer overflow reading */

		{
			high = second - first;
			period = third - first;
			
			long freq= F_CPU*0.001/period;/* Calculate frequency in KHz*/

			/* Calculate duty cycle */
			float duty_cycle =((float) high /(float)period)*100;
			ltoa(freq,frequency,10);
			
			itoa((int)duty_cycle,duty_cy,10);
			
			LCD_Command(0x80);
			LCD_String("Freq: ");
			LCD_String(frequency);
			LCD_String(" KHz    ");
			
			LCD_Command(0xC0);
			LCD_String("Duty: ");
			LCD_String(duty_cy);
			LCD_String(" %      ");



		}
		
		else
		{
			LCD_Clear();
			LCD_String("OUT OF RANGE!!");
		}
		
		_delay_ms(50);
		
	}
}

