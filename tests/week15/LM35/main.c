#include "DIO_interface.h"
#include "LCD_interface.h"
#include "Std_Types.h"
#include "Macros.h"
#include <avr/io.h>
#include <util/delay.h>
u8 num[10] = {0b10100000,0b10101111,0b11000100,0b10000110,0b10001011,0b10010010,0b10010000,0b10100111,0b10000000,
0b10000010};
u8 u8analog = 0;
u8 u8digitalValue = 0;
u8 u8xPos, u8yPos;
void main(void) {

	DIO_vidSetPortDirection(DIO_PORTB,0b11111111);
	DIO_vidSetPortDirection(DIO_PORTD,0b11111111);
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN0,1);
	DIO_vidSetPinDirection(DIO_PORTC,DIO_PIN0,1);


	DIO_vidSetPinValue(DIO_PORTA,DIO_PIN0,1);
	DIO_vidSetPinValue(DIO_PORTC,DIO_PIN0,1);

	/*ADC initialization*/
	CLEAR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);
	SET_BIT(ADMUX,5);

	CLEAR_BIT(ADMUX,4);
	CLEAR_BIT(ADMUX,3);
	CLEAR_BIT(ADMUX,2);
	SET_BIT(ADMUX,1);
	SET_BIT(ADMUX,0);

	SET_BIT(ADCSRA,7);

	SET_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	CLEAR_BIT(ADCSRA,0);

	while(1) {
		u8digitalValue = ADCH;
		u8analog = ((u8digitalValue)*5*100)/256;
		u8xPos =u8analog/10;
		u8yPos = u8analog%10;
		DIO_vidSetPortValue(DIO_PORTB,num[u8xPos]);		
		DIO_vidSetPortValue(DIO_PORTD,num[u8yPos]);
		SET_BIT(ADCSRA,6);
		
	}
}
