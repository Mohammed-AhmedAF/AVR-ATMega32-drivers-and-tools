#include <stdio.h>
#include <stdlib.h>

void printArray(int *);
void doSelectionSort(int *);
int * arr;
int * cur;
int size;
int temp;
int min;
int ind;

void doSelectionSort(int *);
void main() {
	printf("Enter a size:\n");
	scanf("%d",&size);
	arr = malloc(sizeof(int)*size);
	fillArray(arr);
	printArray(arr);
	doSelectionSort(arr);
	printArray(arr);
}

void printArray(int * arr) {
	printf("\n");
	cur = arr;
	for (int i = 0; i < size; i++) {
		printf("%d ", *(cur+i));
	}
}

void doSelectionSort(int * arr) {
	cur = arr;
	for(int j = 0; j < size; j++){
		min = *(cur+j);
		for (int i = j+1; i < size; i++) {
			if (min >= *(cur+i)) {
				min = *(cur+i);
				ind = i;
			}
		}
		temp = *(cur+j);
		*(cur+j) = min;
		*(cur+ind) = temp;	
	}	
}

void fillArray(int * arr) {
	for (int i = 0; i < size; i++) {
		*(arr+i) = rand()%size+1;
	}
}


