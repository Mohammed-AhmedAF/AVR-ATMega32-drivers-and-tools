#include "Std_Types.h"
#include "Macros.h"
#include "LCD_interface.h"
#include "Keypad_interface.h"
#include "Services_interface.h"
#include "Password_interface.h"
#include "EEPROM_interface.h"

u8 i;
u8 id[9];
u8 pass[9];
u8 passR[9];
u8 u8Byte;
u8 flag = 0;
u8 u8IDSize = 0;
u8 u8PasswordSize;
u8 u8PasswordStart;

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
	u8PasswordStart = u8IDSize-1;
	LCD_vidSendCommand(LCD_CLEAR_SCREEN);
	for (i = 0; i < u8IDSize; i++) {
		c = id[i];
		flag = EEPROM_u8WriteByte(i,c);
		if (flag == 1) {
			LCD_vidWriteCharacter('!');
		}
		else {
			LCD_vidWriteCharacter('/');
		}
	}
	LCD_vidWriteString("ID saved");
}

void Password_vidReenterPassword(void) {
	LCD_vidSendCommand(LCD_CLEAR_SCREEN);
	LCD_vidWriteString("Reenter pass: ");
	LCD_vidGoToXY(0,2);
	i = 0;
	do {
		Services_vidWriteCharacter();
		if(u8keyPressed == '#') {
			break;
		}
		else {
			passR[i] = u8keyPressed;
			i++;
		}
	}while(1);
}

void Password_vidSavePassword(u8 u8PasswordStart,u8 u8PasswordSize) {
	u8 flag;
	u8 c;
	u8 u8PasswordIndex = u8PasswordStart;
	LCD_vidGoToXY(0,2);
	for (i = 0; i < u8PasswordSize; i++) {
		c = pass[i];
		flag = EEPROM_u8WriteByte(u8PasswordIndex++,c);
	}

	LCD_vidWriteString("Password saved");

}

void Password_vidAskPassword(void) {
	LCD_vidSendCommand(LCD_CLEAR_SCREEN);
	LCD_vidWriteString("Pass: ");
	LCD_vidGoToXY(0,2);
	i = 0;
	do {
		Services_vidWriteCharacter();
		if (u8keyPressed == '#') {
			break;
		}
		else {
			pass[i] = u8keyPressed;
			i++;
			u8PasswordSize++;
		}

	}while(1);

}

u8 Password_vidCheckPasswordMatch(u8 u8PasswordSizeCpy) {
	for (i = 0; i < u8PasswordSizeCpy; i++) {
		if (pass[i] != passR[i]) {
			LCD_vidSendCommand(LCD_CLEAR_SCREEN);
			LCD_vidWriteString("No match!");
			return 0;
		}	
		else if(i == (u8PasswordSizeCpy-1)) {
			return 1;
		}
	}
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

void Password_vidReadPassword(u8 u8PasswordStartCpy, u8 u8PasswordSizeCpy) {
	u8 u8PasswordIndex;
	u8PasswordIndex = u8PasswordStartCpy;
	LCD_vidSendCommand(LCD_CLEAR_SCREEN);
	LCD_vidWriteString("Password is: ");
	for (i = 0; i < u8PasswordSizeCpy; i++) {
		flag = EEPROM_u8ReadByte(u8PasswordIndex,&u8Byte);		
		u8PasswordIndex++;
		if (flag == 1) {
			LCD_vidWriteCharacter(u8Byte);
		}
		else {
			LCD_vidWriteCharacter(u8PasswordIndex+'0');
		}
	}
}
