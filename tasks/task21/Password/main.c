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
u8 i = 0;

void main(void) {
	LCD_vidInit();
	KEYPAD_vidInit();

	while(1) {
		/*Check for password match*/
		Password_vidAskID();
		Password_vidAskPassword();
		Password_vidAskReenter();
		Password_vidCheckMatch();
		Password_vidViewRecord();
	}
}
