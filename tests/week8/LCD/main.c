#include "dio.h"
#include <util/delay.h>

void Lcd_vidInit();
void Lcd_vidSendCommand(u8);
void Lcd_vidWriteCharacter(u8);

void main(void)  {
	Dio_vidSetPortDirection(DIO_PORTD,0b11111111);
	Dio_vidSetPortDirection(DIO_PORTA,0b00000111);
	Dio_vidSetPortValue(DIO_PORTD,0b00000000);
	Lcd_vidInit();
	while(1) {
		char name = 'M';
		for (u8 i = 0; i < 16; i++) {
			Lcd_vidWriteCharacter(name);	
			Lcd_vidSendCommand(0b00010100);
		}
	}
}

void Lcd_vidInit(void) {
	Lcd_vidSendCommand(0b00000001);
	Lcd_vidSendCommand(0b00000010);
	Lcd_vidSendCommand(0b00000110);
	Lcd_vidSendCommand(0b00001101);
	Lcd_vidSendCommand(0b00010000);
}

void Lcd_vidSendCommand(u8 u8Command) {
	Dio_vidSetPinValue(DIO_PORTA,0,0);
	Dio_vidSetPinValue(DIO_PORTA,1,0);
	Dio_vidSetPinValue(DIO_PORTA,2,1);
	_delay_ms(50);
	Dio_vidSetPortValue(DIO_PORTD,u8Command);
	Dio_vidSetPinValue(DIO_PORTA,2,0);
	_delay_ms(50);
	Dio_vidSetPinValue(DIO_PORTA,2,1);
}
void Lcd_vidWriteCharacter(u8 u8DataCpy) {
	Dio_vidSetPinValue(DIO_PORTA,0,1);
	Dio_vidSetPinValue(DIO_PORTA,1,0);
	Dio_vidSetPinValue(DIO_PORTA,2,1);
	Dio_vidSetPortValue(DIO_PORTD,u8DataCpy);
	Dio_vidSetPinValue(DIO_PORTA,2,0);
	_delay_ms(50);
}
