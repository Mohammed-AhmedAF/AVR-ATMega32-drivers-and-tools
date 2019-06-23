/*
 * Author: Mohammed Ahmed Abd Al-Fattah Mahmoud
 */

#ifndef _SPI_INTERFACE_H
#define _SPI_INTERFACE_H

void SPI_vidInitMaster(void);
void SPI_vidEnableSS(void);
void SPI_vidDisableSS(void);
void SPI_vidTransferByte(u8);
void SPI_vidEnableInterrupt(void);
void SPI_vidDisableInterrupt(void);

#define SPI_CLK_RISING 0
#define SPI_CLK_FALLING 1

#define SPI_CLK_PHASE_SAMPLE 0
#define SPI_CLK_PHASE_SETUP 1

#endif

