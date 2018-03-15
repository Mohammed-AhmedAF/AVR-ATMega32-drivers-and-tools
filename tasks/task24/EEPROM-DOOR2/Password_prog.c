#include "Std_Types.h"
#include "Macros.h"
#include "LCD_interface.h"
#include "Keypad_interface.h"
#include "Services_interface.h"
#include "Password_interface.h"
#include "EEPROM_interface.h"
#include <util/delay.h>
u8 i;
u8 id[9];
u8 pass[9];
u8 passR[9];
u8 u8Byte;
u8 flag = 0;
u8 u8IDSize = 0;
u8 u8PasswordSize = 0;
u8 u8PasswordStart = 0;
u8 u8PasswordIndex = 0;
u8 u8AskedIDSize = 0;
u8 u8AskedPassSize = 0;

void Password_vidEnterID(void) {
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

void Password_vidCheckID(void) {
	LCD_vidSendCommand(LCD_CLEAR_SCREEN);
	LCD_vidWriteString("ID: ");
	i = 0;
	u8AskedIDSize = 0;
	do {
		Services_vidWriteCharacter();
		if (u8keyPressed == '#') {
			break;
		}
		else {
			id[i] = u8keyPressed;
			i++;
			u8AskedIDSize++;
		}
	}while(1);
	if (u8AskedIDSize != u8IDSize) {
		LCD_vidSendCommand(LCD_CLEAR_SCREEN);
		LCD_vidWriteString("You're not registerd");
	}
	else {
		for (i = 0; i < u8IDSize; i++) {
			EEPROM_u8ReadByte(i,&u8Byte);
			if (id[i] != u8Byte) {
				Password_vidCheckID();
			}		
			else if (i == u8IDSize-1) {
				LCD_vidGoToXY(0,2);
				LCD_vidWriteCharacter('.');
			}
		}
	}
}

u8 Password_vidCheckPassword(void) {
	LCD_vidSendCommand(LCD_CLEAR_SCREEN);
	i = 0;
	u8AskedPassSize = 0;
	LCD_vidWriteString("Pass: ");
	do {
		Services_vidWriteCharacter();
		if (u8keyPressed == '#') {
			break;
		}
		else {
			pass[i] = u8keyPressed;
			i++;
			u8AskedPassSize++;
		}
	}while(1);
	if (u8AskedPassSize != u8PasswordSize) {
		return 0;
	}
	else {
		u8PasswordStart = u8IDSize+1;
		for (i = 0; i < u8PasswordSize; i++) {
			EEPROM_u8ReadByte(u8PasswordStart,&u8Byte);
			u8PasswordStart++;
			if (pass[i] != u8Byte) {
				return 0;
			}		
			else if (i == u8PasswordSize-1) {
				return 1;
			}
		}
	}
}

void Password_vidSave(u8 u8IDSize) {
	u8 c;
	u8 flag;
	u8PasswordStart = u8IDSize+1;
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
	for(i = 0; i <u8PasswordSize;i++) {
		flag = EEPROM_u8WriteByte(u8PasswordStart,pass[i]);
		u8PasswordStart++;
		if (flag == 1) {
			LCD_vidWriteCharacter('!');
		}
		else {
			LCD_vidWriteCharacter('/');
		}
	}
	LCD_vidWriteString("Saved");
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
	u8PasswordIndex = u8PasswordStart;
	LCD_vidGoToXY(0,2);
	for (i = 0; i < u8PasswordSize; i++) {
		flag = EEPROM_u8WriteByte(u8PasswordIndex,passR[i]);
		u8PasswordIndex++;
		if (flag == 1) {
			continue;
		}
		else {
			LCD_vidWriteCharacter(i+'0');
		}

	}

	LCD_vidWriteString("Password saved");

}

void Password_vidEnterPassword(void) {
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
	u8PasswordIndex = u8PasswordStartCpy;
	LCD_vidSendCommand(LCD_CLEAR_SCREEN);
	LCD_vidWriteString("Password is: ");
	for (i = 0; i < u8PasswordSizeCpy; i++) {
		flag = EEPROM_u8ReadByte(u8PasswordIndex++,&u8Byte);		
		if (flag == 1) {
			LCD_vidWriteCharacter(u8Byte);
		}
		else {
			LCD_vidWriteCharacter('?');
		}
	}
}
