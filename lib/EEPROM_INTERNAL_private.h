/*
 * EEPROM_INTERNAL_private.h
 *
 * Created: 7/1/2019 8:06:05 AM
 *  Author: Admin
 */ 


#ifndef _EEPROM_INTERNAL_PRIVATE_H_
#define _EEPROM_INTERNAL_PRIVATE_H_


/*Register definitions*/
#define EEARH * ((u8*) 0x3F) 
#define EEARL * ((u8*) 0x3E)
#define EEDR * ((u8*) 0x3D)
#define EECR * ((u8*) 0x3C)

/*Bit definitions*/
#define EERE 0
#define EEWE 1
#define EEMWE 2
#define EERIE 3

#endif /* EEPROM_INTERNAL_PRIVATE_H_ */