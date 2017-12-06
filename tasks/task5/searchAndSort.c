#include <stdio.h>

int calcOnArray(int [], int);
void search(int [],int);
void sort(int [],int,char);
void getMin(int [], int);
void getMax(int [], int);
void showArray(int [], int);
void fillArray(char);

int size,i;
char answer;
int close = 0;
int operation = 0;
int arr[100];

void main(void) {
	printf("Do you want an array?\n");
	scanf(" %c", &answer);
	fillArray(answer);
}

void fillArray(char answer) {
	while(1) {
		if(answer == 'y' || answer == 'Y') {
			printf("Enter the size:\n");
			scanf(" %d",&size);
			for(i = 1; i <= size; i++) {
				printf("Enter the element no. %d: ",i);
				scanf("%d",&arr[i-1]);
			}
			close = calcOnArray(arr,size);
			if (close == 1) {
				break;				
			}
		}
		else if(answer == 'n' || answer == 'N') {
			printf("Exiting..");
			break;
		}
		else {
			printf("Wrong answer!\n");
		}

	}
}

int calcOnArray(int arr[], int size) {
	while(1) {
		printf("------\n");
		printf("Select operation:\n");
		printf("1) Sort\n2) Search\n3) Get Max\n4) Get Min \n5) Show array\n6) Refill Array\n7) Exit\n");
		scanf("%d", &operation);
		switch(operation) {
			case 1:
				sort(arr,size,'u');
				break;
			case 2:
				search(arr,size);
				break;
			case 3:
				getMax(arr,size);
				break;
			case 4:
				getMin(arr, size);
				break;
			case 5:
				showArray(arr,size);
				break;
			case 6:
				fillArray(answer);
				break;
			case 7:
				return 1;
				break;
			default:
				printf("-----\n");
				printf("Invalid operation\n");
				break;
		}
	}
	return 0;
}
