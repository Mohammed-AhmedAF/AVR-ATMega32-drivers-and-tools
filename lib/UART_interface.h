#ifndef UART_INTERFACE
#define UART_INTERFACE
void UART_vidInit(void);
void UART_vidSendByte(u8);
u8 UART_u8ReceiveByte(void);
void UART_vidSendLine(void);
void UART_vidSendString(u8 *);
#endif
