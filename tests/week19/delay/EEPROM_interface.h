#ifndef EEPROM_INTERFACE
#define EEPROM_INTERFACE
 void EEPROM_vidInit(void);
 u8 EEPROM_u8WriteByte(u16,u8);
 u8 EEPROM_u8ReadByte(u16,u8 *);
#endif
