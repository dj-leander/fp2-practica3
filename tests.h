#pragma once

#include <stdbool.h>

#define N_MEASUREMENTS 5

#define N_SORT_FUNCTIONS 5

#define FUNC_DEF(func) { func, #func }

typedef void (*sort_function)(int arr[], unsigned int size, unsigned long long *n_iters);

typedef struct {
	sort_function func_ptr;
	char name[BUFSIZ];
} function_t;

void test_sort_functions(int *test_arrays[][N_MEASUREMENTS], unsigned int array_sizes[], unsigned int n_arrays);
