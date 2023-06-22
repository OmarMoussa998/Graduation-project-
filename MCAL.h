


#ifndef MCAL_H_
#define MCAL_H_

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

void ICU_init();							/* Input capture unit Initialize*/
void ICU_Read( uint32_t* first , uint32_t* second , uint32_t* third );  /* Reading the capture signal*/

#endif /* MCAL_H_ */