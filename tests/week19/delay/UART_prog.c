#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "UART_interface.h"
#include <avr/io.h>

void UART_vidInit(void) {	

	//Setting both Receive Enabel and Transmit Enable
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

void UART_vidSendByte(u8 u8byteCpy) {
	while (GET_BIT(UCSRA,5) == 0); //Checking the UART Data Register Empty (UDRE) bit
	UDR = u8byteCpy;
}

u8 UART_u8ReceiveByte(void) {
	while (GET_BIT(UCSRA,7) == 0); //Checking the Receive Complete (RxE) bit
	return UDR;
}

void UART_vidSendString(u8 * u8pStringCpy) {
	do {
		UART_vidSendByte(*u8pStringCpy);
	}while(*u8pStringCpy++ != '\0');
}

void UART_vidSendLine(void) {
	UART_vidSendString("\n\r******\n\r");
}
