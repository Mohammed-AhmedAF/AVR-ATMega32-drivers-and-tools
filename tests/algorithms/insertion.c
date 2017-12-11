#include <stdio.h>
#include <stdlib.h>

void createArray();
void showArray();
void doInsertionSort();

int arrSize;
int arr[100];
int current;

int i, j,temp;

void main() {
	printf("Enter array size:\n");
	scanf(" %d",&arrSize);
	
	createArray();
	showArray();
	doInsertionSort();
	showArray();
}
void createArray() {
	for(i = 0; i < arrSize; i++) {
		arr[i] = rand()%arrSize + 1;
	}
}

void doInsertionSort() {
	for(i = 1; i < arrSize; i++) {
		j = i;
		while (j > 0 && arr[j] < arr[j-1]) {
			temp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = temp;
			j--;
		}
	}
}

void showArray() {
	for (i = 0; i < arrSize; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
