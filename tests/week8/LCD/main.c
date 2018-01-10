#include "dio.h"
#include <util/delay.h>

void Lcd_vidInit();
void Lcd_vidSendCommand(u8);
void Lcd_vidWriteCharacter(u8);

void Lcd_insertMessage(s8 *);
u8 u8Shift = 0b00010100;
u8 flag = 0xff;
void main(void)  {
	Dio_vidSetPortDirection(DIO_PORTD,0b11111111);
	Dio_vidSetPortDirection(DIO_PORTA,0b00000111);
	Dio_vidSetPortValue(DIO_PORTD,0b00000000);
	Lcd_vidInit();
	s8 * u8name = "Mohamed";
	Lcd_insertMessage(u8name);

	while(1) {
		for(s8 i = 0; i < 9; i++) {
			if (flag == 0xFF) {
				Lcd_vidSendCommand(0x1c);
				_delay_ms(500);
			}
			else {
				Lcd_vidSendCommand(0x18);
				_delay_ms(500);
			}
		}
		flag = ~(flag);
	}
}

void Lcd_vidInit(void) {
	Lcd_vidSendCommand(0b00000001); /*Clear screen*/
	Lcd_vidSendCommand(0b00000010); /*Move to home*/
	Lcd_vidSendCommand(0b00000110); /*Set entry mode*/
	Lcd_vidSendCommand(0b00001100); /*Display On/Off control*/
	Lcd_vidSendCommand(0b00110000); /*Function Set*/
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
	_delay_ms(500);
}

void Lcd_insertMessage(s8 * s8Message) {
	for (s8 i = 0; i < 7; i++) {
		Lcd_vidWriteCharacter(*s8Message++);
	}
	_delay_ms(1000);
}
