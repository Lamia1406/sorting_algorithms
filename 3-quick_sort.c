#include "sort.h"
#include <stdlib.h>
/**
 * lomuto_partition - Partitions the array using Lomuto scheme
 * @array: The array to be sorted
 * @low: The index of the lower bound of the sub-array to be partitioned
 * @high: The index of the upper bound of the sub-array to be partitioned
 * @size: The size of the array
 *
 * Return: The index of the pivot element after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			print_array(array, size);
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	return (i + 1);
}
/**
 * quick_sort_lomuto - Sorts an array using the Quick
 *			Sort algorithm with Lomuto scheme
 * @array: The array to be sorted
 * @low: The index of the lower bound of the sub-array to be sorted
 * @high: The index of the upper bound of the sub-array to be sorted
 * @size: The size of the array
 */
void quick_sort_lomuto(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(array, low, high, size);

		quick_sort_lomuto(array, low, pivot_index - 1, size);
		quick_sort_lomuto(array, pivot_index + 1, high, size);
	}
}
/**
 * quick_sort - Sorts an array using the Quick
 *			Sort algorithm with Lomuto scheme
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_lomuto(array, 0, size - 1, size);
}


