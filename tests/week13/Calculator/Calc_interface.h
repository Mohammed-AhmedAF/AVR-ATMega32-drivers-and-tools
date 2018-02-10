#ifndef _CALC_H
#define _CALC_H
#include "Std_Types.h"
s8 Calc_s8ToNumber(u8 *, u8);
u8 u8GetSymbolPosition(u8 *);
s32 Calc_s32Power(u8, u8);
s8 s8GetResultSize(void);
void calc(void);
void vidPutInEquation(u8);
void vidShowResult(u8);

#endif
