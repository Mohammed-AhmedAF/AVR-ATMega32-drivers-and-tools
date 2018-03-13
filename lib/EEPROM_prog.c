#include "Macros.h"
#include "Std_Types.h"
#include "TWI_interface.h"
#include "LCD_interface.h"

void EEPROM_vidInit(void) {
	TWI_vidInit();
}

u8 EEPROM_u8WriteByte(u16 u16locationCpy, u8 u8byteCpy) {
	u8 slave_w;
	u8 p1, p0;
	slave_w = 0b10100000;
	p1 = GET_BIT(u16locationCpy,9);
	p0 = GET_BIT(u16locationCpy,8);
	slave_w |= (p1<<2);
	slave_w |= (p0<<1);

	TWI_vidSendStart();
	if(TWI_u8CheckAck(START_CONDITION) == 1) {
		TWI_vidSendByte(slave_w);
		if(TWI_u8CheckAck(SLA_W_ACK) == 1) {
			TWI_vidSendByte((u8)u16locationCpy); //This casting is done, so we take the first 8 bits, that signify the location
			if(TWI_u8CheckAck(DATA_TX_ACK) == 1) {
				TWI_vidSendByte(u8byteCpy);
				if(TWI_u8CheckAck(DATA_TX_ACK) == 1) {
					TWI_vidSendStop();
					return 1; //
				}
			}
		}
	}
	return 0; //If anything fails, return 0;
}

u8 EEPROM_u8readByte(u16 u16locationCpy, u8 * u8dataCpy) {
	u8 slave_w;
	u8 p1, p0;
	slave_w = 0b10100000;
	p1 = GET_BIT(u16locationCpy,9);
	p0 = GET_BIT(u16locationCpy,8);
	slave_w |= (p1<<2);
	slave_w |= (p0<<1);

	TWI_vidSendStart();
	if(TWI_u8CheckAck(START_CONDITION) == 1) {
		TWI_vidSendByte(slave_w);
		if(TWI_u8CheckAck(SLA_W_ACK) == 1) {
			TWI_vidSendByte((u8)u16locationCpy); //This casting is done, so we take the first 8 bits, that signify the location.
			if(TWI_u8CheckAck(DATA_TX_ACK) == 1) {
				TWI_vidSendStart();
				if(TWI_u8CheckAck(REPEATED_START) == 1) {
					SET_BIT(slave_w,0);
					TWI_vidSendByte(slave_w);
					if(TWI_u8CheckAck(SLA_W_ACK) == 1) {
						*u8dataCpy = TWI_u8ReceiveWithNoAck();
						TWI_vidSendStop();
						return 1;
					}
				}	
			}
		}
	}
	return 0;
}

