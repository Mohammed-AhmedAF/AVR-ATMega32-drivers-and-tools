#include <stdio.h>
#include <stdlib.h>

int arr[100];
int i,j,temp,arrSize,x;
int algorithm;
char answer;
void showArray();
void createArray();
void doBubbleSort();
void doInsertionSort();
void doSelectionSort();

void main() {
	printf("Enter array size:\n");
	scanf(" %d",&arrSize);
	printf("What do you want to do?\n");
	scanf(" %c",&answer);
	if (answer == 'e' || answer == 'E') {
		arrSize = 6;
		arr[0] = 1;
		arr[1] = 3;
		arr[2] = 5;
		arr[3] = 4;
		arr[4] = 2;
		arr[5] = 6;
	}
	else {
		createArray();
	}
	printf("Choose sorting algorithm:\n");
	printf("1) Bubble sort.\n2) Insertion sort.\n3) Selection sort.\n");
	scanf(" %d",&algorithm);

	switch(algorithm) {
		case 1:
			doBubbleSort();
			break;
		case 2:
			doInsertionSort();
			break;
		case 3:
			doSelectionSort();
			break;
		default:
			printf("Wrong number\n");
			break;
	}
}

void createArray() {
	for (i = 0; i < arrSize; i++) {
		arr[i] = rand()%arrSize+1;
	}
}

void doBubbleSort() {
	for(i = 0; i < arrSize; i++) {
		for (j = 1; j < arrSize - i; j++) {
			if(arr[j] < arr[j-1]) {
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
		showArray();
	}
}

void showArray() {
	for(x = 0; x < arrSize; x++) {
		printf("%d ",arr[x]);
	}
	printf("\n");
}

void doSelectionSort() {
	int ind;
	int min;
	for(i = 0; i < arrSize; i++) {
		min = arr[i];
		for(j = i; j < arrSize; j++) { 
			if(min >= arr[j]) {
			 min = arr[j];
			 ind =j;
			}
		}
			arr[ind] = arr[i];
			arr[i] = min;
			showArray();
	}
}

void doInsertionSort() {
	printf("What");
}
