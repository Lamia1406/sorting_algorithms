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
	for (i = 0; i < size - 1; i++)
	{
		swapped = 1;
		for (j = 0; j < size - 1 ; j++)
		{

			if (array[j] > array[j + 1])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
				swapped = 0;
			}
		}
		if (swapped == 1)
			break;
	}
}
