#include "Macros.h"
#include "Std_Types.h"
#include "DIO_interface.h"
#include "TWI_interface.h"
#include "EEPROM_interface.h"
#include "LCD_interface.h"

u8 flag;
u8 u8Ack;
int main(void) {
	LCD_vidInit();
	EEPROM_vidInit();

	u8 u8Data;
	flag = EEPROM_u8ReadByte(0,&u8Data);
	if (flag = 1) {
		LCD_vidGoToXY(0,2);
		LCD_vidWriteCharacter(u8Data);
	}
	else {
		LCD_vidGoToXY(0,2);
		LCD_vidWriteString("Not done.");
	}
}
