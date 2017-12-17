#include <stdio.h>
#include <stdlib.h>
#include "types.h"

struct node {
	u32 number;
	struct node * link;
} node;

u32 i, numberOfNodes,count;
struct node * start;
struct node * current;
struct node * previous;

void main() {
	numberOfNodes = 5;
	/*Creating list*/
	for(i = 0; i < numberOfNodes; i++) {
		if(i == 0) {
			start = malloc(sizeof(node));
		}
		else if(i == 1) {
			current = malloc(sizeof(node));
			start->link = current;
		}
		else {
			previous = current;
			current = malloc(sizeof(node));
			previous->link = current;
		}	
	}
	current->link = NULL;
	printf("Linked list created.\n");
	/*filling linked list*/
	current = start;
	for (i = 0; i < numberOfNodes; i++) {
		printf("Number: ");
		scanf("%d",&current->number);
		current = current->link;
	}
	/*printing linked list contetns*/
	current = start;
	printf("-------\n");
	for(i = 0; i < numberOfNodes; i++){
		printf("%d\n",current->number);
		current = current->link;
	}
	/*Getting the number of nodes*/
	printf("------\n");
	current = start;
	while (current->link != NULL) {
		count++;
		current = current->link;
	}
	count++;
	printf("Number of element is %d",count);

}
