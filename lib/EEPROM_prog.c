#include"Macros.h"
#include"Std_Types.h"
#include"TWI_interface.h"
#include"EEPROM_interface.h"

void EEPROM_vidInit(void)
{
	TWI_vidInit();
}

u8 EEPROM_u8WriteByte(u16 u16Location,u8 u8ByteCpy)
{
	u8 SLA_W;
	u8 P1,P0;
	SLA_W=0b10100000;
	P1=GET_BIT(u16Location,9);
	P0=GET_BIT(u16Location,8);
	SLA_W |=(P1<<2);
	SLA_W |=(P0<<1);
	TWI_vidSendStart();
	if(TWI_u8CheckAck(START_CONDITION)==1)
	{
		TWI_vidSendByte(SLA_W);
		if(TWI_u8CheckAck(SLA_W_ACK)==1)
		{
			TWI_vidSendByte((u8)u16Location);
			if(TWI_u8CheckAck(DATA_TX_ACK)==1)
			{
				TWI_vidSendByte(u8ByteCpy);
				if(TWI_u8CheckAck(DATA_TX_ACK)==1)
				{
					TWI_vidSendStop();
					return 1;
				}
			}
		}
	}
	return 0;
}

u8 EEPROM_u8ReadByte(u16 u16LocationCpy,u8 * u8DataCpy)
{

	u8 SLA_W;
	u8 P1,P0;
	SLA_W=0b10100000;
	P1=GET_BIT(u16LocationCpy,9);
	P0=GET_BIT(u16LocationCpy,8);
	SLA_W |=(P1<<2);
	SLA_W |=(P0<<1);

	TWI_vidSendStart();
	if(TWI_u8CheckAck(START_CONDITION) == 1) {
		TWI_vidSendByte(SLA_W);
		if(TWI_u8CheckAck(SLA_W_ACK) == 1) {
			TWI_vidSendByte((u8)u16LocationCpy);
			if(TWI_u8CheckAck(DATA_TX_ACK) == 1) {
				TWI_vidSendStart();
				if(TWI_u8CheckAck(REPEATED_START) == 1) {
					SET_BIT(SLA_W,0);
					TWI_vidSendByte(SLA_W);
					if(TWI_u8CheckAck(SLA_R_ACK) == 1) {
						*u8DataCpy = TWI_u8ReceiveWithNoAck();
						TWI_vidSendStop();
						return 1;
					}
				}
			}
		}
	}
	return 0;
}


