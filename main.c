#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "vector.h"

void main()
{
	srand((unsigned int)time(NULL));

	printf("test;\n");

	int *arr = random_vect(1000);

	for (unsigned i = 0; i < 1000; i++)
		printf("%d ", arr[i]);
}
