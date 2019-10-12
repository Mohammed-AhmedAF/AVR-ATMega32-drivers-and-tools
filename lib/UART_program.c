/*
 * Author: Mohammed Ahmed Abd Al-Fattah Mahmoud
 * Purpose: UART driver for Atmega32
 */

#include "Macros.h"
#include "Std_Types.h"
#include "DIO_interface.h"
#include "UART_interface.h"
#include <avr/io.h>

void UART_vidInit(void) {	

	//Setting both Receive Enable and Transmit Enable
	SET_BIT(UCSRB,4);
	SET_BIT(UCSRB,3);

	//Selecting UCSRA

	//Selecting Asynchronous mode

	//No parity
	CLEAR_BIT(UCSRC,5);
	CLEAR_BIT(UCSRC,4);

	//Number of stop bits
	SET_BIT(UCSRC,3);

	//Character size
	CLEAR_BIT(UCSRB,2);
	SET_BIT(UCSRC,2);
	SET_BIT(UCSRC,1);

	//Clock polarity
	

	//Selecting UBRRH
	UBRRH = 0;
	UBRRL = 51;
}

void UART_vidInitExpanded(UARTConfig_t * UARTConfig)
{
	switch(UARTConfig->u8RxTxEnable)
	{
		case UART_ENABLE_TXRX:
			SET_BIT(UCSRB,4);
			SET_BIT(UCSRB,3);
			break;
		case UART_ENABLE_TX:
			SET_BIT(UCSRB,3);
			break;
		case UART_ENABLE_RX:
			SET_BIT(UCSRB,4);
			break;
		default:
			SET_BIT(UCSRB,4);
			SET_BIT(UCSRB,3);
	}
	
	switch (UARTConfig->u8ParityBits)
	{
		case UART_PARITYBITS_DISABLED:
			CLEAR_BIT(UCSRC,5);
			CLEAR_BIT(UCSRC,4);
			break;
		case UART_PARITYBITS_EVEN:
			SET_BIT(UCSRC,5);
			CLEAR_BIT(UCSRC,4);
			break;
		case UART_PARITYBITS_ODD:
			SET_BIT(UCSRC,5);
			SET_BIT(UCSRC,4);
			break;
		default:
			CLEAR_BIT(UCSRC,5);
			CLEAR_BIT(UCSRC,4);
	}

	switch (UARTConfig->u8StopBits)
	{
		case UART_STOPBITS_1:
			CLEAR_BIT(UCSRC,3);
			break;
		case UART_STOPBITS_2:
			SET_BIT(UCSRC,3);
			break;
		default:
			CLEAR_BIT(UCSRC,3);
	}

	switch (UARTConfig->u8CharacterSize)
	{
		case UART_CHARSIZE_5:
			CLEAR_BIT(UCSRB,2);
			CLEAR_BIT(UCSRC,2);
			CLEAR_BIT(UCSRC,1);
			break;
		case UART_CHARSIZE_6:
			CLEAR_BIT(UCSRB,2);
			CLEAR_BIT(UCSRC,2);
			SET_BIT(UCSRC,1);
			break;
		case UART_CHARSIZE_7:
			CLEAR_BIT(UCSRB,2);
			CLEAR_BIT(UCSRC,2);
			SET_BIT(UCSRC,1);
			break;
		case UART_CHARSIZE_8:
			CLEAR_BIT(UCSRB,2);
			CLEAR_BIT(UCSRC,2);
			SET_BIT(UCSRC,1);
			break;
		case UART_CHARSIZE_9:
			SET_BIT(UCSRB,2);
			SET_BIT(UCSRC,2);
			SET_BIT(UCSRC,1);
			break;
		default:
			CLEAR_BIT(UCSRB,2);
			CLEAR_BIT(UCSRB,2);
			SET_BIT(UCSRB,1);
			break;
	}

	//Selecting baudrate
	UBRRH = UARTConfig->u8BaudRateHigh;
	UBRRL = UARTConfig->u8BaudRateLow;


}

void UART_vidSendByte(u8 u8byteCpy) {
	while (GET_BIT(UCSRA,5) == 0); //Checking the UART Data Register Empty (UDRE) bit
	UDR = u8byteCpy;
}

u8 UART_u8ReceiveByte(void) {
	while (GET_BIT(UCSRA,7) == 0); //Checking the Receive Complete (RxE) bit
	return UDR;
}

u8 UART_u8GetReceivedByte(void)
{
	return UDR;
}

void UART_vidSendString(u8 * u8pStringCpy) {
	do {
		UART_vidSendByte(*u8pStringCpy);
	}while(*u8pStringCpy++ != '\0');
}

void UART_vidSendLine(void) {
	UART_vidSendString((u8*)"\n\r******\n\r");
}
