#include <stdio.h>

int main() {
	int numbers [] = {5, 5, 6, 3, 7, 8};
	int size = sizeof(numbers)/sizeof(int);
	printf("%d\n",size);
	return 0;
}
