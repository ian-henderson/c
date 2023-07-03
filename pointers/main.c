#include <stdio.h>

int main() {
	int a = 0;
	int* ptr = &a;

	a += 1;
	*ptr += 1;
	printf("a:\t%d\n", a);
	printf("ptr:\t%d\n", *ptr);

	return 0;
}
