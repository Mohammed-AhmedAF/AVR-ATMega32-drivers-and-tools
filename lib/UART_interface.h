#ifndef _UART_INTERFACE_H
#define _UART_INTERFACE_H
void UART_vidInit(void);
void UART_vidSendByte(u8);
u8 UART_u8ReceiveByte(void);
void UART_vidSendLine(void);
void UART_vidSendString(u8 *);


void UART_vidInitExtended(u8);
void UART_vidSendByteExtended(u8,u8);
u8 UART_u8ReceiveByteExtended(u8);

#define UART_CHANNEL0 0
#define UART_CHANNEL1 1

#endif
