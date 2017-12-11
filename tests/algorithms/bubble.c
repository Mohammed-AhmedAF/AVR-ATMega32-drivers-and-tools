#include <stdio.h>
#include <stdlib.h>

int arrSize;

int arr[100];
int i, j, temp;

void createArray();
void doBubbleSort();

void main() {
	printf("Enter array size: \n");
	scanf(" %d",&arrSize);
	createArray();
	doBubbleSort();
	showArray();
}

void createArray() {
	for (i = 0; i < arrSize; i++) {
		arr[i] = rand()%arrSize+1;
	}
}

void showArray() {
	for(i = 0; i <arrSize; i++) {
		printf("%d ",arr[i]);
	}
}

void doBubbleSort() {
	for(i = 0; i < arrSize;i++) {
		for(j = 0; j < arrSize-1-i; j++) {
			if(arr[j] > arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
