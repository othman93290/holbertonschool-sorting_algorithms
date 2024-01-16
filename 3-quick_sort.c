#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}

/**
 * quicksort_recursive - Recursive function for quick sort
 *
 * @array: The array to be sorted
 * @low: Starting index of the sub-array
 * @high: Ending index of the sub-array
 * @size: Number of elements in the array
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	int partition_index;

	if (low < high)
	{
		partition_index = partition(array, low, high, size);

		/* Print the array after each partition */
		print_array(array, size);

		quicksort_recursive(array, low, partition_index - 1, size);
		quicksort_recursive(array, partition_index + 1, high, size);
	}
}

/**
 * partition - Chooses a pivot and partitions the array around it
 *
 * @array: The array to be sorted
 * @low: Starting index of the sub-array
 * @high: Ending index of the sub-array
 * @size: Number of elements in the array
 *
 * Return: The index of the partition
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, temp;
	int i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			/* Print the array after each swap */
			if (i != j)
				print_array(array, size);
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	/* Print the array after each swap */
	if (i + 1 != high)
		print_array(array, size);

	return (i + 1);
}

