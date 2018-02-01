/*This code is to illustrate the data padding properties of structures*/
/*Order of definition of member variables in a structure will have an effect on the
 * overall size of the structure.
 * */
#include <stdio.h>

typedef struct test {
	char a;
	int x;
	char b;
} t1;

void main(void) {
	printf("Size of struct: %ld",sizeof(t1));
}
