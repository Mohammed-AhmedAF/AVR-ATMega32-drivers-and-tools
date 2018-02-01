#include <stdio.h>

union test1 {
	int x;
	int y;
};

union test2 {
	int z;
	char a[6];
};

void main(void) {
	union test1 t1;
	union test2 t2;
	printf("Sizeof test1: %ld\n",sizeof(t1));
	printf("Size of test2: %ld\n",sizeof(t2));
	printf("Size of member: %ld\n",sizeof(t2.a));
}
