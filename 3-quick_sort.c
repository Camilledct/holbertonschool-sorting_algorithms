#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @array: The array containing elements
 * @i: Index of the first element
 * @j: Index of the second element
 */
void swap(int *array, int i, int j)
{
	int temp = array[i];

	array[i] = array[j];
	array[j] = temp;
}

/**
 * partition - Partitions the array using the Lomuto scheme
 * @array: The array to sort
 * @low: Starting index of the partition
 * @high: Ending index of the partition (pivot)
 * @size: Size of the array (for printing)
 *
 * Return: The final position of the pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(array, i + 1, high);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursively applies the Quick Sort algorithm
 * @array: The array to sort
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: Size of the array (for printing)
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array using the Quick Sort algorithm
 * @array: The array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
