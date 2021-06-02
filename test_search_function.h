#pragma once
#include <stdio.h>
 
#define N_SEARCH_MEASUREMENTS 10 
#define N_RIGHT_MEASUREMENTS N_SEARCH_MEASUREMENTS / 2
#define N_SEARCH_SIZES 7

extern unsigned int SEARCH_ARRAY_SIZES[N_SEARCH_SIZES];

void test_search_function(int *sorted_arrays[N_SEARCH_SIZES][N_SEARCH_MEASUREMENTS]);
