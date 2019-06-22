/*
 * Author: Mohammed Ahmed Abd Al-Fattah Mahmoud
 * File: SPI driver
 */

#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "SPI_private.h"
#include "SPI_interface.h"

void SPI_vidInitMaster(u8 u8ClockPolarity, u8 u8ClockPhase, u8 u8ClockFrequency) {

	//Enabling SPI
	SET_BIT(SPCR,6); //SPE: SPI Enable

	//Selecting Master
	SET_BIT(SPCR,4); //MSTR

	//Clock Polarity
	if (u8ClockPolarity == SPI_CLK_RISING) {
		CLEAR_BIT(SPCR,3); //CPOL: Clock Polarity
	}
	else if (u8ClockPolarity == SPI_CLK_FALLING) {
		SET_BIT(SPCR,3); //CPOL: Clock Polarity
	}

	//Clock Phase
	if (u8ClockPhase == SPI_CLK_PHASE_SAMPLE) {
		CLEAR_BIT(SPCR,2);
	}
	else if (u8ClockPhase == SPI_CLK_PHASE_SETUP) {
		SET_BIT(SPCR,2);
	}

	//Clock Frequency
	if (u8ClockFrequency == SPI_CLK_FREQ_4) {
		CLEAR_BIT(SPCR,0);
		CLEAR_BIT(SPCR,1);
		CLEAR_BIT(SPSR,0);
	}
	else if(u8ClockFrequency == SPI_CLK_FREQ_16) {
		SET_BIT(SPCR,0);
		CLEAR_BIT(SPCR,1);
		CLEAR_BIT(SPSR,0);
	}
	else if(u8ClockFrequency == SPI_CLK_FREQ_64) {
		CLEAR_BIT(SPCR,0);
		SET_BIT(SPCR,1);
		CLEAR_BIT(SPSR,0);
	}
	else if(u8ClockFrequency == SPI_CLK_FREQ_128) {
		SET_BIT(SPCR,0);
		SET_BIT(SPCR,1);
		CLEAR_BIT(SPSR,0);
	}
	else if(u8ClockFrequency == SPI_CLK_FREQ_2) {
		CLEAR_BIT(SPCR,0);
		CLEAR_BIT(SPCR,1);
		SET_BIT(SPSR,0);
	}
	else if(u8ClockFrequency == SPI_CLK_FREQ_8) {
		SET_BIT(SPCR,0);
		CLEAR_BIT(SPCR,1);
		SET_BIT(SPSR,0);
	}
	else if(u8ClockFrequency == SPI_CLK_FREQ_32) {
		CLEAR_BIT(SPCR,0);
		SET_BIT(SPCR,1);
		SET_BIT(SPSR,0);
	}
	else if(u8ClockFrequency == SPI_CLK_FREQ_64_DOUBLE) {
		SET_BIT(SPCR,0);
		SET_BIT(SPCR,1);
		SET_BIT(SPSR,0);
	}


}

void SPI_vidInitSlave(u8 u8ClockPolarity, u8 u8ClockPhase, u8 u8ClockFrequency) {

	//Enable SPI
	SET_BIT(SPCR,6);

	//Slave
	CLEAR_BIT(SPCR,4);

	//Clock Polarity
	if (u8ClockPolarity == SPI_CLK_RISING) {
		CLEAR_BIT(SPCR,3); //CPOL: Clock Polarity
	}
	else if (u8ClockPolarity == SPI_CLK_FALLING) {
		SET_BIT(SPCR,3); //CPOL: Clock Polarity
	}

	//Clock Phase
	if (u8ClockPhase == SPI_CLK_PHASE_SAMPLE) {
		CLEAR_BIT(SPCR,2);
	}
	else if (u8ClockPhase == SPI_CLK_PHASE_SETUP) {
		SET_BIT(SPCR,2);
	}

	//Clock Frequency
	if (u8ClockFrequency == SPI_CLK_FREQ_4) {
		CLEAR_BIT(SPCR,0);
		CLEAR_BIT(SPCR,1);
		CLEAR_BIT(SPSR,0);
	}
	else if(u8ClockFrequency == SPI_CLK_FREQ_16) {
		SET_BIT(SPCR,0);
		CLEAR_BIT(SPCR,1);
		CLEAR_BIT(SPSR,0);
	}
	else if(u8ClockFrequency == SPI_CLK_FREQ_64) {
		CLEAR_BIT(SPCR,0);
		SET_BIT(SPCR,1);
		CLEAR_BIT(SPSR,0);
	}
	else if(u8ClockFrequency == SPI_CLK_FREQ_128) {
		SET_BIT(SPCR,0);
		SET_BIT(SPCR,1);
		CLEAR_BIT(SPSR,0);
	}
	else if(u8ClockFrequency == SPI_CLK_FREQ_2) {
		CLEAR_BIT(SPCR,0);
		CLEAR_BIT(SPCR,1);
		SET_BIT(SPSR,0);
	}
	else if(u8ClockFrequency == SPI_CLK_FREQ_8) {
		SET_BIT(SPCR,0);
		CLEAR_BIT(SPCR,1);
		SET_BIT(SPSR,0);
	}
	else if(u8ClockFrequency == SPI_CLK_FREQ_32) {
		CLEAR_BIT(SPCR,0);
		SET_BIT(SPCR,1);
		SET_BIT(SPSR,0);
	}
	else if(u8ClockFrequency == SPI_CLK_FREQ_64_DOUBLE) {
		SET_BIT(SPCR,0);
		SET_BIT(SPCR,1);
		SET_BIT(SPSR,0);
	}
}

u8 SPI_u8TransferByte(u8 u8ByteCpy) {
	DIO_vidSetPinValue(DIO_PORTB,DIO_PIN4,STD_LOW);
	SPDR = u8ByteCpy;

	while(GET_BIT(SPSR,7) == 0);
	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN4,STD_HIGH);
	return SPDR;

}

void SPI_vidEnableInterrupt(void) {
	SET_BIT(SPCR,7);
}

void SPI_vidDisableInterrupt(void) {
	CLEAR_BIT(SPCR,7);
}
