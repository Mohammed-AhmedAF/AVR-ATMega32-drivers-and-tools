#ifndef MACROS_H
#define MACROS_H

#define Set_Bit(reg,bit) reg |= (1<<bit)
#define Clear_Bit(reg,bit) reg &= ~(1<<bit)
#define Get_Bit(reg,bit) (reg>>bit)&1
#define Toggle_Bit(reg,bit) (reg ^= (1<<bit))
#endif
