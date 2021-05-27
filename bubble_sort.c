#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "utils.h"

/*
	Description:
		Sorts an array by comparing each two elements starting at the beginning
		and moves the greatest element to the right. This proccess is repeated
		with one element less at each time.
*/
void bubble_sort(int arr[], int size, unsigned long long *count)
{
	int i, j;
	//Main loop
	
	for (i = 0; i < size - 1; i++)
	{ 
		for (j = 0; j < size - i - 1; j++)
		{
			++*count;
			//Swap elements if first number is bigger than its follower
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}
 