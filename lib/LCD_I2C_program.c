#include "Macros.h"
#include "Std_Types.h"
#include "DIO_interface.h"
#include "PCF8574_interface.h"
#include "LCD_I2C_interface.h"
#include <util/delay.h>

void LCD_I2C_vidInit(void)
{
	LCD_I2C_vidSendCommand(0x02);
	LCD_I2C_vidSendCommand(0x28);
	LCD_I2C_vidSendCommand(LCD_I2C_CLEAR_SCREEN);
	LCD_I2C_vidSendCommand(LCD_I2C_RETURN_HOME);
	LCD_I2C_vidSendCommand(LCD_I2C_SET_ENTRY_MODE|LCD_I2C_MOVE_CURSOR_RIGHT);
	LCD_I2C_vidSendCommand(LCD_I2C_DISPLAY_ON);
}

void LCD_I2C_vidSendCommand(u8 u8Command)
{
	u8 u8Command_up = u8Command & 0xF0;
	
	PCF8574_vidWriteByte(u8Command_up);
	/*RS set to low*/
	PCF8574_vidWriteByte(u8Command_up|0x00);
	
	/*En set to high*/
	PCF8574_vidWriteByte(u8Command_up|0x04);
	_delay_us(2);
	/*En set to low*/
	PCF8574_vidWriteByte(u8Command_up|0x00);
	_delay_us(200);
	
	/*Sending low 4 bit*/
	u8 u8Command_low = (u8Command  & 0x0F)<<4;
	
	/*Toggling En*/
	PCF8574_vidWriteByte(u8Command_low|0x04);
	_delay_us(2);
	PCF8574_vidWriteByte(u8Command_low|0x00);
	_delay_ms(2);
	
}

void LCD_I2C_vidSendCharacter(u8 u8Char)
{
	u8 u8Char_up = u8Char & 0xF0;
	
	PCF8574_vidWriteByte(u8Char_up);
	/*RS set to low*/
	PCF8574_vidWriteByte(u8Char_up|0x01);
	
	/*En set to high*/
	PCF8574_vidWriteByte(u8Char_up|0x05);
	_delay_us(2);
	/*En set to low*/
	PCF8574_vidWriteByte(u8Char_up|0x01);
	_delay_us(200);
	
	/*Sending low 4 bit*/
	u8 u8Char_low = (u8Char  & 0x0F)<<4;
	
	/*Toggling En*/
	PCF8574_vidWriteByte(u8Char_low|0x05);
	_delay_us(2);
	PCF8574_vidWriteByte(u8Char_low|0x01);
	_delay_ms(2);
}

void LCD_I2C_vidSendString(u8 * ptu8String)
{
	do {
		LCD_I2C_vidSendCharacter(*ptu8String);
		(ptu8String++);
	}while(*ptu8String != '\0');
}

void LCD_I2C_vidSendNumber(u16 u16NumberCpy)
{
	if(u16NumberCpy < 10) {
		LCD_I2C_vidSendCharacter('0');
		LCD_I2C_vidSendCharacter(u16NumberCpy+'0');
	}
	else {
		if (u16NumberCpy < 100) {
			LCD_I2C_vidSendCharacter(u16NumberCpy/10+'0');
			LCD_I2C_vidSendCharacter(u16NumberCpy%10+'0');
		}
		else if (u16NumberCpy < 1000) {
			LCD_I2C_vidSendCharacter((u16NumberCpy/100)+'0');
			LCD_I2C_vidSendCharacter((u16NumberCpy%100)/10+'0');
			LCD_I2C_vidSendCharacter((u16NumberCpy%100)%10+'0');
		}
		else if (u16NumberCpy < 10000)
		{
			LCD_I2C_vidSendCharacter((u16NumberCpy/1000)+'0');
			LCD_I2C_vidSendCharacter((u16NumberCpy%1000)/100+'0');
			LCD_I2C_vidSendCharacter((u16NumberCpy%100)/10+'0');
			LCD_I2C_vidSendCharacter((u16NumberCpy%100)%10+'0');
		}
	}
}

void LCD_I2C_vidGoToXY(u8 u8xCpy, u8 u8yCpy) {
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
	LCD_I2C_vidSendCommand(u8address | 0x80);
}