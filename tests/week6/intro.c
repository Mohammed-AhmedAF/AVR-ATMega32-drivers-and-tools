#include <stdio.h>

unsigned short a = 0xFFFF;
void main() {
a = ~(a^(a<<4));
printf("%x",a);
}
