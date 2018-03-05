/* User should enter a 5 digit ID
*/

#include "Std_Types.h"
#include "Macros.h"
#include "Password_interface.h"
#include "DIO_interface.h"
#include "UART_interface.h"
#include <util/delay.h>

u8 u8currentUser;
u8 u8foundFlag;
u8 u8success;
u8 u8keyPressed;
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
	UART_vidSendLine();
	UART_vidSendString(ID);
	i = 0;
	do {
		u8keyPressed = UART_u8ReceiveByte();
		UART_vidSendByte(u8keyPressed);
		if (u8keyPressed != '\r') {
			u8id[i] = u8keyPressed;
			i++;
		}
	}while(u8keyPressed != '\r');
	u8idSize = i;
}

void Password_vidAskPassword(void) {
	UART_vidSendLine();
	UART_vidSendString(PASSWORD);
	i = 0;
	do {
		u8keyPressed = UART_u8ReceiveByte();
		UART_vidSendByte(u8keyPressed);
		if (u8keyPressed != '\r') {
			u8password[i] = u8keyPressed;
			i++;
		}
	}while(u8keyPressed != '\r');
	u8passwordSize = i;
}

void Password_vidAskReenter(void) {
	UART_vidSendLine();
	UART_vidSendString(RE_PASSWORD);
	i = 0;
	do {
		u8keyPressed = UART_u8ReceiveByte();
		UART_vidSendByte(u8keyPressed);
		if(u8keyPressed != '\r') {
			u8passwordTemp[i] = u8keyPressed;
			i++;
		}
	}while(u8keyPressed != '\r');
}

void Password_vidCheckMatch(void) {
	for (i = 0; i < 5; i++) {
		if (u8password[i] != u8passwordTemp[i]) {
			UART_vidSendLine();
			UART_vidSendString(NO_MATCH);
			_delay_ms(500);
			u8saveFlag = 0;
			break;
		}
		else if(i==4) {
			UART_vidSendLine();
			UART_vidSendString(PASSWORD_SAVED);
			_delay_ms(500);
			Password_vidSavePassword(u8id,u8passwordTemp,u8idSize,u8passwordSize);
			break;
		}
	}
}

void Password_vidCheckID(u8 u8askFlagCpy) {
	UART_vidSendLine();
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
				UART_vidSendLine();
				UART_vidSendString("ID already here");
				u8currentUser = x;
				u8foundFlag = 1;
				_delay_ms(1000);
				UART_vidSendLine();
			}
		}
	}
	if (u8foundFlag == 0) {
		if (u8askFlagCpy == 1) {
			UART_vidSendLine();
			UART_vidSendString("ID not found!");
			_delay_ms(2000);
		}		
	}
}

void Password_vidCheckPassword(u8 u8countCpy) {
	Password_vidAskPassword();
	for (i = 0; i < 5; i++) {
		if (db[u8currentUser].u8password[i] != u8password[i]) {
			UART_vidSendString("Wrong password");
			u8success = 0;
			_delay_ms(800);
			break;
		}
		else if (i == 4) {
			UART_vidSendLine();
			UART_vidSendString("Welcome");
			u8success = 1;
			_delay_ms(1000);

		}
	}
}
