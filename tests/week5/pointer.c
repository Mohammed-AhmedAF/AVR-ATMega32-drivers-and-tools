/*testing calloc(no_elements,size_element_in_byte)*/

#include <stdio.h>
#include <stdlib.h>

void main() {
	int i;
	int * p = calloc(8,sizeof(int));
	/*Filling element*/
	for(i = 0; i < 8; i++) {
		*p = i;
		p++;
	}
	/*Printing array contents*/
	for(i = 0; i < 8;i++)	{
		printf("%d\n",*p);
		p--;
	}
}
