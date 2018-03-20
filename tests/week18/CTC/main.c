#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include <avr/io.h>
#include <util/delay.h>
#include "UART_interface.h"


u8 u8Val;
void main(void) {
	LCD_vidInit();	
	DIO_vidSetPinDirection(DIO_PORTD,DIO_PIN5,STD_HIGH);
	SET_BIT(TCCR1A,6);
	SET_BIT(TCCR1B,3);

	/*Clk selection*/
	SET_BIT(TCCR1B,2);
	CLEAR_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,0);

	OCR1A = 500;

	while(1) {
		LCD_vidWriteNumber(TCNT1);
		UART_vidSendByte(TCNT1);
		LCD_vidWriteCharacter(' ');
		
	}
}
