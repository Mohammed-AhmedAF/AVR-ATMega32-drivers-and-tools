#include "Std_Types.h"
#include "dio.h"
#include "Macros.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include "lcd.h"
u8 value = 0;

u8 u8ToChar(u8);
void main(void) {

	Dio_vidSetPortDirection(DIO_PORTB,0xFF);
	Dio_vidSetPortValue(DIO_PORTB,0x00);
	Dio_vidSetPortDirection(DIO_PORTD,0xFF);
	Dio_vidSetPortDirection(DIO_PORTA,0b00000111);
	Lcd_vidInit();

	//enable interrupt
	//enable adc
	Set_Bit(ADCSRA,7);

	//setting prescaler
	Set_Bit(ADCSRA,2);
	Set_Bit(ADCSRA,1);
	Set_Bit(ADCSRA,0);

	//local adc interrupt
	Set_Bit(ADCSRA,3);

	//setting reference and channel
	Clear_Bit(ADMUX,7);
	Set_Bit(ADMUX,6);
	//setting left adjustment
	Set_Bit(ADMUX,5);

	//selecting channel
	Set_Bit(ADMUX,0);
	Set_Bit(ADMUX,1);
	Set_Bit(ADMUX,2);
	Clear_Bit(ADMUX,3);
	Clear_Bit(ADMUX,4);

	//Setting global interrupt enable
	Set_Bit(SREG,7);

	Set_Bit(ADCSRA,6); //start first conversion
	while(1) {
		Dio_vidSetPortValue(DIO_PORTB,value);
		u8ToChar(value);

	}
}

ISR (ADC_vect) {
	value = ADCH;
	Set_Bit(ADCSRA,6); // start next conversion
}

u8 u8ToChar(u8 res) {
	u8 x = 100;
	u8 u8a;
	u8 arr[3];
	u8 * message;
	for (s8 i = 0; i < 3; i++) {
		u8a = (res/x)+48;
		res = res - (res/x)*x;
		arr[i] = u8a;
		x = x/10;
	}
	message = arr;
	Lcd_vidInsertSizedMessage(message,3);
	_delay_ms(500);
	Lcd_vidSendCommand(LCD_CLEAR_SCREEN);
	Lcd_vidSendCommand(LCD_RETURN_HOME);


}
