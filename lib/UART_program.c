/*
 * Author: Mohammed Ahmed Abd Al-Fattah Mahmoud
 * Purpose: UART driver for Atmega32
 */

#include "SETTINGS_interface.h"
#include "Macros.h"
#include "Std_Types.h"
#include "DIO_interface.h"
#include "UART_private.h"
#include "UART_interface.h"

#ifdef ST_MC_ATMEGA1632
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
#endif

#ifdef ST_MC_ATMEGA128
void UART_vidInitExtended(u8 u8ChannelNumber) {
	if (u8ChannelNumber == UART_CHANNEL0) {
		/*Enabling receiver and transmitter*/
		SET_BIT(UCSR0B,4);
		SET_BIT(UCSR0B,3);
		/*Setting no parity*/
		CLEAR_BIT(UCSR0C,4);
		CLEAR_BIT(UCSR0C,5);
		/*Setting number of stop bits*/
		SET_BIT(UCSR0C,3);
		/*Character size*/
		CLEAR_BIT(UCSR0B,2);
		SET_BIT(UCSR0C,2);
		SET_BIT(UCSR0C,1);
		/*Selecting baudrate*/
		UBRR0H = 0;
		UBRR0L = 51;
	}
	else {
		/*Enabling receiver and transmitter*/
		SET_BIT(UCSR1B,4);
		SET_BIT(UCSR1B,3);
		/*Setting no parity*/
		CLEAR_BIT(UCSR1C,4);
		CLEAR_BIT(UCSR1C,5);
		/*Setting number of stop bits*/
		SET_BIT(UCSR1C,3);
		/*Character size*/
		CLEAR_BIT(UCSR1B,2);
		SET_BIT(UCSR1C,2);
		SET_BIT(UCSR1C,1);
		/*Selecting baudrate*/
		UBRR1H = 0;
		UBRR1L = 103;
	}
}
#endif

#ifdef ST_MC_ATMEGA1632
void UART_vidSendByte(u8 u8byteCpy) {
	while (GET_BIT(UCSRA,5) == 0); //Checking the UART Data Register Empty (UDRE) bit
	UDR = u8byteCpy;
}
#endif

#ifdef ST_MC_ATMEGA128
void UART_vidSendByteExtended(u8 u8ChannelNumber, u8 u8ByteCpy) {
	switch(u8ChannelNumber) {
		case UART_CHANNEL0:
			while(GET_BIT(UCSR0A,5) == 0);
			UDR0 = u8ByteCpy;
		break;
		case UART_CHANNEL1:
			while(GET_BIT(UCSR1A,5) == 0);
			UDR1 = u8ByteCpy;
		break;
	}
}
#endif

#ifdef ST_MC_ATMEGA1632
u8 UART_u8ReceiveByte(void) {
	while (GET_BIT(UCSRA,7) == 0); //Checking the Receive Complete (RxE) bit
	return UDR;
}
#endif

#ifdef ST_MC_ATMEGA128
u8 UART_u8ReceiveByteExtended(u8 u8ChannelNumber) {
	switch(u8ChannelNumber) {
		case UART_CHANNEL0:
			while (GET_BIT(UCSR0A,7) == 0);
			return UDR0;
		break;
		case UART_CHANNEL1:
			while (GET_BIT(UCSR1A,7) == 0);
			return UDR1;
		break;
	}
}
#endif


#ifdef ST_MC_ATMEGA1632
void UART_vidSendString(u8 * u8pStringCpy) {
	do {
		UART_vidSendByte(*u8pStringCpy);
	}while(*u8pStringCpy++ != '\0');
}
#endif

#ifdef ST_MC_ATMEGA1632
void UART_vidSendLine(void) {
	UART_vidSendString((u8*)"\n\r******\n\r");
}
#endif
