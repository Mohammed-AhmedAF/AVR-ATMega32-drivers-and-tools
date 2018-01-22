#include "dio.h"
#include "Std_Types.h"
#include "Macros.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include "lcd.h"
volatile u8 count = 0;

void main(void) {
	Dio_vidSetPortDirection(DIO_PORTA,0b10000111);
	Dio_vidSetPortDirection(DIO_PORTD,0b11111111);
	Lcd_vidInit();
	//set prescale option

	Set_Bit(TCCR0,2);
	Clear_Bit(TCCR0,1);
	Set_Bit(TCCR0,0);

	//set overflow interrupt flag
	Set_Bit(TIMSK,0);


	//Initialize counter
	TCNT0 = 0;
	//setting global interrupt
	Set_Bit(SREG,7);
	Lcd_vidSendCommand(LCD_CLEAR_SCREEN);
	Lcd_vidSendCommand(LCD_RETURN_HOME);
	while (1) {
		if (count >= 30) {
				Toggle_Bit(PORTA,7);
				count = 0;
		}
	}

}

ISR(TIMER0_OVF_vect) {
	count++;
}
