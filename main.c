#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "utils.h"
#include "tests.h"

void main()
{
	srand((unsigned int)time(NULL));

	printf("Generating random vectors...\n\n");

	int *test_arrays[N_MEASUREMENTS][N_SIZES];

	for (int i = 0; i < N_MEASUREMENTS; i++)
		for (int j = 0; j < N_SIZES; j++)
			test_arrays[i][j] = random_vect(ARRAY_SIZES[j]);

	printf("Starting the tests...\n\n");

	test_sort_functions(test_arrays);

	printf("Finished testing.\n");

	printf("Freeing memory...");

	for (int i = 0; i < N_MEASUREMENTS; i++)
		for (int j = 0; j < N_SIZES; j++)
			free(test_arrays[i][j]);

	printf("Done.");
}
