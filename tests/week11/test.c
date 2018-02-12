#include <stdio.h>

int calculateSum(int *);

void main(void) {
	
	int A[5] = {1,2,3,4,5};

	printf("Sum is %d\n", calculateSum(A));
}
int calculateSum(int * A) {
	int sum = 0;
	int size = sizeof(A)/sizeof(A[0]);
	printf("Size of A: %d\n",sizeof(A));
	printf("Size of one element: %d\n",sizeof(A[0]));
	for (int i = 0; i < size; i++) {
		sum += A[i];
	}
	return sum;
}


