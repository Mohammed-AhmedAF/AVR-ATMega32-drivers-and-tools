#include "DIO_interface.h"
#include "LCD_interface.h"
#include "Std_Types.h"
#include "Macros.h"
#include <avr/io.h>
#include <util/delay.h>

u8 u8analog = 0;
u8 u8digitalValue = 0;
u8 u8xPos, u8yPos;
void main(void) {
	LCD_vidInit();

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
		LCD_vidWriteCharacter(u8xPos+'0');		
		LCD_vidWriteCharacter(u8yPos+'0');
		LCD_vidSendCommand(LCD_CLEAR_SCREEN);
		LCD_vidSendCommand(LCD_CLEAR_SCREEN);
		SET_BIT(ADCSRA,6);
		
	}
}
