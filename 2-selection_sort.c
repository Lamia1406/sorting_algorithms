#include "sort.h"
/**
 *selection_sort - sorts an array of integers in ascending order
 *			using the Selection sort algorithm
 * @array : the array to sort
 * @size : size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, temp;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size ; j++)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
}
