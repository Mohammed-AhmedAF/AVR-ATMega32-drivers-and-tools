/*The aim of this program is to travers a linked list in revers*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node * next;
} Node;

void main() {
	Node * head;
	Node * current;
	Node * previous;
	int * dataArr = (int *) malloc(sizeof(Node)*5);
	int i,val;
	/*Filling linked list*/
	for(i = 0; i <= 8; i++) {
		if (i == 0) {
			head = malloc(sizeof(Node));
			head->data = i;
			head->next = NULL;
		}
		else if (i == 1){
			current = malloc(sizeof(Node));
			current->data = i;
			head->next = current;
		}
		else {
			previous = current;
			current = malloc(sizeof(Node));	
			current->data = i;
			previous->next = current;
			current->next = NULL;
		}	
	}
	/*Printing linked list contents*/
	current = head;
	i = 0;
	while(current != NULL)	{
		printf("%d", current->data);
		dataArr =&current->data;
		dataArr++;
		current = current->next;
		i++;
	}
	printf("\n");
	printf("In reverse\n");
	/*Printing in reverse*/
	while(i >= 0 )	{
		printf("%d\n",*(dataArr--));
		i--;
	}
}


