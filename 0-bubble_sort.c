#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order
 *			using the Bubble sort algorithm
 * @array : the array to sort
 * @size : size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j, temp;
	int swapped;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		swapped = 0;
		for (j = 0; j < size - 1 - i ; j++)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (swapped == 0)
			break;
	}
}
