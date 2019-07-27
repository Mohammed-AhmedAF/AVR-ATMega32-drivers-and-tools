#ifndef _EEPROM_INTERFACE_H
#define _EEPROM_INTERFACE_H
 
#define EEPROM_STATUS_FAIL 0
#define EEPROM_STATUS_SUCCESS 1


void EEPROM_vidInit(void);
 u8 EEPROM_u8WriteByte(u16,u8);
 u8 EEPROM_u8ReadByte(u16,u8 *);
#endif
