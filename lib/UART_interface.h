#ifndef _UART_INTERFACE_H
#define _UART_INTERFACE_H

typedef struct {
	u8 u8RxTxEnable;
	u8 u8ParityBits;
	u8 u8StopBits;
	u8 u8CharacterSize;
	u8 u8BaudRateHigh;
	u8 u8BaudRateLow;
} UARTConfig_t;

#define UART_ENABLE_TXRX 0
#define UART_ENABLE_TX 1
#define UART_ENABLE_RX 2

#define UART_PARITYBITS_DISABLED 0
#define UART_PARITYBITS_EVEN 1
#define UART_PARITYBITS_ODD 2

#define UART_STOPBITS_1 0
#define UART_STOPBITS_2 1

#define UART_CHARSIZE_5 0
#define UART_CHARSIZE_6 1
#define UART_CHARSIZE_7 2
#define UART_CHARSIZE_8 3
#define UART_CHARSIZE_9 4

void UART_vidInit(void);
void UART_vidInitExpanded(UARTConfig_t *);
void UART_vidSendByte(u8);
u8 UART_u8ReceiveByte(void);
u8 UART_u8GetReceivedByte(void);
void UART_vidSendLine(void);
void UART_vidSendString(u8 *);

#endif
