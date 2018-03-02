#ifndef UART_INTERFACE
#define UART_INTERFACE
void UART_vidInit(void);
void UART_vidSendByte(u8);
u8 UART_vidReceiveByte(void);
#endif
