#include "DIO_interface.h"
#include "Std_Types.h"
#include "Macros.h"
#include "UART_interface.h"
#include <util/delay.h>
void Test_vidCheck(void);
void Test_vidSend(void);

u8 u8character = 0;
void main(void) {
	DIO_vidSetPinValue(DIO_PORTA,DIO_PIN0,1);
	DIO_vidSetPinValue(DIO_PORTA,DIO_PIN1,1);
	UART_vidInit();
	while(1) {
		Test_vidSend();
	}
}  

void Test_vidCheck(void) {
	if(UART_vidReceiveByte() == 'a') {
		TOGGLE_BIT(PORTA,0);
	}
	else if(UART_vidReceiveByte() == 'b') {
		TOGGLE_BIT(PORTA,1);
	}
}

void Test_vidSend(void) {
	_delay_ms(1000);
	u8character = UART_vidReceiveByte();	
	switch(u8character) {
		case 'a':
			UART_vidSendString("Apple ");
			UART_vidSendByte('\n');
			break;
		case 'b':
			UART_vidSendString("Book ");
			break;
		case 'c':
			UART_vidSendString("Car ");
			break;
		default:
			UART_vidSendString("World ");
			break;
	}
}

