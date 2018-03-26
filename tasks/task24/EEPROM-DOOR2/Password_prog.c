#include "Std_Types.h"
#include "Macros.h"
#include "LCD_interface.h"
#include "DIO_interface.h"
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

u8 Password_u8CheckSaveFlag(void) {
	EEPROM_u8ReadByte(PASSWORD_SAVED_PASSWORD_FLAG_LOCATION,&u8Byte);
	if (u8Byte == PASSWORD_SAVED_FLAG) {
		return PASSWORD_SAVED_FLAG;
	}
	else {
		return PASSWORD_UNSAVED_FLAG;
	}
}

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

u8 Password_u8CheckID(void) {
	LCD_vidSendCommand(LCD_CLEAR_SCREEN);
	LCD_vidWriteString("ID: ");

	EEPROM_u8ReadByte(PASSWORD_ID_SIZE_LOCATION,&u8Byte);
	u8IDSize = u8Byte;
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
	if (u8AskedIDSize != u8IDSize) { //When ID doesn't have the same length as in EEPROM
		LCD_vidSendCommand(LCD_CLEAR_SCREEN);
		LCD_vidWriteString("You're not registerd"); 
		return 0;
	}
	else {
		for (i = 0; i < u8IDSize; i++) {
			EEPROM_u8ReadByte(i,&u8Byte);
			if (id[i] != u8Byte) { //When ID is not the same as in EEPROM
				return 0;
			}		
			else if (i == u8IDSize-1) { //This means ID is the same as in EEPROM
				LCD_vidGoToXY(0,2);
				return 1;
			}
		}
	}
}

u8 Password_u8CheckBlock(void) {
	flag = EEPROM_u8ReadByte(PASSWORD_BLOCKED_FLAG_LOCATION,&u8Byte);
	if (flag == 1) {
		if(u8Byte == PASSWORD_BLOCKED) {
			LCD_vidWriteCharacter('B');
			_delay_ms(2000);
			return PASSWORD_BLOCKED;
		}
		else {
			LCD_vidWriteCharacter('N');
			_delay_ms(2000);
			return PASSWORD_NOT_BLOCKED;
		}
	}
}

void Password_vidBlockUser(void) {
	LCD_vidSendCommand(LCD_CLEAR_SCREEN);
	flag = EEPROM_u8WriteByte(PASSWORD_BLOCKED_FLAG_LOCATION,PASSWORD_BLOCKED);
	if (flag == 1) {
		LCD_vidWriteString("BLock flag set");
		_delay_ms(1000);
	}
	else {
		LCD_vidWriteString("Flag not set");
		_delay_ms(2000);
	}
}

u8 Password_u8CheckPassword(void) {
	LCD_vidSendCommand(LCD_CLEAR_SCREEN);
	//Getting password size from EEPROM
	flag =	EEPROM_u8ReadByte(PASSWORD_PASSWORD_SIZE_LOCATION,&u8Byte);
	if (flag == 1) {
		u8PasswordSize = u8Byte;
	}
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
	u8PasswordStart = u8IDSize+1;
	LCD_vidSendCommand(LCD_CLEAR_SCREEN);
	for (i = 0; i < u8IDSize; i++) {
		flag = EEPROM_u8WriteByte(i,id[i]);
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
	if (flag == 1) {

		Password_vidSaveSize();

		flag = EEPROM_u8WriteByte(PASSWORD_SAVED_PASSWORD_FLAG_LOCATION,PASSWORD_SAVED_FLAG);
		if (flag == 0) {
			LCD_vidWriteCharacter('S');
		}
		LCD_vidWriteString("Saved");
	}
}

void Password_vidSaveSize(void) {
	flag = EEPROM_u8WriteByte(PASSWORD_ID_SIZE_LOCATION,u8IDSize);
	if (flag == 0) {
		LCD_vidWriteCharacter('I');
	}
	_delay_ms(500);
	flag =	EEPROM_u8WriteByte(PASSWORD_PASSWORD_SIZE_LOCATION,u8PasswordSize);
	if (flag == 0) {
		LCD_vidWriteCharacter('P');
	}
	_delay_ms(500);
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
	LCD_vidWriteString("ID is  ");
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
