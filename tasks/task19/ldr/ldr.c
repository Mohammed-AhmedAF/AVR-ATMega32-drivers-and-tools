#include "dio.h"
#include "Std_Types.h"
#include "Macros.h"
#include "lcd.h"
#include <avr/interrupt.h>
#include <util/delay.h>

void vidToChar(u8); 

u8 value = 0;


void main(void) {
	
	//Setting pin direction for LED
	Dio_vidSetPortDirection(DIO_PORTA,0b00000111);
	Dio_vidSetPortDirection(DIO_PORTD,0b11111111);
	//Setting Global Interrupt Enable
	Set_Bit(SREG,7);

	//Setting ADC Enable in ADCSRA
	Set_Bit(ADCSRA,7);

	//Setting Prescaler Selection bits in ADCSRA
	Set_Bit(ADCSRA,0);
	Set_Bit(ADCSRA,1);
	Set_Bit(ADCSRA,2);

	//Setting ADC Interrupt Enable in ADCSRA
	Set_Bit(ADCSRA,3);
	
	//Selecting ADC input pin in ADMUX, the first five bit
	Set_Bit(ADMUX,0);
	Set_Bit(ADMUX,1);
	Set_Bit(ADMUX,2);
	Clear_Bit(ADMUX,3);
	Clear_Bit(ADMUX,4);

	//Setting left adjustment
	Set_Bit(ADMUX,5);

	//Setting Reference Selection Bits
	Clear_Bit(ADMUX,7);
	Set_Bit(ADMUX,6);

	//Setting ADC Start Conversion
	Set_Bit(ADCSRA,6);


	Lcd_vidInit();

	while(1) {
		/*	if (ADCH !=0 ) {
			Dio_vidSetPinValue(DIO_PORTA,7,1);
			_delay_ms(300);
			}
			else {
			Dio_vidSetPinValue(DIO_PORTA,7,0);
			_delay_ms(300);
			} */
		vidToChar(value);
	}

}

ISR(ADC_vect) {
	value = ADCH;
	//Start the next conversion	
	Set_Bit(ADCSRA,6);	
}

void vidToChar(u8 res) {
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
