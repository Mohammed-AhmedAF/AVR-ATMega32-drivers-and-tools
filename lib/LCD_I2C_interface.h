#ifndef _LCD_I2C_INTERFACE_H
#define _LCD_I2C_INTERFACE_H

void LCD_I2C_vidInit(void);
void LCD_I2C_vidSendCommand(u8 u8Command);
void LCD_I2C_vidSendCharacter(u8 u8Char);
void LCD_I2C_vidSendString(u8 * ptu8String);
void LCD_I2C_vidSendNumber(u16 u16NumberCpy);
void LCD_I2C_vidGoToXY(u8 u8xCpy, u8 u8yCpy);

#define LCD_I2C_CLEAR_SCREEN 0b00000001
#define LCD_I2C_RETURN_HOME 0b00000010
#define LCD_I2C_DISPLAY_ON 0x0C
#define LCD_I2C_DISPLAY_OFF 0x08

#define LCD_I2C_CURSOR_ON 0x0A
#define LCD_I2C_CURSOR_OFF 0x08
#define LCD_I2C_CURSOR_BLINK_ON 0x09
#define LCD_I2C_CURSOR_BLINK_OFF 0x08
#define LCD_I2C_FUNCTION_SET 0x20
#define LCD_I2C_8BIT 0x10
#define LCD_I2C_4BIT 0x00
#define LCD_I2C_4LINES 0x08
#define LCD_I2C_SET_ENTRY_MODE 0x04

#define LCD_I2C_MOVE_CURSOR_LEFT 0x00
#define LCD_I2C_MOVE_CURSOR_RIGHT 0x02

#endif