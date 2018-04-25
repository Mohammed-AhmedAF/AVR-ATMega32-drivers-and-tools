/*
 * Author: Mohammed Ahmed Abd Al-Fattah Mahmoud
 */

#ifndef _SPI_INTERFACE_H
#define _SPI_INTERFACE_H

void SPI_vidInitMaster(u8,u8,u8);
void SPI_vidInitSlave(u8,u8,u8);
u8 SPI_u8TransferByte(u8);
void SPI_vidEnableInterrupt(void);
void SPI_vidDisableInterrupt(void);

#define SPI_CLK_RISING 0
#define SPI_CLK_FALLING 1

#define SPI_CLK_PHASE_SAMPLE 0
#define SPI_CLK_PHASE_SETUP 1

#define SPI_CLK_FREQ_4 0
#define SPI_CLK_FREQ_16 1
#define SPI_CLK_FREQ_64 2
#define SPI_CLK_FREQ_128 3
#define SPI_CLK_FREQ_2 4
#define SPI_CLK_FREQ_8 5
#define SPI_CLK_FREQ_32 6
#define SPI_CLK_FREQ_64_DOUBLE 7


#endif

