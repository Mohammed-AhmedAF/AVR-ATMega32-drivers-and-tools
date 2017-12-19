#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;
	struct node * next;
} node_t;

void showHelp();
void createLinkedList();


char answer[10];
int size;
node_t * current;
node_t * start;
node_t * previous;
int i;
void main() {
	printf("Show help (h); or build linked list (ll)\n");
	scanf("%s",&answer);
	if(strcmp(answer,"h") == 0) {
		showHelp();
	}
	else if (strcmp(answer,"ll") == 0){
		createLinkedList();
	}
}

void createLinkedList() {	
	printf("What is the initial size of the list?\n");
	scanf(" %d",&size);
	if(size > 0) {
		printf("Creating list..\n");
		start = malloc(sizeof(node_t));
		start->next = NULL;
		current = start;
		for (i = 2; i <= size;i++) {
			previous = current;
			current = malloc(sizeof(node_t));
			previous->next = current;
			current->next = NULL;
		}
	}
	else {
		printf("Invalid size.\n");
	}
}

void showHelp() {
	printf("This program allows you to create a linked list.\n");
	printf("You will be asked for an initial size of the linked list\n");
	printf("Then you may fill the linked list, and then you will be asked if you want");
	printf(" to grow the linked list and add more items.\n");
}
