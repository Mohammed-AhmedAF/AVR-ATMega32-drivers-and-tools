#include <stdio.h>

typedef unsigned short int u16;
typedef unsigned long int u32;
typedef unsigned char u8;
typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef double s64;
typedef long double s128;
typedef float f32;

void main() {
	printf("%zd\n",sizeof(double));
	
	printf("Size of short int :%zd\n",sizeof(u16));
	printf("Size of long int : %zd\n",sizeof(u32));
	printf("size of double : %zd\n",sizeof(s64));
	printf("size of signed long int : %zd\n",sizeof(s32));
	printf("size of long double : %zd\n",sizeof(s128));
	printf("size of float : zd\n",sizeof(f32));
}
