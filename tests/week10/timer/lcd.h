#ifndef _LCD_H
#define _LCD_H

#define LCD_CLEAR_SCREEN 0b00000001
#define LCD_RETURN_HOME 0b00000010
#include "Std_Types.h"

void Lcd_vidInit(void);
void Lcd_vidSendCommand(u8);
void Lcd_vidWriteCharacter(u8);
void Lcd_vidGoToXY(s8,s8);
void Lcd_vidInsertMessage(s8 *);
void Lcd_vidBlinkMessage(s8 *, s8);

#endif
