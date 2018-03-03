#include "DIO_interface.h"
#include "Std_Types.h"
#include "Macros.h"
#include "SPI_interface.h"
#include <avr/io.h>

void SPI_vidMasterInit(void) {
	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN4,1);
	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN5,1);
	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN7,1);
	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN6,1);

	SET_BIT(SPCR,6);
	CLEAR_BIT(SPCR,5);
	SET_BIT(SPCR,4);
	CLEAR_BIT(SPCR,1);
	CLEAR_BIT(SPCR,0);
	CLEAR_BIT(SPCR,3);
	SET_BIT(SPCR,2);

}

void SPI_vidSlaveInit(void) {
	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN4,0);
	DIO_vidSetPinValue(DIO_PORTB,DIO_PIN4,1); //Pull-up resistance

	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN5,0);
	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN7,0);
	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN6,1);

	SET_BIT(SPCR,6); //SPI Enable
	CLEAR_BIT(SPCR,5); //
	CLEAR_BIT(SPCR,4);
	CLEAR_BIT(SPCR,1);
	CLEAR_BIT(SPCR,0);
	CLEAR_BIT(SPCR,3);
	SET_BIT(SPCR,2);	
}

u8 SPI_u8transferData(u8 u8dataCpy) {
	DIO_vidSetPinValue(DIO_PORTB,DIO_PIN4,STD_LOW);
	SPDR = u8dataCpy;
	while (GET_BIT(SPCR,7) ==0);
	DIO_vidSetPinDirection(DIO_PORTN,DIO_PIN4,STD_HIGH);
	return SPDR;
}
