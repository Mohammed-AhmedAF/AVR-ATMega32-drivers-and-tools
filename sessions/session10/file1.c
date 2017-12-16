#include <stdio.h>
#include "types.h"

extern u16 x;

void sum(u16);

void main() {
	sum(6);
	printf("%d\n",x);
}
