
#ifndef HAL_H_					/* Define library H file if not defined */
#define HAL_H_

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


#define LCD_Data_Dir DDRB				/* Define LCD data port direction */
#define LCD_Command_Dir DDRC			/* Define LCD command port direction register */
#define LCD_Data_Port PORTB				/* Define LCD data port */
#define LCD_Command_Port PORTC			/* Define LCD data port */
#define EN PINC2							/* Define Enable signal pin */
#define RW PINC1							/* Define Read/Write signal pin */
#define RS PINC0							/* Define Register Select (data reg./command reg.) signal pin */



void LCD_Command (char);				/* LCD command write function */
void LCD_Char (char);					/* LCD data write function */
void LCD_Init (void);					/* LCD Initialize function */
void LCD_String (char*);				/* Send string to LCD function */
void LCD_String_xy (char,char,char*);	/* Send row, position and string to LCD function */
void LCD_Clear (void);					/* LCD clear function */
void LCD_Custom_Char ( uint8_t loc, volatile uint8_t *msg);  /* LCD Custom character */







#endif									/* HAL_H_ */