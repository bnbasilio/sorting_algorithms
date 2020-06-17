#include "sort.h"

/**
 * swap - swaps 2 elements of an array
 * @x: first element
 * @y: second element
 */

void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}

/**
 * selection_sort - sorts an array of integers in ascending order
 *                  using the Selection sort algorithm
 * @array: array of integers
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != 1 && array[min_idx] != array[i])
		{
			swap(&array[min_idx], &array[i]);
			print_array(array, size);
		}
	}
}
