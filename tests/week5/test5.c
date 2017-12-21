#include <stdio.h>

#define x 5

void main() {
	#if x == 5
		#error "Won't compile.\n"
	#endif
}
