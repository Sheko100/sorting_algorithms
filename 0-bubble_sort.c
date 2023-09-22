#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 *
 * @array: array of integers
 * @size: array size
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j = 0, temp = 0;

	if (size < 2)
		return;

	while (j < size)
	{
		i = 0;
		while (i < (size - 1))
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
			i++;
		}
		j++;
	}
}
