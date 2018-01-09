#include "dio.h"

void Lcd_vidInit();
void Lcd_vidSendCommand();
void Lcd_vidWriteCharacter();

void main(void)  {
	Dio_vidSetPortDirection(DIO_PORTD,0b11111111);
	Dio_vidSetPortDirection(DIO_PORTA,0b00000111);
	Lcd_vidInit();
}

void Lcd_vidInit() {
	Lcd_vidSendCommand(0b00000001);
	Lcd_vidSendCommand(0b00000010);
	Lcd_vidSendCommand(0b00000110);
	Lcd_vidSendCommand(0b00001110);
	/*Function Set*/
	Lcd_vidSendCommand(0b00111000);
}

void Lcd_vidSendCommand(u8 u8Command) {
	Dio_vidSetPortValue(DIO_PORTA,0b00000100);
	/*Loading command on databus*/	
	Dio_vidSetPortValue(DIO_PORTD,u8Command);
	Dio_vidSetPortValue(DIO_PORTA,0b00000000);
	_delay_ms(5);
	/*Setting E to High*/
	Dio_vidSetPortValue(DIO_PORTA,0b00000100);
}
void Lcd_vidWriteCharacter() {

}
