/*
 * Author: Mohammed Ahmed Abd Al-Fattah Mahmoud
 * Purpose: I2C driver for Atmega32
 */

#include "Macros.h"
#include "Std_Types.h"
#include "TWI_interface.h"
#include <avr/io.h>

void TWI_vidInit(void) {
	TWCR = (1<<TWEN); //To enable TWI
	TWBR = 2; //Clk configuration
	TWSR = 0; //Clk configuration
	TWAR = 2; // Address of this node, whether it is a slave or master
}

void TWI_vidInitWithValues(u8 u8BitrateRegVal, u8 u8PresScalerVal) {
	TWCR = (1<<TWEN);
	TWBR = u8BitrateRegVal;
	TWSR = u8PresScalerVal;
	TWAR = 2;

}

void TWI_vidSendStart(void) {

	TWCR = (1<<TWSTA) | (1<<TWINT) | (1<<TWEN); //
	while(GET_BIT(TWCR,TWINT) == 0);
}

//This function is used to send bytes
//whether data or address.
void TWI_vidSendByte(u8 u8byteCpy) {
	TWDR = u8byteCpy;
	TWCR = (1<<TWINT) | (1<<TWEN);

	while(GET_BIT(TWCR,TWINT)==0); //Waiting for TWI job flag
}

void TWI_vidSendStop(void) {
	TWCR = (1 << TWSTO) | (1 << TWINT) | (1 << TWEN);
	//We don't need to worry about checking the flag
}

u8 TWI_u8ReceiveWithAck(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	while(GET_BIT(TWCR,TWINT) == 0);
	return TWDR;
}

u8 TWI_u8ReceiveWithNoAck(void) {
	TWCR = (1<<TWINT) | (1 << TWEN);
	while(GET_BIT(TWCR,TWINT) == 0); //We wait until the job of receiving is complete;
	return TWDR;
}

//This function takes the expected ACK as an input parameter
//Based on the current job, the microcontoller will check from a list of ACKs.
u8 TWI_u8CheckAck(u8 u8AckCpy) {
	//Masking TWSR
	u8 u8receivedAck;
	u8receivedAck = TWSR&(0b11111000);
	if(u8receivedAck == u8AckCpy) {
		return 1;
	}
	else {
		return 0;
	}
}
