#include <stdio.h>

int calculateSum(int *, int);

void main(void) {
	
	int A[5] = {1,2,3,4,5};
	int size = sizeof(A)/sizeof(A[0]);
	int sum = calculateSum(A,size);
	printf("Sum is %d\n", sum);
}
int calculateSum(int * A, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += A[i];
	}
	return sum;
}


