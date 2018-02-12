#include "DIO_interface.h"
#include "Std_Types.h"
#include "KEYPAD_interface.h"
#include "LCD_interface.h"
#include "Macros.h"
#include <util/delay.h>

void main(void) {
	LCD_vidInit();
	KEYPAD_vidInit();
	u8 u8PressedKey = 0xFF;
	while(1) {
		u8PressedKey = 0xFF;
		do {
			u8PressedKey = KEYPAD_u8GetKey();
			_delay_ms(200);
			u8PressedKey = KEYPAD_u8GetKey();
		}while(u8PressedKey==0xFF);
		if ((u8PressedKey >= 0) && (u8PressedKey <=9)) {
			u8PressedKey += 0x30;
		}
		LCD_vidWriteCharacter(u8PressedKey);
	}
}

