#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//Function to swap two elements. Used in bubble_sort
void swap (int *n, int *m)
{
	int aux = *n;
	*n = *m;
	*m = aux;
}

void bubble_sort(int arr[], int size, unsigned long long *count)
{
	int i, j;
	 //Main loop
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			++* count;
			//Swap elements if first number is bigger than its follower
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}
 //Function to print the final array
void print_array(int array[], int size)
{
	int i;
	for (i = 0; i < size; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}