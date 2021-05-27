#pragma once

unsigned partition(int arr[], unsigned left, unsigned right);

void quick_sort_aux(int arr[], unsigned left, unsigned right, unsigned long long *n_iters);

void quick_sort(int arr[], unsigned size, unsigned long long *n_iters);
