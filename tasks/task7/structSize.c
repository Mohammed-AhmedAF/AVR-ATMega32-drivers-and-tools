#include <stdio.h>

struct struct_a {
	double a;
	int b;
	char c;
};

struct struct_b  {
	int a;
	double b;
 	char c;
};

void main() {
	struct struct_a strct_a;
	struct struct_b strct_b;
	
	printf("Size of student is %zd\n",sizeof(strct_a));
	printf("Size of schuler is %zd\n",sizeof(strct_b));
}
