#include "Macros.h"
#include "Std_Types.h"
#include <avr/io.h>

void I2C_vidInitMaster(void)
{
	TWBR = 0x00;
	TWBR = 0x0C;
}

void I2C_vidInitSlave(u8 u8SlaveAddress)
{
	TWAR = u8SlaveAddress;
}

void I2C_vidSendStart(void)
{
	TWCR = (1<<TWEN) | (1<<TWSTA) | (1<<TWEA);
	
	/*Until flag is set to 1 by hardware after sending start*/
	while((TWCR & (1<<TWINT))==0);
	/*Read status register*/
	while((TWSR & 0xF8) != 0x08);

}

void I2C_vidSendAddress(u8 u8Address)
{
	TWDR = u8Address<<1;
	TWCR = (1<<TWEN) | (1<<TWINT);
	while ((TWCR & (1<<TWINT)) == 0);
	while ((TWSR & (0xF8)) != 0x18);

}

void I2C_vidSendData(u8 u8Byte)
{
	TWDR = u8Byte;	
	TWCR = (1<<TWINT) | (1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);
	while ((TWSR & 0xF8) != 0x28);

}

u8 I2C_vidReadDataAsSlave(void)
{
	TWCR = (1<<TWEN) | (1<<TWINT) | (1<<TWEA);
	while((TWCR & (1<<TWINT)) == 0);
	while((TWSR & (0xF8)) != 0x80);

	u8 x;
	x = TWDR;
	return x;
}

void I2C_vidStop(void)
{
	TWCR = (1<<TWEN) | (1<<TWSTO) | (1<<TWINT);

}

void I2C_vidMatchACK(void)
{
	while((TWSR & (0xF8)) != 0x60)
	{
		TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
		while ((TWCR & (1<<TWINT)) == 0);
	}
}
