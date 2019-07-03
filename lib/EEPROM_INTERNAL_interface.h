/*
 * EEPROM_INTERNAL_interface.h
 *
 * Created: 7/1/2019 8:02:27 AM
 *  Author: Admin
 */ 


#ifndef _EEPROM_INTERNAL_INTERFACE_H_
#define _EEPROM_INTERNAL_INTERFACE_H_

void EEPROM_INTERNAL_vidWriteByte(u16 u16Address, u8 u8Data);
u8 EEPROM_INTERNAL_u8ReadByte(u16 u16Address);
void EEPROM_INTERNAL_vidWriteByte_test(u16 u16Address, u8 u8Data);



#endif /* EEPROM_INTERNAL_INTERFACE_H_ */