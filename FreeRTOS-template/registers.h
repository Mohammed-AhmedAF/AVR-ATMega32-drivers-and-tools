/*
 * registers.h
 *
 *  Created on: Oct 21, 2019
 *      Author: Sprints
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "std_types_i.h"

/*
 * General Registers
 */
#define MCUCR    *((reg_type8)(0x55))
#define MCUCSR    *((reg_type8)(0x54))
#define GICR    *((reg_type8)(0x5B))
#define GIFR    *((reg_type8)(0x5A))

/*
 * PORTx registers
 */

#define PORTA_DATA     *((reg_type8)(0x3B))
#define PORTA_DIR      *((reg_type8)(0x3A))
#define PORTA_PIN    *((reg_type8)(0x39))

#define PORTB_DATA     *((reg_type8)(0x38))
#define PORTB_DIR      *((reg_type8)(0x37))
#define PORTB_PIN    *((reg_type8)(0x36))

#define PORTC_DATA     *((reg_type8)(0x35))
#define PORTC_DIR      *((reg_type8)(0x34))
#define PORTC_PIN    *((reg_type8)(0x33))


#define PORTD_DATA     *((reg_type8)(0x32))
#define PORTD_DIR      *((reg_type8)(0x31))
#define PORTD_PIN    *((reg_type8)(0x30))


/*
 * General Timer registers
 */
#define TIMSK        *((reg_type8)(0x59))
#define TIFR        *((reg_type8)(0x58))


/*
 * Timer 0 Registers
 */

#define TCCR0        *((reg_type8)(0x53))
#define TCNT0        *((reg_type8)(0x52))
#define OCR0        *((reg_type8)(0x5C))


/*
 * Timer 1 Registers
 */

#define TCCR1A        *((reg_type8)(0x4F))
#define TCCR1B        *((reg_type8)(0x4E))
#define TCCR1        *((reg_type16)(0x4E))
#define TCNT1H        *((reg_type8)(0x4D))
#define TCNT1L        *((reg_type8)(0x4C))
#define TCNT1        *((reg_type16)(0x4C))
#define OCR1AH        *((reg_type8)(0x4B))
#define OCR1AL        *((reg_type8)(0x4A))
#define OCR1A        *((reg_type16)(0x4A))
#define OCR1BH        *((reg_type8)(0x4F))
#define OCR1BL        *((reg_type8)(0x48))
#define OCR1B        *((reg_type16)(0x48))
#define ICR1H        *((reg_type8)(0x47))
#define ICR1L        *((reg_type8)(0x46))
#define ICR1        *((reg_type16)(0x46))


/*
 * Timer 2 Registers
 */
#define TCCR2        *((reg_type8)(0x45))
#define TCNT2        *((reg_type8)(0x44))
#define OCR2        *((reg_type8)(0x43))








#endif /* REGISTERS_H_ */