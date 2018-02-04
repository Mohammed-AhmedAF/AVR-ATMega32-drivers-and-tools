#include "Std_Types.h"
#include "DIO_interface.h"
#include "lcd.h"
#include "Macros.h"
#include <util/delay.h>


void LCD_vidInit(void) {
	DIO_vidSetPinDirection(LCD_DATA_PORT,LCD_D0,1);
	DIO_vidSetPinDirection(LCD_DATA_PORT,LCD_D1,1);
	DIO_vidSetPinDirection(LCD_DATA_PORT,LCD_D2,1);
	DIO_vidSetPinDirection(LCD_DATA_PORT,LCD_D3,1);
	DIO_vidSetPinDirection(LCD_DATA_PORT,LCD_D4,1);
	DIO_vidSetPinDirection(LCD_DATA_PORT,LCD_D5,1);
	DIO_vidSetPinDirection(LCD_DATA_PORT,LCD_D6,1);
	DIO_vidSetPinDirection(LCD_DATA_PORT,LCD_D7,1);


	DIO_vidSetPinDirection(LCD_CTRL_PORT,LCD_E,1);
	DIO_vidSetPinDirection(LCD_CTRL_PORT,LCD_RS,1);
	DIO_vidSetPinDirection(LCD_CTRL_PORT,LCD_RW,1);

	LCD_vidSendCommand(LCD_8MODE_2L);
	_delay_ms(2);
	LCD_vidSendCommand(LCD_ON_NOCURSOR);
	_delay_ms(2);
	LCD_vidSendCommand(LCD_CLEAR_SCREEN);
}

void LCD_vidSendCommand(u8 commandCpy) {
	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_RS,STD_LOW);
	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_RW,STD_LOW);

	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D0,GET_BIT(commandCpy,0));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D1,GET_BIT(commandCpy,1));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D2,GET_BIT(commandCpy,2));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D3,GET_BIT(commandCpy,3));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D4,GET_BIT(commandCpy,4));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D5,GET_BIT(commandCpy,5));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D6,GET_BIT(commandCpy,6));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D7,GET_BIT(commandCpy,7));

	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_E,1);
	_delay_ms(2);
	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_E,0);
}

void LCD_vidWriteChar(u8 charCpy) {
	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_RS,STD_HIGH);
	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_RW,STD_LOW);

	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D0,GET_BIT(charCpy,0));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D1,GET_BIT(charCpy,1));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D2,GET_BIT(charCpy,2));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D3,GET_BIT(charCpy,3));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D4,GET_BIT(charCpy,4));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D5,GET_BIT(charCpy,5));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D6,GET_BIT(charCpy,6));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D7,GET_BIT(charCpy,7));

	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_E,1);
	_delay_ms(2);
	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_E,0);
}
