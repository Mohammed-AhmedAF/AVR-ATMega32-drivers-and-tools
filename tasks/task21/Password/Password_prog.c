#include "Std_Types.h"
#include "Macros.h"
#include "Password_interface.h"

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
