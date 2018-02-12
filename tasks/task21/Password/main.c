/*
 * Project: Password
 * Developer: Mohamed Ahmed
 * Date: 11 Feb 2018
 */


#include "Macros.h"
#include "Std_Types.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KEYPAD_interface.h"
#include "Services_interface.h"
#include "Password_interface.h"
#include <util/delay.h>

extern u8 u8keyPressed;
u8 * message;
u8 i = 0;

void main(void) {
	LCD_vidInit();
	KEYPAD_vidInit();

	while(1) {
		LCD_vidSendCommand(LCD_CLEAR_SCREEN);
		message = "ID: ";
		LCD_vidWriteString(message);
		do {
			Services_vidWriteCharacter();
			u8id[i] = u8keyPressed;
			i++;
		}while(u8keyPressed != '#');

		message = "Password: ";
		LCD_vidGoToXY(0,2);
		LCD_vidWriteString(message);
		i = 0;
		do {
			Services_vidWriteCharacter();
			u8password[i] = u8keyPressed;
			i++;
		}while(u8keyPressed != '#');
		LCD_vidSendCommand(LCD_CLEAR_SCREEN);
		message = "Reenter password: ";
		LCD_vidWriteString(message);
		LCD_vidGoToXY(0,2);
		i = 0;
		do {
			Services_vidWriteCharacter();
			u8passwordTemp[i] = u8keyPressed;
			i++;
		}while(u8keyPressed != '#');
		/*Check for password match*/
		for (i = 0; i < 5; i++) {
			if (u8password[i] != u8passwordTemp[i]) {
				LCD_vidSendCommand(LCD_CLEAR_SCREEN);
				message = "No match";
				LCD_vidWriteString(message);
				_delay_ms(500);
				break;
			}
			else if(i==4) {
				LCD_vidSendCommand(LCD_CLEAR_SCREEN);
				message = "Saving password";
				LCD_vidWriteString(message);
				_delay_ms(500);
				Password_vidSavePassword(u8id,u8passwordTemp);
				break;
			}
		}
	}

}