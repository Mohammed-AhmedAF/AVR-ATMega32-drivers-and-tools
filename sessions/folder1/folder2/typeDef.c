#include <stdio.h>
#include "./typeDef.h"

#define maxValue 70

void main() {
	s32 x = 8;
	printf("The value of x is %ld\n",x);
	x = maxValue;
	printf("The value of x is %ld\n",x);
}
