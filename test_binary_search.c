#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "binary_search.h"
#include "test_binary_search.h"

void test_search(int arr[], unsigned int size, int target)
{
	int index;		/* Target index */
	unsigned long long n_iters = 0;		/* iterations made by the inner loop of binary search */

	bool ok;

	/* Call the binary search function */
	index = binary_search(arr, size, target, &n_iters);

	/* Determine if target number has been found in the array */
	bool is_found = (index != -1);

	/* Check if correct */
	ok = is_found ? arr[index] == target : true;

	printf("target: %10d\tn_iters: %10llu\tnumber found? %s\tcorrect? %s\n",
		target, n_iters, is_found ? "true" : "false", ok ? "true" : "false");
}

void test_binary_search(int *sorted_arrays[][N_SEARCHES], unsigned int array_sizes[], unsigned int n_arrays)
{
	int target;

	printf("Testing the binary search function\n\n");

	/* For equal array sizes containing different values */
	for (unsigned int i = 0; i < n_arrays; i++)
	{
		/* Array size */
		unsigned int size = array_sizes[i];

		printf("\nARRAY SIZE: %d\n", size);

		printf("\nSearching existing elements\n\n");

		/* Do N_SEARCHES searches with an existing element*/
		for (unsigned int j = 0; j < N_SEARCHES; j++)
		{
			printf("SEARCH: %d\t", j);

			/* Get an array random position */
			unsigned int random_pos = rand() % size;
			target = sorted_arrays[i][j][random_pos];

			/* Do the search */
			test_search(sorted_arrays[i][j], size, target);
		}

		printf("\nSearching a non-existing element\n\n");

		/* Do N_SEARCHES searches with a non-existing element*/
		for (unsigned int j = 0; j < N_SEARCHES; j++)
		{
			printf("SEARCH: %d\t", j);

			/* Set the target as a number that we know does not exist */
			target = RAND_MAX + 1;

			/* Do the search */
			test_search(sorted_arrays[i][j], size, target);
		}
	}
}
