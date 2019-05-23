/*
* NOKIA5110_program.c
*
* Created: 5/23/2019 10:40:32 AM
*  Author: Admin
*/

#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "Font.h"
#include "NOKIA5110_interface.h"
#include "SPI_interface.h"
#include <string.h>
#include <util/delay.h>

void NOKIA5110_vidInit(void) {
	/*Configuring direction for DC and RST pins*/
	DIO_vidSetPinDirection(NOKIA5110_DC_PORT,NOKIA5110_DC_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(NOKIA5110_RST_PORT,NOKIA5110_RST_PIN,DIO_OUTPUT);
	
	NOKIA5110_vidReset();
	NOKIA5110_vidSendCommand(NOKIA5110_CMD_ADD_MODE);
	NOKIA5110_vidSendCommand(NOKIA5110_CMD_VOLT_5V);
	NOKIA5110_vidSendCommand(NOKIA5110_CMD_TEMPCOEF_3);
	NOKIA5110_vidSendCommand(NOKIA5110_CMD_VOLTBIAS);
	NOKIA5110_vidSendCommand(NOKIA5110_CMD_BASIC_MODE);
	NOKIA5110_vidSendCommand(NOKIA5110_CMD_NORMAL_MODE);
}

void NOKIA5110_vidSendCommand(u8 u8CommandCpy) {
	DIO_vidSetPinValue(NOKIA5110_DC_PORT,NOKIA5110_DC_PIN,STD_LOW);
	
	/*Enable SS*/
	SPI_vidEnableSS();
	SPI_vidTransferByte(u8CommandCpy);
	DIO_vidSetPinValue(NOKIA5110_DC_PORT,NOKIA5110_DC_PIN,STD_HIGH);
	
	/*Disable SS*/
	SPI_vidDisableSS();
}

void NOKIA5110_vidReset(void) {
	DIO_vidSetPinValue(NOKIA5110_RST_PORT,NOKIA5110_RST_PIN,STD_LOW);
	_delay_ms(100);
	DIO_vidSetPinValue(NOKIA5110_RST_PORT,NOKIA5110_RST_PIN,STD_HIGH);
}

void NOKIA5110_vidClearScreen(void) {
	SPI_vidEnableSS();
	
	DIO_vidSetPinValue(NOKIA5110_DC_PORT,NOKIA5110_DC_PIN,STD_HIGH);
	u16 u16PixelIndex;
	for (u16PixelIndex = 0; u16PixelIndex < 503; u16PixelIndex++) {
		SPI_vidTransferByte(0x00);
	}
	
	DIO_vidSetPinValue(NOKIA5110_DC_PORT,NOKIA5110_DC_PIN,STD_LOW);
	
	SPI_vidDisableSS();
}

void NOKIA5110_vidSendData(u8 * u8DataCpy) {
	
	DIO_vidSetPinValue(NOKIA5110_DC_PORT,NOKIA5110_DC_PIN,STD_HIGH);
	
	SPI_vidEnableSS();
	
	u32 lenan = strlen(u8DataCpy);
	u8 u8Index;
	u32 u32seg;
	for (u32seg = 0; u32seg < lenan; u32seg++) {
		for (u8Index = 0; u8Index < 5; u8Index++) {
			SPI_vidTransferByte(ASCII[u8DataCpy[u32seg] - 0x20][u8Index]);
		}
		SPI_vidTransferByte(0x00);
	}
	SPI_vidDisableSS();
}

void NOKIA5110_vidDrawImage(const u8 * u8ImageData) {
	SPI_vidEnableSS();
	
	DIO_vidSetPinValue(NOKIA5110_DC_PORT,NOKIA5110_DC_PIN,STD_HIGH);
	u16 u16PixelIndex;
	for (u16PixelIndex = 0; u16PixelIndex < 503; u16PixelIndex++) {
		SPI_vidTransferByte(u8ImageData[u16PixelIndex]);
	}
	DIO_vidSetPinValue(NOKIA5110_DC_PORT,NOKIA5110_DC_PIN,STD_LOW);
	
	SPI_vidDisableSS();
}

void NOKIA5110_vidGoToXY(u8 u8XPos, u8 u8YPos) {
	NOKIA5110_vidSendCommand(u8XPos);
	NOKIA5110_vidSendCommand(u8YPos);
}