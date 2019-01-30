/*
 * Author: Mohammed Ahmed Abd Al-Fattah
 * Purpose: Keypad driver for Atmega32 MCU
 *
 */


#include "Macros.h"
#include "Std_Types.h"
#include "KEYPAD_interface.h"
#include "DIO_interface.h"

void KEYPAD_vidInit(void) {

	DIO_vidSetPinDirection(ROW0_PORT,ROW0_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(ROW1_PORT,ROW1_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(ROW2_PORT,ROW2_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(ROW3_PORT,ROW3_PIN,DIO_OUTPUT);

	DIO_vidSetPinDirection(COL0_PORT,COL0_PIN,DIO_INPUT);	
	DIO_vidSetPinValue(COL0_PORT,COL0_PIN,STD_HIGH);	
	DIO_vidSetPinDirection(COL1_PORT,COL1_PIN,DIO_INPUT);
	DIO_vidSetPinValue(COL1_PORT,COL1_PIN,STD_HIGH);
	DIO_vidSetPinDirection(COL2_PORT,COL2_PIN,DIO_INPUT);
	DIO_vidSetPinValue(COL2_PORT,COL2_PIN,STD_HIGH);
	DIO_vidSetPinDirection(COL3_PORT,COL3_PIN,DIO_INPUT);
	DIO_vidSetPinValue(COL3_PORT,COL3_PIN,STD_HIGH);

}


u8 keys[4][4] = {{'/',3,2,1},{'*',6,5,4},{'+',9,8,7},{'=','-',0,'#'}};
u8 values[4] = {0x0E,0x0D,0x0B,0x07};
u8 value,i = 0;
u8 KEYPAD_u8GetKey(void) {
	for (i = 0; i < 4; i++) {
		u8 x = 0;
		value = values[i];
		DIO_vidSetPinValue(ROW0_PORT,ROW0_PIN,GET_BIT(value,0));
		DIO_vidSetPinValue(ROW1_PORT,ROW1_PIN,GET_BIT(value,1));
		DIO_vidSetPinValue(ROW2_PORT,ROW2_PIN,GET_BIT(value,2));
		DIO_vidSetPinValue(ROW3_PORT,ROW3_PIN,GET_BIT(value,3));

		x |= (DIO_u8GetPinValue(COL0_PORT,COL0_PIN) << 0);
		x |= (DIO_u8GetPinValue(COL1_PORT,COL1_PIN) << 1);
		x |= (DIO_u8GetPinValue(COL2_PORT,COL2_PIN) << 2);
		x |= (DIO_u8GetPinValue(COL3_PORT,COL3_PIN) << 3);
		/*This macro, if defined, will not print a character until
		 *the button is depressed. It is used to prevent printing 
		 *the character more than once.
		 **/		
		#ifdef HOLD_BUTTON
			while(DIO_u8GetPinValue(COL0_PORT,COL0_PIN) == 0);
			while(DIO_u8GetPinValue(COL1_PORT,COL1_PIN) == 0);
			while(DIO_u8GetPinValue(COL2_PORT,COL2_PIN) == 0);
			while(DIO_u8GetPinValue(COL3_PORT,COL3_PIN) == 0);	
		#endif
		switch(x) {
			case 0x07:
				return keys[i][0];
			case 0x0B:
				return keys[i][1];
			case 0x0D:
				return keys[i][2];
			case 0x0E:
				return keys[i][3];
		}
	}
	return 0xFF;
}
