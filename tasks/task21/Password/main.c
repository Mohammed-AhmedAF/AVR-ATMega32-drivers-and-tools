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
#include <util/delay.h>

extern u8 u8keyPressed;
u8 * message;
void main(void) {
	LCD_vidInit();
	KEYPAD_vidInit();

	while(1) {
		message = "Enter ID: ";
		LCD_vidWriteString(message);
		LCD_vidGoToXY(0,2);
		do {
			Services_vidWriteCharacter();
		}while(u8keyPressed != '=');
	}

}
