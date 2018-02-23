#include "DIO_interface.h"
#include "LCD_interface.h"
#include "Macros.h"
#include "Std_Types.h"
#include <avr/io.h>
#include <util/delay.h>
u8 i;
void main(void) {
	
	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN3,1);

	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);

	SET_BIT(TCCR0,5);
	CLEAR_BIT(TCCR0,4);

	SET_BIT(TCCR0,0);

	TCNT0=0;
	while(1) {
		for (i = 0; i < 255; i++) {
			OCR0 = i;
			_delay_ms(1000);
		}
		for 
				
	}
}
