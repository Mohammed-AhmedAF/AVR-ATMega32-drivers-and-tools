/*
 * EEPROM_INTERNAL_private.h
 *
 * Created: 7/1/2019 8:06:05 AM
 *  Author: Admin
 */ 


#ifndef _EEPROM_INTERNAL_PRIVATE_H_
#define _EEPROM_INTERNAL_PRIVATE_H_


/*Register definitions*/
#define EEAR * ((volatile u8*) 0x3E)
#define EEARH * ((volatile u8*) 0x3F) 
#define EEARL * ((volatile u8*) 0x3E)
#define EEDR * ((volatile u8*) 0x3D)
#define EECR * ((volatile u8*) 0x3C) /*So that the compiler doesn't outsmart me*/

#define SPMCR * ((u8*) 0x57)

/*Bit definitions*/
#define EERE 0
#define EEWE 1
#define EEMWE 2
#define EERIE 3

#define SPMEN 0
#endif /* EEPROM_INTERNAL_PRIVATE_H_ */