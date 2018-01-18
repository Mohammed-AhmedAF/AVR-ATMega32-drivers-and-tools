#ifndef _CALC_H
#define _CALC_H
#include "Std_Types.h"
u32 Calc_u32ToNumber(u8 *, u8);
u32 Calc_u32Power(u8, u8);
u8 u8GetSignPosition(u8 eqCpy[]);
u8 u8GetResultSize(void);
void vidPack(u8 *, u8); 
void calc(void);
void vidPutInEquation(u8);
void vidShowResult(void);


#endif
