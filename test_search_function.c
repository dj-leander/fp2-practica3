#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "binary_search.h"
#include "test_search_function.h"

unsigned int SEARCH_ARRAY_SIZES[N_SEARCH_SIZES] = { 1000, 5000, 10000, 25000, 30000, 50000, 100000};

void test_search_function(int *sorted_arrays[N_SEARCH_SIZES][N_SEARCH_MEASUREMENTS])
{
	int target;
	int mid;		/* Target number position */

	printf("Testing the binary search function\n\n");

	/* For equal array sizes containing different values */
	for (int i = 0; i < N_SEARCH_SIZES; i++)
	{
		/* Array size */
		unsigned int size = SEARCH_ARRAY_SIZES[i];

		printf("ARRAY SIZE: %d\n", size);

		/* Total time */
		double total_time = 0;

		/* Do multiple measurements */
		for (int j = 0; j < N_SEARCH_MEASUREMENTS; j++)
		{
			/* Prepare parameters for the binary search function */
			unsigned long long n_iters = 0;		/* iterations made by the inner loop of binary search */ 

			/* Perform binary searches for elements that we know already exist */
			if (j < N_RIGHT_MEASUREMENTS)
			{ 
				/* Get an array random position */
				unsigned int random_pos = rand() % size; 
				target = sorted_arrays[i][j][random_pos];
			} 
			else 
				/* Set the target as a number that we know does not exist */
				target = RAND_MAX + 1;

			/* Call the binary search function */
			mid = binary_search(sorted_arrays[i][j], size, target, &n_iters); 

			/* Determine if target number has been found in the array */
			bool target_is_found = (mid != -1);

			printf("MEASURE: %d\ttarget: %10d\tn_iters: %10llu\tnumber found? %s\n",
				j, target, n_iters, target_is_found ? "true" : "false");
		} 
	}
}
