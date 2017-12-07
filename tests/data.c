#include <stdio.h>

int add(int a, int b) {
	int c = a + b;
	return c;
	}

int main() {
	int a = 5;
	int b = 6;
	char c = 'a';
	printf("The value of a is %d \n", a);
	printf("The value of b is %d \n", b);
	printf("The value of c is %c \n", c);
	int sum = add(a,b);
	printf("Sum is %d\n", sum);
	return 0;
}

