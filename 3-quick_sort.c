#include "sort.h"

/**
 * partition - divides array into two partitions
 *
 * @array: array of integers
 * @lo: right subarray
 * @hi: left subarray
 *
 * Return: pivot index
 */

int partition(int *array, int lo, int hi)
{
	int pivot = array[hi];
	int i = lo - 1;
	int tmp = 0;
	int j;

	for (j = lo; j<=hi-1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}
	tmp = array[i + 1];
	array[i + 1] = array[hi];
	array[hi] = tmp;

	return (i + 1);
}

/**
 * quicksort - sorts the sub arrays
 *
 * @array: array of integers
 * @lo: right subarray
 * @hi: left subarray
 *
 * Return: void
 */

void quicksort(int *array, size_t lo, size_t hi)
{
	size_t pi;

	if (lo < hi)
	{
		pi = partition(array, lo, hi);
		quicksort(array, lo, pi - 1);
		quicksort(array, pi + 1, hi);
	}
}
/**
 * quick_sort - sorts an array of integers in
 * ascending order using the Quick sort algorithm
 *
 * @array: array of integers
 * @size: array size
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quicksort(array, 0, size);

}
