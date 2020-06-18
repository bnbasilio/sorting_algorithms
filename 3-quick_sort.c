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
 * partition - function to set an element as pivot and places numbers smaller
 *             than pivot element to its left and bigger numbers to its right
 * @array: array of integers
 * @low: beginning of the array
 * @high: end of the array
 * @size: size of the array
 *
 * Return: index of last swapped integer
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (array[i] != array[j])
				print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	if (array[i + 1] != array[high])
		print_array(array, size);
	return (i + 1);
}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 *              Quick sort algorithm (implementing the Lomuto partition scheme)
 * @array: array of integers
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	int high = (int)size - 1;

	actually_sort(array, 0, high, size);
}

/**
 * actually_sort - actually sorts the array using quick sort
 * @array: array of integers
 * @low: beginning of the array
 * @high: end of the array
 * @size: size of the array
 */

void actually_sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		actually_sort(array, low, pivot - 1, size);
		actually_sort(array, pivot + 1, high, size);
	}
}
