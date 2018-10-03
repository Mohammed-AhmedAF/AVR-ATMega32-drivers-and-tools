/*
 * Author: Mohammed Ahmed Abd Al-Fattah Mahmoud
 * Purpose: Driver for Graphical LCD Nokia 5110
 * Date: 4 October 2018
 */

#include "Macros.h"
#include "Std_Types.h"
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "GLCD_interface.h"

void GLCD_vidInit(void) {
	/*Setting pin direction*/
	DIO_vidSetPinDirection(GLCD_CE_PORT,GLCD_CE_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(GLCD_DC_PORT,GLCD_DC_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(GLCD_RESET_PORT,GLCD_RESET_PIN,DIO_OUTPUT);

	/*Initializing GLCD*/
	GLCD_vidWrite(GLCD_C,0x21);
	GLCD_vidWrite(GLCD_C,0xB9);
	GLCD_vidWrite(GLCD_C,0x04);
	GLCD_vidWrite(GLCD_C,0x14);
	GLCD_vidWrite(GLCD_C,0x20);
	GLCD_vidWrite(GLCD_C,0x0C);
}

void GLCD_vidWrite(u8 dc, u8 data) {
	DIO_vidSetPinValue(GLCD_DC_PORT,GLCD_DC_PIN,dc);
	DIO_vidSetPinValue(GLCD_CE_PORT,GLCD_CE_PIN,STD_LOW);
	SPI_u8TransferByte(data);
	DIO_vidSetPinValue(GLCD_CE_PORT,GLCD_CE_PIN,STD_HIGH);
}
