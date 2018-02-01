#include <stdio.h>

typedef struct structa_tag {
	char c;
	short int s;
} structa_t;

typedef struct structb_tag {
	short int s;
	char c;
	int i;
} structb_t;

typedef struct structc_tag {
	char c;
	double d;
	int s;
} structc_t;

typedef struct structd_tag {
	double d;
	int s;
	char c;
} structd_t;

void main(void) {
	printf("Size of struct_a: %ld\n",sizeof(structa_t));
	printf("Size of struct_b: %ld\n",sizeof(structb_t));
	printf("Size of struct_c: %ld\n",sizeof(structc_t));
	printf("Size of struct_d: %ld\n",sizeof(structd_t));
}
