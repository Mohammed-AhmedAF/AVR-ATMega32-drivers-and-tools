#ifndef TWI_INTERFACE
#define TWI_INTERFACE

void TWI_vidInit(void);
void TWI_vidSendStart(void);
u8 TWI_vidSendByte(u8);
void TWI_vidSendStop(void);
u8 TWI_u8receiveWithNoAck(void);
u8 TWI_u8checkAck(u8);


#define START_CONDITION 0x08
#define REPEATED_START 0x10
#define SLA_W_ACK 0x18
#define SLA_R_ACK 0x40
#define DATA_TX_ACK 0x28
#endif
