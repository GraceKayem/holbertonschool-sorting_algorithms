#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array and prints the array
 *	       only if the values are different
 * @a: Pointer to first integer
 * @b: Pointer to second integer
 * @array: The array being sorted
 * @size: Size of the array
 */
void swap_ints(int *a, int *b, int *array, size_t size)
{
	if (*a != *b)
	{
		int temp;

		temp = *a;
		*a = *b;
		*b = temp;
		print_array(array, size);
	}
}

/**
 * lomuto_partition - Partitions an array using the Lomuto scheme
 * @array: Array to partition
 * @low: Starting index
 * @high: Ending index (pivot)
 * @size: Size of the array (for printing)
 *
 * Return: Partition index
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low, j;

	for (j = low; j < high; j++)
	{
	if (array[j] < pivot)
	{
		if (i != j)
		{
			swap_ints(&array[i], &array[j], array, size);
		}
	i++;
	}
	}

	if (i != high)
	{
		swap_ints(&array[i], &array[high], array, size);
	}

	return (i);
}


/**
 * quick_sort_recursive - Recursively sorts array using Lomuto scheme
 * @array: Array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array (for printing)
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
	size_t p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		if (p > 0)
			quick_sort_recursive(array, low, p - 1, size);
		quick_sort_recursive(array, p + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
