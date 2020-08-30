/******************************************************************************
 *    File Name: Mahmoud Saad
 *
 *     Description: source file for my_itoa function
 *
 *     Author: Mahmoud Saad
 *
 *    Created on: Apr 29, 2019
 *
 *******************************************************************************/
#include "std_types_i.h"
#include "my_stdlib.h"

/*******************************************************************************
 *            Private functions Prototypes
 *******************************************************************************/

static void my_reverse(uint8 *src, uint8 length);


/*******************************************************************************
 *            Functions Definitions
 *******************************************************************************/


void my_reverse(uint8 *src, uint8 length)
{
    uint8 i;
    uint8 reverseBuffer[length];
    if ( NULL_PTR != reverseBuffer)
    {
        for(i = 0; i < length; i++)
        {
            *(reverseBuffer + length - i - 1) =  *(src + i);
        }

        for( i = 0; i < length; i++)
        {
            *(src + i) = *(reverseBuffer + i);
        }
    }
}
void my_itoa(sint32_t data, uint8 * ptr, uint32_t base)
{
    /* variable definitions */
    uint8 digits = 0;
    uint8 last_digit;
    uint8 i = 0;

    /* if data is zero, store zero into array ( * ptr ) and return it */
    if(data == 0)
    {
        *( ptr + i ) = '0';
        i++;
    }
    else
    {
        /* if data is non- zero. check if it is less than zero
         * and the base is BASE_10. take negative sign and
         * multiply data by -1.
         */
        while(data != 0)
        {
            last_digit = data % base;
            *( ptr + i ) = (last_digit >= 10) ? last_digit - 10 + 'A' : last_digit + '0';
            data /= base;
            i++;
            digits++;
        }
        my_reverse( ptr, digits );
        *( ptr + i ) = '\0';
    }
    *( ptr + i ) = '\0';
}
