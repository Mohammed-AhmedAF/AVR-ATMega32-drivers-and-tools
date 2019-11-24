#ifndef _TWI_PRIVATE_H
#define _TWI_PRIVATE_H

#define TWCR * ((volatile u8*) 0x56)
#define TWDR * ((volatile u8*) 0x23)
#define TWAR * ((volatile u8*) 0x22)
#define TWSR * ((volatile u8*) 0x21)
#define TWBR * ((volatile u8*) 0x20)

#endif
