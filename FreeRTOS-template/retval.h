
/*
 * retval.h
 *
 * Created: 1/13/2020 5:01:34 PM
 *  Author: ahmad
 */ 
#ifndef RETVAL_H_
#define RETVAL_H_

#define ERROR_STATUS             uint8
#define E_OK                    0
#define E_NOK                    1

#define BCM_BASE_ERR                (100U)
#define TMU_BASE_ERR                (120U)
#define SOS_BASE_ERR                (140U)
#define KEYPAD_BASE_ERR                (160U)
#define LCD_BASE_ERR                (180U)
#define ADC_BASE_ERR                (180U)

#define SUCCESS                     (0U)
#define INVALID_ARGU_ERR            (1U)
#define NOT_INITIALIZED_ERR          (2U)
#define ALREADY_INITIALIZED_ERR      (3U)
#define NULL_PTR_ERR                 (4U)
#define RESOURCE_NOT_FOUND_ERR         (5U)
#define HW_CONSTRAIN_ERR            (6U)
#define BUFFER_FULL_ERR                (7U)
#define UART_ERR                    (8U)
#define SPI_ERR                        (9U)
#define TIMER_ERR                    (10U)
#define RESOURCE_NOT_AVAILABLE_ERR     (11U)
#define NOT_SUPPORTED_ERR            (12U)
#define BUFFER_NOT_ENOUGH_ERR        (13U)
#define CHECKSUM_ERR                (14U)
#endif