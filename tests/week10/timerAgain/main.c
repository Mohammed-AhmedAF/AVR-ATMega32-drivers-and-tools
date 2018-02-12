#include "dio.h"
#include "lcd.h"
#include "Std_Types.h"
#include "Macros.h"
#include <util/delay.h>
#include <avr/interrupt.h>
volatile u8 count;
volatile u8 res;
void displayTCNT(void);
void main(void) {

	Dio_vidSetPortDirection(DIO_PORTA,0b10000111);
	Dio_vidSetPortDirection(DIO_PORTD,0b11111111);
	Lcd_vidInit();

	Set_Bit(TIMSK,0);

	//Setting prescaler
	Set_Bit(TCCR0,0);
	Clear_Bit(TCCR0,1);
	Set_Bit(TCCR0,2);

	Clear_Bit(TCCR0,3);
	Clear_Bit(TCCR0,6);

	Set_Bit(SREG,7);

	while(1) {
		displayTCNT();
	}
}
void displayTCNT() {
	s8 * message;
	res = TCNT0;
	u8 arr[3];
	u8 u8a;
	u8 x = 100;
	for (s8 i = 0; i < 3; i++) {
		u8a = (res/x)+48;
		res = res - (res/x)*x;
		arr[i] = u8a;
		x = x/10;
	}
	message = arr;
	Lcd_vidInsertSizedMessage(message,3);
	Lcd_vidSendCommand(LCD_CLEAR_SCREEN);
	Lcd_vidSendCommand(LCD_RETURN_HOME);

}

ISR(TIMER0_OVF_vect) {
	count++;
}


