#include "Std_Types.h"
#include "lcd.h"
#include "dio.h"
#include <util/delay.h>

void Lcd_vidInit(void) {
	Lcd_vidSendCommand(0b00000001); /*Clear screen*/
	Lcd_vidSendCommand(0b00000010); /*Move to home*/
	Lcd_vidSendCommand(0b00000110); /*Set entry mode*/
	Lcd_vidSendCommand(0b00001100); /*Display On/Off control*/
	Lcd_vidSendCommand(0b00111000); /*Function Set*/
}

void Lcd_vidGoToXY(s8 s8xCpy, s8 s8yCpy) {
	Lcd_vidSendCommand(0b00000010);
	if (s8yCpy == 1) {
		for (s8 i = 0; i < s8xCpy;i++) {
			Lcd_vidSendCommand(0b00010100);
		}	
	}
	else {
		for (s8 i = 0; i < s8xCpy+40; i++) {
			Lcd_vidSendCommand(0b00010100);
		}
	}
}

void Lcd_vidSendCommand(u8 u8Command) {
	Dio_vidSetPinValue(DIO_PORTA,0,0);
	Dio_vidSetPinValue(DIO_PORTA,1,0);
	Dio_vidSetPinValue(DIO_PORTA,2,1);
	_delay_ms(3);
	Dio_vidSetPortValue(DIO_PORTD,u8Command);
	Dio_vidSetPinValue(DIO_PORTA,2,0);
	_delay_ms(3);
	Dio_vidSetPinValue(DIO_PORTA,2,1);
}
void Lcd_vidWriteCharacter(u8 u8DataCpy) {
	Dio_vidSetPinValue(DIO_PORTA,0,1);
	Dio_vidSetPinValue(DIO_PORTA,1,0);
	Dio_vidSetPinValue(DIO_PORTA,2,1);
	Dio_vidSetPortValue(DIO_PORTD,u8DataCpy);
	Dio_vidSetPinValue(DIO_PORTA,2,0);
}

void Lcd_vidInsertMessage(s8 * s8Message) {
	for (s8 i = 0; i < 6; i++) {
		Lcd_vidWriteCharacter(*s8Message++);
	}
	_delay_ms(1000);
	Lcd_vidSendCommand(0b00000001);
}


