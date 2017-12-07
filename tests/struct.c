#include <stdio.h>

struct Person {
	char name[20];
	int age;
};

int main() {
	struct Person person1;
	printf("Enter a name:\n");
	scanf("%s",person1.name);
	printf("%s\n",person1.name);	
	return 0;
}
