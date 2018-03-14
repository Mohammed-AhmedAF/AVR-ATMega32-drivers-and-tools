#include "Std_Types.h"
#include "Macros.h"
#include "LCD_interface.h"
#include "Keypad_interface.h"
#include "Services_interface.h"
#include "Password_interface.h"
#include "EEPROM_interface.h"

u8 i;
u8 id[9];
u8 u8Byte;
u8 flag = 0;
u8 u8IDSize = 0;;
void Password_vidAskID(void) {
	LCD_vidSendCommand(LCD_CLEAR_SCREEN);
	LCD_vidWriteString("ID: ");
	LCD_vidGoToXY(0,2);
	do {
		Services_vidWriteCharacter();
		if (u8keyPressed == '#') {
			break;
		}
		else {
			id[i] = u8keyPressed;
			i++;
			u8IDSize++;
		}
	
	}while(1);
}

void Password_vidShowID(u8 u8IDSize) {
	LCD_vidSendCommand(LCD_CLEAR_SCREEN);
	LCD_vidWriteString("ID: ");
	i = 0;
	while(i < u8IDSize) {
		LCD_vidWriteCharacter(id[i]);
		i++;
	}
}

void Password_vidSaveID(u8 u8IDSize) {
	u8 c;
	u8 flag;
	for (i = 0; i < u8IDSize; i++) {
		c = id[i];
		flag = EEPROM_u8WriteByte(i,c);	
		if (flag == 1) {
			LCD_vidWriteCharacter('$');
		}
		else {
			LCD_vidWriteCharacter('!');
		}
	}
	LCD_vidGoToXY(0,2);
	LCD_vidWriteString("ID saved!");
}

void Password_vidRetreiveID(u8 u8IDSize) {
	LCD_vidSendCommand(LCD_CLEAR_SCREEN);
	LCD_vidWriteString("ID: ");
	LCD_vidGoToXY(0,2);
	for (i = 0; i < u8IDSize; i++) {
		flag = EEPROM_u8ReadByte(i,&u8Byte);
		if (flag ==1) {
			LCD_vidWriteCharacter(u8Byte);
		}
		else {
			LCD_vidWriteCharacter('?');
		}
	}
}
