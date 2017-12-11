#include <stdio.h>

typedef unsigned long int u32;

typedef struct strc {
	u32 x;
	u32 y;
}structTwo;

void swap ();

structTwo * pointer2a;
structTwo * pointer2b;

void main() {
	structTwo struct_a, struct_b;
	int x = 10;
	int y = 12;
	struct_a.x = x;
	struct_a.y = y;
	printf("Contents of struct a:\n");
	printf("X is %lu, y is %lu\n",struct_a.x,struct_a.y);
	
	struct_b.x = x + 5;
	struct_b.y = y + 5;
	printf("Contents of struct b:\n");
	printf("X is %lu, y is %lu\n",struct_b.x,struct_b.y);
	
	pointer2a = &struct_a;
	pointer2b = &struct_b;
	
	swap();
	printf("After Swapping\n");
	printf("Contetns of struct a:\n");
	printf("X is %lu, y is %lu\n",struct_a.x,struct_a.y);
	printf("Contents of struct b:\n");
	printf("Y is %lu, y is %lu\n",struct_b.x,struct_b.y);
}

void swap () {
	structTwo tempPointer;

	tempPointer = *pointer2a;

	*pointer2a = *pointer2b;

	*pointer2b = tempPointer;
}

