#include "Std_Types.h"
#include "Macros.h"
#include "Password_interface.h"
#include "LCD_interface.h"

void Password_vidSavePassword(u8 * u8idCpy, u8 * u8passwordCpy) {
	static u8 x = 0;
	u8 i = 0;
	/*saving id*/
	for (i = 0; i < 5; i++) {
		db[x].u8id[i] = *u8idCpy++;
	}
	/*saving password*/
	for (i = 0; i < 6; i++) {
		db[x].u8id[i] = *u8passwordCpy++;
	}
	x++;
}

void Password_vidViewRecord(void) {
	u8 x,i;
	for (x = 0; x < 10; x++) {
		LCD_vidSendCommand(LCD_CLEAR_SCREEN);
		/*Viewing ID*/
		for (i = 0; i < 5; i++) {
			LCD_vidWriteCharacter(db[x].u8id[i]);
		}
		/*Viewing password*/
		LCD_vidGoToXY(0,2);
		for (i = 0; i < 6; i++) {
			LCD_vidWriteCharacter(db[x].u8password[i]);
		}
	}
}
