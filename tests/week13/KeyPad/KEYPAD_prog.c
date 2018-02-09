#include "DIO_interface.h"
#include "Macros.h"
#include "Std_Types.h"

void KEYPAD_vidInit() {

	DIO_vidSetPinDirection(ROW0_PORT,ROW0_PIN,1);
	DIO_vidSetPinValue(ROW0_PORT,ROW0_PIN,1);
	DIO_vidSetPinDirection(ROW1_PORT,ROW1_PIN,1);
	DIO_vidSetPinValue(ROW1_PORT,ROW1_PORT,1);
	DIO_vidSetPinDirection(ROW2_PORT,ROW2_PIN,1);
	DIO_vidSetPinValue(ROW2_PORT,ROW2_PIN,1);
	DIO_vidSetPinDirection(ROW3_PORT,ROW3_PIN,1);
	DIO_vidSetPinValue(ROW3_PORT,ROW3_PIN,1);
	
	DIO_vidSetPinDirection(COL0_PORT,COL0_PORT,0);
	DIO_vidSetPinDirection(COL1_PORT,COL1_PIN,0);
	DIO_vidSetPinDirection(COL2_PORT,COL2_PIN,0);
	DIO_vidSetPinDirection(COL3_PIN,COL3_PIN,0);


}
