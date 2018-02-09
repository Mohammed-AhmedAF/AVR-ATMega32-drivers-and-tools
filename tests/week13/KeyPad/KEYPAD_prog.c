#include "DIO_interface.h"
#include "KEYPAD_interface.h"
#include "Macros.h"
#include "Std_Types.h"

void KEYPAD_vidInit() {

	DIO_vidSetPinDirection(ROW0_PORT,ROW0_PIN,1);
	DIO_vidSetPinDirection(ROW1_PORT,ROW1_PIN,1);
	DIO_vidSetPinDirection(ROW2_PORT,ROW2_PIN,1);
	DIO_vidSetPinDirection(ROW3_PORT,ROW3_PIN,1);

	DIO_vidSetPinDirection(COL0_PORT,COL0_PORT,0);	
	DIO_vidSetPinValue(COL0_PORT,COL0_PIN,1);	
	DIO_vidSetPinDirection(COL1_PORT,COL1_PIN,0);
	DIO_vidSetPinValue(COL1_PORT,COL1_PIN,1);
	DIO_vidSetPinDirection(COL2_PORT,COL2_PIN,0);
	DIO_vidSetPinValue(COL2_PORT,COL2_PIN,1);
	DIO_vidSetPinDirection(COL3_PIN,COL3_PIN,0);
	DIO_vidSetPinValue(COL2_PORT,COL2_PIN,1);

}

u8 KEYPAD_u8GetKey(void) {
	/*1st*/
	u8 x = 0;
	DIO_vidSetPinValue(ROW0_PORT,ROW0_PIN,0);
	DIO_vidSetPinValue(ROW1_PORT,ROW1_PIN,1);
	DIO_vidSetPinValue(ROW2_PORT,ROW2_PIN,1);
	DIO_vidSetPinValue(ROW3_PORT,ROW3_PIN,1);

	x |= (DIO_u8GetPinValue(COL0_PORT,COL0_PIN) << 0);
	x |= (DIO_u8GetPinValue(COL1_PORT,COL1_PIN) << 1);
	x |= (DIO_u8GetPinValue(COL2_PORT,COL2_PIN) << 2);
	x |= (DIO_u8GetPinValue(COL3_PORT,COL3_PIN) << 3);
	switch(x) {
		case 0x07:
			return '/';
		case 0x0B:
			return 3;
		case 0x0D:
			return 2;
		case 0x0E:
			return 1;

	}	
	/*2nd*/
	x = 0;
	DIO_vidSetPinValue(ROW0_PORT,ROW0_PIN,1);
	DIO_vidSetPinValue(ROW1_PORT,ROW1_PIN,0);
	DIO_vidSetPinValue(ROW2_PORT,ROW2_PIN,1);
	DIO_vidSetPinValue(ROW3_PORT,ROW3_PIN,1);

	x |= (DIO_u8GetPinValue(COL0_PORT,COL0_PIN) << 0);
	x |= (DIO_u8GetPinValue(COL1_PORT,COL1_PIN) << 1);
	x |= (DIO_u8GetPinValue(COL2_PORT,COL2_PIN) << 2);
	x |= (DIO_u8GetPinValue(COL3_PORT,COL3_PIN) << 3);
	switch(x) {
		case 0x07:
			return '*';
		case 0x0B:
			return 6;
		case 0x0D:
			return 5;
		case 0x0E:
			return 4;
	}

	/*3d*/
	x =0;
	DIO_vidSetPinValue(ROW0_PORT,ROW0_PIN,1);
	DIO_vidSetPinValue(ROW1_PORT,ROW1_PIN,1);
	DIO_vidSetPinValue(ROW2_PORT,ROW2_PIN,0);
	DIO_vidSetPinValue(ROW3_PORT,ROW3_PIN,1);

	x |= (DIO_u8GetPinValue(COL0_PORT,COL0_PIN) << 0);
	x |= (DIO_u8GetPinValue(COL1_PORT,COL1_PIN) << 1);
	x |= (DIO_u8GetPinValue(COL2_PORT,COL2_PIN) << 2);
	x |= (DIO_u8GetPinValue(COL3_PORT,COL3_PIN) << 3);

	switch(x) {
		case 0x07:
			return '+';
		case 0x0B:
			return 9;
		case 0x0D:
			return 8;
		case 0x0E:
			return 7;
	}

	/*4th*/
	x = 0;
	DIO_vidSetPinValue(ROW0_PORT,ROW0_PIN,1);
	DIO_vidSetPinValue(ROW1_PORT,ROW1_PIN,1);
	DIO_vidSetPinValue(ROW2_PORT,ROW2_PIN,1);
	DIO_vidSetPinValue(ROW3_PORT,ROW3_PIN,0);
	

	x |= (DIO_u8GetPinValue(COL0_PORT,COL0_PIN) << 0);
	x |= (DIO_u8GetPinValue(COL1_PORT,COL1_PIN) << 1);
	x |= (DIO_u8GetPinValue(COL2_PORT,COL2_PIN) << 2);
	x |= (DIO_u8GetPinValue(COL3_PORT,COL3_PIN) << 3);

	switch(x) {
		case 0x07:
			return '-';
		case 0x0B:
			return '=';
		case 0x0D:
			return 0;
		case 0x0E:
			return '#';
	}
	return 0xFF;
}
