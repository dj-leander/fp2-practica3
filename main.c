#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "utils.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"

void main()
{
	srand((unsigned int)time(NULL));

	printf("test;\n");

	int *arr_10 = random_vect(10);
	int *arr_100 = random_vect(100);
	int *arr_1000 = random_vect(1000);
	int *arr_10000 = random_vect(10000);
	int *arr_100000 = random_vect(100000);
	
	unsigned long long n_iters = 0;
	/*
	selection_sort(arr_10, 10, &n_iters);
	printf("n_iters 10 = %llu\n", n_iters);

	n_iters = 0;
	selection_sort(arr_100, 100, &n_iters);
	printf("n_iters 100 = %llu\n", n_iters);

	n_iters = 0;
	selection_sort(arr_1000, 1000, &n_iters);
	printf("n_iters 1000 = %llu\n", n_iters);

	n_iters = 0;
	selection_sort(arr_10000, 10000, &n_iters);
	printf("n_iters 10000 = %llu\n", n_iters);

	n_iters = 0;
	selection_sort(arr_100000, 100000, &n_iters);
	printf("n_iters 100000 = %llu\n", n_iters);
	*/

	/*
	n_iters = 0;
	insertion_sort(arr_10, 10, &n_iters);
	printf("n_iters 10 = %llu\n", n_iters);

	n_iters = 0;
	insertion_sort(arr_100, 100, &n_iters);
	printf("n_iters 100 = %llu\n", n_iters);

	n_iters = 0;
	insertion_sort(arr_1000, 1000, &n_iters);
	printf("n_iters 1000 = %llu\n", n_iters);

	n_iters = 0;
	insertion_sort(arr_10000, 10000, &n_iters);
	printf("n_iters 10000 = %llu\n", n_iters);

	n_iters = 0;
	insertion_sort(arr_100000, 100000, &n_iters);
	printf("n_iters 100000 = %llu\n", n_iters);
	*/

	n_iters = 0;
	bubble_sort(arr_10, 10, &n_iters);
	printf("n_iters 10 = %llu\n", n_iters);

	n_iters = 0;
	merge_sort(arr_10, 10, &n_iters);
	printf("n_iters 10 = %llu\n", n_iters);

	n_iters = 0;
	merge_sort(arr_100, 100, &n_iters);
	printf("n_iters 100 = %llu\n", n_iters);

	n_iters = 0;
	merge_sort(arr_1000, 1000, &n_iters);
	printf("n_iters 1000 = %llu\n", n_iters);

	n_iters = 0;
	merge_sort(arr_10000, 10000, &n_iters);
	printf("n_iters 10000 = %llu\n", n_iters);

	n_iters = 0;
	merge_sort(arr_100000, 100000, &n_iters);
	printf("n_iters 100000 = %llu\n", n_iters);
}
