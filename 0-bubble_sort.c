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
 * bubble_sort - sorts an array of integers in ascending order using
 *               Bubble sort algorithm
 * @array: array of integers
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
