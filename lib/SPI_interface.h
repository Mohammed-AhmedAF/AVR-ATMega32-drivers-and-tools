/*
 * Author: Mohammed Ahmed Abd Al-Fattah Mahmoud
 */

#ifndef _SPI_INTERFACE_H
#define _SPI_INTERFACE_H

void SPI_vidInitMaster(void);
void SPI_vidInitSlave(void);
void SPI_vidEnableSS(void);
void SPI_vidDisableSS(void);
void SPI_vidTransferByte(u8);
u8 SPI_u8ReceiveByte(void);
void SPI_vidEnableInterrupt(void);
void SPI_vidDisableInterrupt(void);

/*Definitions of pins and ports*/
#define SPI_MOSI_PORT DIO_PORTB
#define SPI_MOSI_PIN DIO_PIN5
#define SPI_MISO_PORT DIO_PORTB
#define SPI_MISO_PIN DIO_PIN6
#define SPI_SCK_PORT DIO_PORTB
#define SPI_SCK_PIN DIO_PIN7
#define SPI_SS_PORT DIO_PORTB
#define SPI_SS_PIN DIO_PIN4


#ifdef ST_MC_ATMEGA128
#define SPI_MOSI_PORT DIO_PORTB
#define SPI_MOSI_PIN DIO_PIN2
#define SPI_MISO_PORT DIO_PORTB
#define SPI_MISO_PIN DIO_PIN3
#define SPI_SCK_PORT DIO_PORTB
#define SPI_SCK_PIN DIO_PIN1
#define SPI_SS_PORT DIO_PORTB
#define SPI_SS_PIN DIO_PIN0
#endif

#define SPI_CLK_RISING 0
#define SPI_CLK_FALLING 1

#define SPI_CLK_PHASE_SAMPLE 0
#define SPI_CLK_PHASE_SETUP 1

#endif

