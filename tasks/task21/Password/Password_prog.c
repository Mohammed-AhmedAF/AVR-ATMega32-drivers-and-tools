/* User should enter a 5 digit ID
*/

#include "Std_Types.h"
#include "Macros.h"
#include "Password_interface.h"
#include "LCD_interface.h"
#include "DIO_interface.h"
#include "Services_interface.h"
#include <util/delay.h>

u8 u8currentUser;
u8 u8foundFlag;
u8 u8success;
void Password_vidSavePassword(u8 * u8idCpy, u8 * u8passwordCpy,u8 u8idSize,u8 u8passwordSize) {
	u8 i = 0;
	/*saving id*/
	db[u8userIndex].u8idSize = u8idSize;
	db[u8userIndex].u8passwordSize = u8passwordSize;
	for (i = 0; i < u8idSize; i++) {
		db[u8userIndex].u8id[i] = *u8idCpy++;
	}
	/*saving password*/
	for (i = 0; i < u8passwordSize; i++) {
		db[u8userIndex].u8password[i] = *u8passwordCpy++;
	}
	u8userIndex++;
	u8saveFlag = 1;
}


/*The function vidAskID will continue to ask for ID, if
 * the provided ID already existed in the database.
 */
void Password_vidAskID(void) {
	LCD_vidSendCommand(LCD_CLEAR_SCREEN);
	LCD_vidWriteString(ID);
	i = 0;
	do {
		Services_vidWriteCharacter();
		if (u8keyPressed != '#') {
			u8id[i] = u8keyPressed;
			i++;
		}
	}while(u8keyPressed != '#');
	u8idSize = i;
}

void Password_vidAskPassword(void) {
	LCD_vidGoToXY(0,2);
	LCD_vidWriteString(PASSWORD);
	i = 0;
	do {
		Services_vidWriteCharacter();
		if (u8keyPressed != '#') {
			u8password[i] = u8keyPressed;
			i++;
		}
	}while(u8keyPressed != '#');
	u8passwordSize = i;
}

void Password_vidAskReenter(void) {
	LCD_vidSendCommand(LCD_CLEAR_SCREEN);
	LCD_vidWriteString(RE_PASSWORD);
	LCD_vidGoToXY(0,2);
	i = 0;
	do {
		Services_vidWriteCharacter();
		if(u8keyPressed != '#') {
			u8passwordTemp[i] = u8keyPressed;
			i++;
		}
	}while(u8keyPressed != '#');
}

void Password_vidViewRecord(void) {
	u8 x;
	for (x = 0; x < u8userIndex; x++) {
		LCD_vidSendCommand(LCD_CLEAR_SCREEN);
		/*Viewing ID*/
		LCD_vidWriteString(ID);
		for (i = 0; i < db[x].u8idSize; i++) {
			LCD_vidWriteCharacter(db[x].u8id[i]);
		}
		/*Viewing password*/
		LCD_vidGoToXY(0,2);
		LCD_vidWriteString(PASSWORD);
		for (i = 0; i < db[x].u8passwordSize; i++) {
			LCD_vidWriteCharacter(db[x].u8password[i]);
		}
		_delay_ms(1000);
	}
}

void Password_vidCheckMatch(void) {
	for (i = 0; i < 5; i++) {
		if (u8password[i] != u8passwordTemp[i]) {
			LCD_vidSendCommand(LCD_CLEAR_SCREEN);
			LCD_vidWriteString(NO_MATCH);
			_delay_ms(500);
			u8saveFlag = 0;
			break;
		}
		else if(i==4) {
			LCD_vidSendCommand(LCD_CLEAR_SCREEN);
			LCD_vidWriteString(PASSWORD_SAVED);
			_delay_ms(500);
			Password_vidSavePassword(u8id,u8passwordTemp,u8idSize,u8passwordSize);
			break;
		}
	}
}

void Password_vidCheckID(u8 u8askFlagCpy) {
	if(u8askFlagCpy == 1) {
		Password_vidAskID();
	}
	u8 x;
	u8foundFlag = 0;
	for (x = 0; x < u8userIndex; x++) {
		for (i = 0; i < 5; i++) {
			if(db[x].u8id[i] != u8id[i]) {
				break;
			}
			else if (i == 4) {
				LCD_vidSendCommand(LCD_CLEAR_SCREEN);
				LCD_vidGoToXY(0,2);
				LCD_vidWriteString("ID already here");
				u8currentUser = x;
				u8foundFlag = 1;
				_delay_ms(1000);
				LCD_vidSendCommand(LCD_CLEAR_SCREEN);
			}
		}
	}
	if (u8foundFlag == 0) {
		if (u8askFlagCpy == 1) {
			LCD_vidGoToXY(0,2);
			LCD_vidWriteString("ID not found!");
			_delay_ms(2000);
		}		
	}
}

void Password_vidCheckPassword(u8 u8countCpy) {
	LCD_vidSendCommand(LCD_CLEAR_SCREEN);
	LCD_vidGoToXY(0,1);
	u8countCpy += 0x30;
	LCD_vidWriteCharacter(u8countCpy);
	Password_vidAskPassword();
	for (i = 0; i < 5; i++) {
		if (db[u8currentUser].u8password[i] != u8password[i]) {
			LCD_vidSendCommand(LCD_CLEAR_SCREEN);
			LCD_vidWriteString("Wrong password");
			u8success = 0;
			_delay_ms(800);
			break;
		}
		else if (i == 4) {
			LCD_vidSendCommand(LCD_CLEAR_SCREEN);
			LCD_vidWriteString("Welcome");
			u8success = 1;
			_delay_ms(1000);
		}
	}
}
