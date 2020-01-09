/*
 * Author: Mohammed Ahmed Abd Al-Fattah Mahmoud
 */

#ifndef _TWI_INTERFACE_H
#define _TWI_INTERFACE_H

void TWI_vidInit(void);
void TWI_vidSendStart(void);
void TWI_vidSendByte(u8);
void TWI_vidSendStop(void);
void TWI_vidInitWithValues(u8,u8);
u8 TWI_u8ReceiveWithAck(void);
u8 TWI_u8ReceiveWithNoAck(void);
u8 TWI_u8CheckAck(u8);


#define START_CONDITION 0x08
#define REPEATED_START 0x10
#define SLA_W_ACK 0x18
#define SLA_R_ACK 0x40
#define DATA_TX_ACK 0x28
#endif
