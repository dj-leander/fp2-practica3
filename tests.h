#pragma once

#include <stdbool.h>

#define N_SIZES 5
#define N_MEASUREMENTS 5

#define N_SORT_FUNCTIONS 4

#define FUNC_DEF(func) { func, #func }

extern unsigned int ARRAY_SIZES[N_SIZES];

typedef void (*sort_function)(int arr[], unsigned int size, unsigned long long *n_iters);

typedef struct {
	sort_function func_ptr;
	char name[BUFSIZ];
} function_t;

void test_sort_functions(int *test_arrays[N_MEASUREMENTS][N_SIZES]);
