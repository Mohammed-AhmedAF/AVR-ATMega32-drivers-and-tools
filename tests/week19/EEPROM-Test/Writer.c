#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "TWI_interface.h"
#include "EEPROM_interface.h"
#include "LCD_interface.h"

#define MESSAGE_SIZE_LOCATION 200

s32 s32WriteFlag = 0;
u8 * message;
u8 * messageTemp;
u8 i = 0;
u8 u8MessageSize = 0;
void main(void) {
	EEPROM_vidInit();
	LCD_vidInit();
	message = "Mohamed";

	//Get Message Size
	messageTemp = message;
	do {
		u8MessageSize++;
		messageTemp++;
	}while(*messageTemp != '\0');
	LCD_vidWriteCharacter(u8MessageSize+'0');
	EEPROM_u8WriteByte(MESSAGE_SIZE_LOCATION,u8MessageSize);
	LCD_vidGoToXY(0,2);
	LCD_vidWriteString("Wait..");
	do {
		s32WriteFlag = EEPROM_u8WriteByte(i,*message);
		message++;
		i++;
		if (s32WriteFlag == 1) {
			LCD_vidWriteString("!");
		}
		else {
			LCD_vidWriteString("?");

		}
	}while(i != u8MessageSize);
	while(1);

}
