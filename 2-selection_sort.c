#include "sort.h"
#include <stdio.h>
/**
 * selection_sort - sorts an array of integers in
 * ascending order using the Selection sort algorithm
 *
 * @array: array of integers
 * @size: array size
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, smallindex, j = 0, tmp = 0;

	if (size < 2)
		return;

	while (j < size)
	{
		i = j + 1;
		smallindex = j;
		while (i < size)
		{
			if (array[smallindex] > array[i])
				smallindex = i;
			i++;
		}
		if (smallindex != j)
		{
			tmp = array[j];
			array[j] = array[smallindex];
			array[smallindex] = tmp;
			print_array(array, size);
		}
		j++;
	}
}
