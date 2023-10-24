#include "sort.h"
#include <stdlib.h>
/**
 * counting_sort - sorts an array of integers in ascending order
 *			using the Counting sort algorithm
 * @array : the array to sort
 * @size : size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t j, i;
	int max = array[0], k, *count_array, *output_array, count;

	if (array == NULL || size < 2)
		return;
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	count_array = calloc(max + 1, sizeof(int));
	if (count_array == NULL)
		return;
	output_array = calloc(size, sizeof(int));
	if (output_array == NULL)
	{
		free(count_array);
		return;
	}
	for (i = 0; i < size ; i++)
	{
		count = 0;
		for (j = 0; j < size; j++)
			if (array[i] == array[j])
				count++;
		count_array[array[i]] = count;
	}
	for (k = 1; k < max + 1; k++)
		count_array[k] += count_array[k - 1];
	print_array(count_array, max + 1);
	for (k = size - 1; k > -1; k--)
	{
		output_array[count_array[array[k]] - 1] = array[k];
		count_array[array[k]] -= 1;
	}
	for (i = 0; i < size; i++)
		array[i] = output_array[i];
	free(output_array);
	free(count_array);
}
