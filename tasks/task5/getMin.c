#include <stdio.h>

void getMin(int arr[],int size) {
	int i, min;
	min = arr[0];
	for(i = 1; i < size ; i++) {
		if(arr[i] < min) {
			min = arr[i];
		}
	}
	printf("Minimum is %d\n",min);

}
