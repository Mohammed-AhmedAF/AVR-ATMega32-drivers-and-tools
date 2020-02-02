/* 
 * File: LCD_prog.c
 *  Author: Mohammed Ahmed Abd Al-Fattah
 */


/*
 * RS: Register Select, Data/Instruction select, driven
 * high for data, and low for instruction.
 *
 *
 */

#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include <util/delay.h>


void LCD_vidInit(void) {
	DIO_vidSetPinDirection(LCD_DATA_PORT,LCD_D0,DIO_OUTPUT);
	DIO_vidSetPinDirection(LCD_DATA_PORT,LCD_D1,DIO_OUTPUT);
	DIO_vidSetPinDirection(LCD_DATA_PORT,LCD_D2,DIO_OUTPUT);
	DIO_vidSetPinDirection(LCD_DATA_PORT,LCD_D3,DIO_OUTPUT);
	DIO_vidSetPinDirection(LCD_DATA_PORT,LCD_D4,DIO_OUTPUT);
	DIO_vidSetPinDirection(LCD_DATA_PORT,LCD_D5,DIO_OUTPUT);
	DIO_vidSetPinDirection(LCD_DATA_PORT,LCD_D6,DIO_OUTPUT);
	DIO_vidSetPinDirection(LCD_DATA_PORT,LCD_D7,DIO_OUTPUT);


	DIO_vidSetPinDirection(LCD_CTRL_PORT,LCD_E,DIO_OUTPUT);
	DIO_vidSetPinDirection(LCD_CTRL_PORT,LCD_RS,DIO_OUTPUT);
	DIO_vidSetPinDirection(LCD_CTRL_PORT,LCD_RW,DIO_OUTPUT);
	
	LCD_vidSendCommand(LCD_CLEAR_SCREEN); /*Clear screen*/
	LCD_vidSendCommand(LCD_RETURN_HOME); /*Move to home*/
	LCD_vidSendCommand(0b00000110); /*Set entry mode*/
	LCD_vidSendCommand(0b00001100); /*Display On/Off control*/
	LCD_vidSendCommand(0b00111000); /*Function Set*/

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

	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_E,STD_HIGH);
	_delay_ms(2);
	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_E,STD_LOW);
	_delay_ms(2);
	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_E,STD_HIGH);
	_delay_ms(2);
}

void LCD_vidWriteCharacter(u8 charCpy) {
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

	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_E,STD_HIGH);
	_delay_ms(2);
	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_E,STD_LOW);
	_delay_ms(2);
	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_E,STD_HIGH);
}

void LCD_vidWriteString(s8 * s8String) {	
	do {
		LCD_vidWriteCharacter(*s8String);
		(s8String++);
	}while(*s8String != '\0');
}

void LCD_vidWriteSizedString(s8 * s8String,u8 u8sizeCpy) {	
	u8 i = 0;
	do {
		LCD_vidWriteCharacter(*s8String);
		(s8String++);
		i++;
	}while(u8sizeCpy > i);
}

void LCD_vidBlinkString(s8 * s8stringCpy,u8 u8timesCpy) {
	u8 i = 0;
	s8 * s8string;
	s8string = s8stringCpy;
	do {
		_delay_ms(500);	
		while(*s8string != '\0') {
			LCD_vidWriteCharacter(*s8string);
			(s8string++);
		}
		_delay_ms(500);
		i++;
		LCD_vidSendCommand(LCD_CLEAR_SCREEN);
		s8string = s8stringCpy;
	}
	while (u8timesCpy > i);
}

void LCD_vidWriteNumber(u16 u16NumberCpy) {
	if(u16NumberCpy < 10) {
		LCD_vidWriteCharacter('0');
		LCD_vidWriteCharacter(u16NumberCpy+'0');
	}
	else {
		if (u16NumberCpy < 100) {
			LCD_vidWriteCharacter(u16NumberCpy/10+'0');
			LCD_vidWriteCharacter(u16NumberCpy%10+'0');
		}
		else if (u16NumberCpy < 1000) {
			LCD_vidWriteCharacter((u16NumberCpy/100)+'0');
			LCD_vidWriteCharacter((u16NumberCpy%100)/10+'0');
			LCD_vidWriteCharacter((u16NumberCpy%100)%10+'0');
		}
		else if (u16NumberCpy < 10000)
		{
			LCD_vidWriteCharacter((u16NumberCpy/1000)+'0');
			LCD_vidWriteCharacter((u16NumberCpy%1000)/100+'0');
			LCD_vidWriteCharacter((u16NumberCpy%100)/10+'0');
			LCD_vidWriteCharacter((u16NumberCpy%100)%10+'0');
		}
	}
}

void LCD_vidGoToXY(u8 u8xCpy, u8 u8yCpy) {
	#define LCD_SET_CURSOR_LOCATION 0x80
	u8 u8address = u8xCpy;
	switch(u8yCpy) {
		case 0:
			u8address = u8xCpy;
			break;
		case 1:
			u8address = u8xCpy+0xC0;
			break;
		case 2:
			u8address = u8xCpy+0x94;
			break;
		case 3:
			u8address = u8xCpy+0xD4;
			break;
	}
	LCD_vidSendCommand(u8address | 0x80);
}

#define SET_CURSOR_LOCATION
void LCD_vidCreateCustomChar(u8 * u8CharPtrCpy, u8 u8LocationCpy) {
	u8 i = 0;
	LCD_vidSendCommand(0x40+(u8LocationCpy*8)); /*Setting to CGRAM address8*/
	while (i != 8) {
		LCD_vidWriteCharacter(*u8CharPtrCpy++);
		i++;
	}
	LCD_vidWriteCharacter(0x00+u8LocationCpy);
}

void LCD_vidWriteCustomChar(u8 u8LocationCpy) {
	LCD_vidWriteCharacter(0x00+u8LocationCpy);
}

/*This function has been reedited to allow writing a character
 *on a specific row and a specific column.
 * */
void LCD_vidWriteInPlace(u8 u8xCpy,u8 u8yCpy, u8 u8CharCpy) {
	LCD_vidGoToXY(u8xCpy,u8yCpy);
	LCD_vidWriteCharacter(u8CharCpy);
}

void LCD_vidClearLine(u8 u8LineNumber)
{
	LCD_vidGoToXY(LCD_XPOS0,u8LineNumber);
	u8 u8xPos;
	for (u8xPos = 0; u8xPos < 20; u8xPos++)
	{
		LCD_vidWriteCharacter(' ');
	}
}
