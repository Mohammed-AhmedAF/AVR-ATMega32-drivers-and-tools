#include "DIO_interface.h"
#include "Std_Types.h"
#include "Macros.h"
#include "UART_interface.h"
#include <util/delay.h>
void Test_vidCheck(void);
void Test_vidSend(void);
void main(void) {
	DIO_vidSetPinValue(DIO_PORTA,DIO_PIN0,1);
	DIO_vidSetPinValue(DIO_PORTA,DIO_PIN1,1);
	UART_vidInit();
	while(1) {
		Test_vidCheck();
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
	UART_vidSendByte('a');
	_delay_ms(1000);	
	UART_vidSendByte('b');
	_delay_ms(1000);

}
