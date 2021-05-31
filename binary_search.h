#pragma once

int binary_search_aux(int arr[], unsigned int low, unsigned int high, int target, unsigned long long *n_iters);

int binary_search(int arr[], unsigned int size, int target, unsigned long long *n_iters);
