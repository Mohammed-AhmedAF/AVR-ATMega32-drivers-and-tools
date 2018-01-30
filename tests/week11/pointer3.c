#include<stdio.h>

void main(void) {
	int val = 9;
	int * pVal = &val;
	printf("Value of val is %d",*pVal);
	:
	printf("Value of incremented pointed is %p\n",pVal+1);
}
