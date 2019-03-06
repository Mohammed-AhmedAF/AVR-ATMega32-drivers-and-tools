#ifndef _GLCD_INTERFACE_H
#define _GLCD_INTERFACE_H

/*GLCD port number definition*/

#define GLCD_D0_PORT DIO_PORTA
#define GLCD_D1_PORT DIO_PORTA
#define GLCD_D2_PORT DIO_PORTA
#define GLCD_D3_PORT DIO_PORTA
#define GLCD_D4_PORT DIO_PORTA
#define GLCD_D5_PORT DIO_PORTA
#define GLCD_D6_PORT DIO_PORTA
#define GLCD_D7_PORT DIO_PORTA

#define GLCD_RS_PORT DIO_PORTB
#define GLCD_RW_PORT DIO_PORTB
#define GLCD_EN_PORT DIO_PORTB

#define GLCD_RST_PORT DIO_PORTD
#define GLCD_CS1_PORT DIO_PORTD
#define GLCD_CS2_PORT DIO_PORTD


/*GLCD pin number definition*/
#define GLCD_D0_PIN DIO_PIN0
#define GLCD_D1_PIN DIO_PIN1
#define GLCD_D2_PIN DIO_PIN2
#define GLCD_D3_PIN DIO_PIN3
#define GLCD_D4_PIN DIO_PIN4
#define GLCD_D5_PIN DIO_PIN5
#define GLCD_D6_PIN DIO_PIN6
#define GLCD_D7_PIN DIO_PIN7


#define GLCD_RS_PIN DIO_PIN0
#define GLCD_RW_PIN DIO_PIN1
#define GLCD_EN_PIN DIO_PIN2

#define GLCD_RST_PIN DIO_PIN0
#define GLCD_CS1_PIN DIO_PIN1
#define GLCD_CS2_PIN DIO_PIN2

/*Definition of GLCD commands*/
#define GLCD_DISPLAYOFF 0x3E
#define GLCD_SETYADD0 0x40
#define GLCD_SETXADD0 0xB8
#define GLCD_SETZADD0 0xC0
#define GLCD_DISPLAYON 0x3F


/*Function definitions*/
void GLCD_vidInit(void);
void GLCD_vidSendCommand(u8 u8Command);
void GLCD_vidWrite(u8 u8Data);


#endif
