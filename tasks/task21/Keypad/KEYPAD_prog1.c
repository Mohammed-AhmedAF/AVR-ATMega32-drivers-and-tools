#include "DIO_interface.h"
#include "KEYPAD_interface.h"
#include "Macros.h"
#include "Std_Types.h"

u8 i;

void KEYPAD_vidInit(void) {

	DIO_vidSetPinDirection(ROW0_PORT,ROW0_PIN,1);
	DIO_vidSetPinDirection(ROW1_PORT,ROW1_PIN,1);
	DIO_vidSetPinDirection(ROW2_PORT,ROW2_PIN,1);
	DIO_vidSetPinDirection(ROW3_PORT,ROW3_PIN,1);

	DIO_vidSetPinDirection(COL0_PORT,COL0_PIN,0);	
	DIO_vidSetPinValue(COL0_PORT,COL0_PIN,1);	
	DIO_vidSetPinDirection(COL1_PORT,COL1_PIN,0);
	DIO_vidSetPinValue(COL1_PORT,COL1_PIN,1);
	DIO_vidSetPinDirection(COL2_PORT,COL2_PIN,0);
	DIO_vidSetPinValue(COL2_PORT,COL2_PIN,1);
	DIO_vidSetPinDirection(COL3_PORT,COL3_PIN,0);
	DIO_vidSetPinValue(COL3_PORT,COL3_PIN,1);
}

void KEYPAD_vidInit_1(u8 u8rowsPorts[], u8  u8rowsPins[], u8 u8colsPorts[], u8 u8colsPins[]){
	DIO_vidSetPinDirection(u8rowsPorts[0],u8rowsPins[0],1);
	DIO_vidSetPinDirection(u8rowsPorts[1],u8rowsPins[1],1);
	DIO_vidSetPinDirection(u8rowsPorts[2],u8rowsPins[2],1);
	DIO_vidSetPinDirection(u8rowsPorts[3],u8rowsPins[3],1);

	DIO_vidSetPinDirection(u8colsPorts[0],u8colsPins[0],0);
	DIO_vidSetPinValue(u8colsPorts[0],u8colsPins[0],1);
	DIO_vidSetPinDirection(u8colsPorts[1],u8colsPins[1],0);
	DIO_vidSetPinValue(u8colsPorts[1],u8colsPins[1],1);
	DIO_vidSetPinDirection(u8colsPorts[2],u8colsPins[2],0);
	DIO_vidSetPinValue(u8colsPorts[2],u8colsPins[2],1);
	DIO_vidSetPinDirection(u8colsPorts[3],u8colsPins[3],0);
	DIO_vidSetPinValue(u8colsPorts[3],u8colsPins[3],1);
}

u8 u8keys[4][4] = {{'/','3','2','1'},{'*','6','5','4'},{'+','9','8','7'},{'-','=','0','#'}};
u8 u8helpers[4] = {0x0E,0x0D,0x0B,0x07};
u8 KEYPAD_u8GetKey_1(void) {
	u8 x = 0;
	for (i = 0; i < 4; i++) {
		x = 0;
		DIO_vidSetPinValue(ROW0_PORT,ROW0_PIN,GET_BIT(u8helpers[i],0));
		DIO_vidSetPinValue(ROW1_PORT,ROW1_PIN,GET_BIT(u8helpers[i],1));
		DIO_vidSetPinValue(ROW2_PORT,ROW2_PIN,GET_BIT(u8helpers[i],2));
		DIO_vidSetPinValue(ROW3_PORT,ROW3_PIN,GET_BIT(u8helpers[i],3));

		x |= (DIO_u8GetPinValue(COL0_PORT,COL0_PIN) << 0);
		x |= (DIO_u8GetPinValue(COL1_PORT,COL1_PIN) << 1);
		x |= (DIO_u8GetPinValue(COL2_PORT,COL2_PIN) << 2);
		x |= (DIO_u8GetPinValue(COL3_PORT,COL3_PIN) << 3);


		switch(x) {
			case 0x07:
				return u8keys[i][0];
			case 0x0B:
				return u8keys[i][1];
			case 0x0D:
				return u8keys[i][2];
			case 0x0E:
				return u8keys[i][3];

		}	

	}
	return 0xFF;
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
