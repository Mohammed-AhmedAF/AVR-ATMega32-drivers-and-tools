#ifndef _LCD_H
define LCD_H

#define LCD_CLEAR_SCREEN 0b00000001
#define LCD_RETURN_HOME 0b00000010

void Lcd_vidSendCommand(u8);
void Lcd_vidWriteCharacter(u8);
void Lcd_vidGoToXY(s8,s8);
void Lcd_vidInsertMessage(s8 *);

#endif
