#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H

#define ROW0_PORT DIO_PORTB
#define ROW0_PIN 0
#define ROW1_PORT DIO_PORTB
#define ROW1_PIN 1
#define ROW2_PORT DIO_PORTB
#define ROW2_PIN 2
#define ROW3_PORT DIO_PORTB
#define ROW3_PIN 3


#define COL0_PORT DIO_PORTB
#define COL0_PIN 4
#define COL1_PORT DIO_PORTB
#define COL1_PIN 5
#define COL2_PORT DIO_PORTB
#define COL2_PIN 6
#define COL3_PORT DIO_PORTB
#define COL3_PIN 7

#define HOLD_BUTTON

void KEYPAD_vidInit(void);
u8 KEYPAD_u8GetKey(void);

#endif
