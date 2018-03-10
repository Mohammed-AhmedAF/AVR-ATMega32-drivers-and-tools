#include "DIO_interface.h"
#include "Macros.h"
#include "Std_Types.h"
#include <avr/io.h>

void TWI_vidInit(void) {
	TWCR = (1<<TWEN); //To enable TWI
	TWBR = 2; //Clk configuration
	TWSR = 0; //Clk configuration
	TWAR = 2; // Address of this node, wheter it is a slave or master
}

void TWI_vidSendStart(void) {

	TWCR = (1<<TWSTA) | (1<<TWINT) | (1<<TWEN); //
	while(GET_BIT(TWCR,TWINT) == 0);
}

//This function is used to send bytes
//whether data or address.
void TWI_vidSendByte(u8 u8byteCpy) {
	TWDR = u8byteCpy;
	TWCR = (1<TWINT) | (1<TWEN);

	while(GET_BIT(TWCR,TWINT)==0); //Waiting for TWI job flag
}
