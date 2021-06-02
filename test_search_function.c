#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "binary_search.h"
#include "test_search_function.h"

unsigned int SEARCH_ARRAY_SIZES[N_SEARCH_SIZES] = { 1000, 5000, 10000, 25000, 30000, 50000, 100000};

void test_search_function(int *sorted_arrays[N_SEARCH_SIZES][N_SEARCH_MEASUREMENTS], int target)
{
	clock_t start, end;
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

			/* RECORD TIME AT THE START (Start stopwatch) */
			start = clock();

			/* Call the binary search function */
			mid = binary_search(sorted_arrays[i][j], size, target, &n_iters);

			/* RECORD TIME AT THE END (Stop stopwatch) */
			end = clock();

			double time_elapsed = ((double)end - start) / CLOCKS_PER_SEC;
 
			total_time += time_elapsed;

			/* Determine if target number has been found in the array */
			bool target_is_found = (mid != -1);

			printf("MEASURE: %d\ttime elapsed: %f s\tn_iters: %10llu\tnumber found? %s\n",
				j, time_elapsed, n_iters, target_is_found ? "true" : "false");
		}

		printf("Total time: %f s\taverage: %f s\n\n", total_time, total_time / N_SEARCH_MEASUREMENTS);
	}
}
