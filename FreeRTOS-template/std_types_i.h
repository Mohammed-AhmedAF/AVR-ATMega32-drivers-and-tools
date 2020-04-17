/*
 * std_types.h
 *
 *  Created on: Dec 22, 2019
 *      Author: ahmad
 */

#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_

/************************************************************************/
/*                   typedefs for standard types                        */
/************************************************************************/

#define NULL    ((void *)0)

typedef unsigned char uint8;
typedef unsigned int uint16;
typedef unsigned long int uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed int sint16;
typedef signed long int sint32;
typedef signed long long sint64;
typedef volatile uint8* const reg_type8;
typedef volatile uint16* const reg_type16;
typedef float float32;

typedef unsigned char boolean_t;
typedef signed long int sint32_t;
typedef unsigned long int uint32_t;

typedef unsigned char boolean;

typedef void (*gptrfu_UserCbk)(void);

#define BLOW                      (0)
#define BHIGH                     (1)

#define ZERO                    (0)

/************************************************************************/
/*                          defining error status                             */
/************************************************************************/
/*#define ERROR_STATUS             uint8
#define E_OK                    0
#define E_NOK                    1*/


/************************************************************************/
/*                           defining bool values                             */
/************************************************************************/
typedef uint8 bool;
#define FALSE                     0
#define TRUE                     1


/************************************************************************/
/*                         LOW/HIGH defines                                 */
/************************************************************************/
#define LOW                      0
#define HIGH                     0xFF

#define F_CPU (16000000UL)
#define ZERO_INITIALIZATION     (0)
#define ONE_INITIALIZATION      (1)
#define DEBUGTEST               (0)

#endif /* _STD_TYPES_H_ */