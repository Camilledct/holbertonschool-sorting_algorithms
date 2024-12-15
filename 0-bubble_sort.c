#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *               using the Bubble sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n;
	int temp, swapped;

	if (!array || size < 2)
		return;

	n = size;
	while (n > 1)
	{
		swapped = 0;
		for (i = 0; i < n - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;

				print_array(array, size);

				swapped = 1;
			}
		}
		if (!swapped)
			break;

		n--;
	}
}
