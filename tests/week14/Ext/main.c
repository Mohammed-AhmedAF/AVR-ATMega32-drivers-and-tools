#include "Macros.h"
#include "Std_Types.h"
#include "DIO_interface.h"
#include <avr/io.h>
void main(void) {
	

	/*Configuring global interrupt*/
	SET_BIT(SREG,7)

	DIO_vidPinDirection(DIO_PORTD,2,0);
	DIO_vidPinValue(DIO_PORTD,2,1);

	/*MCUCR : Interrupt Sense Control*/
	SET_BIT(MCUCR,1);
	SET_BIT(MCUCR,0);

	/*GICR: External Interrupt Enable*/
	SET_BIT(GICR,6);

	/**/
	CLEAR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);

	/*Selecting left adjustment*/
	SET_BIT(ADMUX,5);

	/*Selecting channel*/
	SET_BIT(ADMUX,4);
	SET_BIT(ADMUX,3);
	SET_BIT(ADMUX,2);
	SET_BIT(ADMUX,1);
	SET_BIT(ADMUX,0);

	/*ADCSRA*/
	SET_BIT(ADCSRA,7);
	CLEAR_BIT(ADCSRA,6);
	SET_BIT(ADCSRA,5);
	SET_BIT(ADCSRA,4);
	SET_BIT(ADCSRA,3);
	SET_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);

	/*SFIOR*/
	CLEAR_BIT(SFIOR,7);
	SET_BIT(SFIOR,6);
	CLEAR_BIT(SFIOR,5);

}


