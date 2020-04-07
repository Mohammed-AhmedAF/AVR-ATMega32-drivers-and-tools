#ifndef _I2C_INTERFACE_H
#define _I2C_INTERFACE_H

void I2C_vidInitMaster(void);
void I2C_vidInitSlave(u8 u8SlaveAddress);
void I2C_vidSendAddress(u8 u8Address);
void I2C_vidSendData(u8 u8Byte);
void I2C_vidSendStop(void);
void I2C_vidReadDataAsSlave(void);
void I2C_vidMatchACK(void);

#endif
