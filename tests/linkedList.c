#include <stdio.h>
#include <stdlib.h>

struct node {
	int number;
	struct node * link;
} node;

void main() {
	int nodesNumber;
	int i,count = 0;
	struct node * start;
	struct node * current;
	struct node * previous;
	printf("What is the number of node?\n");
	scanf(" %d",&nodesNumber);
	/*creating and populating nodes*/
	for(i = 0; i < nodesNumber; i++) {
		printf("Creating list..\n");
		if(i == 0) {
			start = malloc(sizeof(node));
		}
		else if (i == 1) {
			current = malloc(sizeof(node));
			start->link = current;
		}
		else{
			previous = current;
			current = malloc(sizeof(node));
			previous->link = current;
		}
	}
	current->link = NULL;
	/*populating list*/
	printf("Populating list\n");
	current = start;
	for (i = 0; i < nodesNumber; i++) {
		current->number = i*i;
		current = current->link;
	}
	/*accessing list*/
	current = start;
	for (i = 0; i < nodesNumber; i++) {
		printf("%d\n",current->number);
		current = current->link;
	}
	/*Counting the nodes*/		
	current = start;
	while (current->link != NULL) {
		count++;
		current = current->link;
	}
	count++;
	printf("Count is %d\n",count);
}
