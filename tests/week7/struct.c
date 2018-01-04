#include <stdio.h>
#include <stdlib.h>

void build(int);
void show(int);

typedef struct Struct_t {
	int id;
	struct node * next;
}node;;

int size;
node * start;
node * current;
node * prev;
int i;	
void main() {
printf("Enter size:\n");
	scanf("%d",&size);

	build(size);
	show(size);
}

void build(int size) {
	if (size > 1) {
		start = malloc(sizeof(node));
		start->next = NULL;
		current = start;
	}

	for (i = 1; i < size; i++) {
		prev = current;
		current = malloc(sizeof(node));
		current->id = i;
		prev->next = current;
	}
}

void show(size) {
	current = start;
	for (i = 0; i <size; i++) {
		printf("%d\n",current->id);
		current = current->next;
	}
}
