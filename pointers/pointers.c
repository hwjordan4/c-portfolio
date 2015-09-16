#include <stdio.h>


int main()
{
	int j = 1;
	int k = 2;
	int *ptr;
	ptr = &k;

	printf("\n");
	printf("j has the value %d and is stored at %p\n", j, (void *)&j);
	printf("k has the value %d and is stored at %p\n", k, (void *)&k);
	printf("ptr has the value %p and is stored at %p\n", ptr, (void *)&ptr);
	printf("The value of the integer pointed to by ptr is %d\n", *ptr);

	return 0;

}
