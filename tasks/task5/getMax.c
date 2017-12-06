#include <stdio.h>

void getMax(int arr[], int size) {
	int max, i;
	max = arr[0];
	for(i = 1; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	printf("Maximum is %d\n", max);
	/*Refill array*/
	for (i = 0; i < size; i++) {
		arr[i] = max++; 
	}
}
