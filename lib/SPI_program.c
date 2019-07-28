/*
 * Author: Mohammed Ahmed Abd Al-Fattah Mahmoud
 * File: SPI driver
 */
#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "SPI_private.h"
#include "SPI_interface.h"

void SPI_vidInitMaster(void) {

	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN5,DIO_OUTPUT); /*MOSI*/
	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN6,DIO_INPUT); /*MISO*/
	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN7,DIO_OUTPUT); /*SCK*/
	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN4,DIO_OUTPUT); /*SS*/
		
	/*SPI control*/
	
	SET_BIT(SPCR,6); 
	/*Enable master*/
	SET_BIT(SPCR,4);
	/*16 prescaler*/
	SET_BIT(SPCR,0);

}


void SPI_vidEnableSS(void) {
	DIO_vidSetPinValue(DIO_PORTB,DIO_PIN4,STD_LOW);
}

void SPI_vidDisableSS(void) {
	DIO_vidSetPinValue(DIO_PORTB,DIO_PIN4,STD_HIGH);
}

void SPI_vidTransferByte(u8 u8ByteCpy) {
	SPDR = u8ByteCpy;
	while(!(SPSR & (1<<7)));										/* wait here while SPIF flag set */
}


u8 SPI_u8ReceiveByte(void) {
	SPDR = 0xFE;
	while(!(SPSR & (1<<7));
	return SPDR;
}

oid SPI_vidEnableInterrupt(void) {
	SET_BIT(SPCR,7);
}

void SPI_vidDisableInterrupt(void) {
	CLEAR_BIT(SPCR,7);
}
