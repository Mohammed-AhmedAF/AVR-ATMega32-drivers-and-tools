#include <stdio.h>
#include <stdlib.h>
#include "types.h"

void fillArray(u32 *);
void doInsertionSort(u32 *,u8);
void printArray(u32 *);
u32 size;
u32 * arr;
u32 temp;
u32 * current;
void main() {
	printf("Enter array size:\n");
	scanf("%d",&size);
	arr = malloc(sizeof(u32)*size);

	fillArray(arr);
	printArray(arr);
	doInsertionSort(arr,'d');
	printArray(arr);
}

void fillArray(u32 * arr) {
	current = arr;
	for (int i = 0; i < size; i++) {
		*(current+i) = rand()%size+1;
	}
}

void printArray(u32 * arr) {
	printf("\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", *(current+i));
	}
}

void doInsertionSort(u32 * arr, u8 order) {
	current = arr;
	int j = 0;
	for (int i = 0; i < size; i++) {
		j = i;
		if (order == 'a') {
			while (j >= 0) {
				if (*(current+j)> *(current+j+1)) {
					temp = *(current+j+1);
					*(current+j+1) = *(current+j);
					*(current+j) = temp;
				}
				j--;
			}
		}
		else {
			while (j >= 0) {
				if (*(current+j) < *(current+j+1)) {
					temp = *(current+j);
					*(current+j) = *(current+j+1);
					*(current+j+1) = temp;
				}
				j--;
			}
		}
	}
}
