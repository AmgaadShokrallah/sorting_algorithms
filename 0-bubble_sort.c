#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 *
 * @array: parameter1
 * @size: parameter2
 *
 */
void bubble_sort(int *array, size_t size)
{
	int tmp = 0;
	size_t i, x;

	if (!array || !size)
		return;

	for (i = 0; i < size; i++)
	{
		for (x = 0; x < size; x++)
		{
			if (array[x] > array[x + 1])
			{
				tmp = array[x];
				array[x] = array[x + 1];
				array[x + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
