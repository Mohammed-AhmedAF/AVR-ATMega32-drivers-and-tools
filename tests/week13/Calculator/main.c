#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KEYPAD_interface.h"
#include "Calc_interface.h"
#include "Macros.h"
#include "Std_Types.h"
#include <util/delay.h>

s8 s8Message;

void main(void) {
	LCD_vidInit();
	KEYPAD_vidInit();
	u8 u8keyPressed = 0xFF;
	while(1) {
		do {
			u8keyPressed = KEYPAD_u8GetKey();
			_delay_ms(300);
			u8keyPressed = KEYPAD_u8GetKey();
		}while(u8keyPressed == 0xFF);
		if (u8keyPressed == '#') {
			LCD_vidSendCommand(LCD_CLEAR_SCREEN);
			Calc_vidRestart();
		}
		else {
			if((u8keyPressed >= 0) && (u8keyPressed <=9)) {
				u8keyPressed += 0x30;
			}
			LCD_vidWriteCharacter(u8keyPressed);
			Calc_vidPutInEquation(u8keyPressed);
		}
	}
}
