#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm.
 * @array: parameter
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, x, y;
	int tmp;

	if (!array || !size)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (x = size - 1, y = i + 1; x > i; x--)
		{
			if (array[x] < array[y])
			{
				y = x;
			}
		}
		if (array[i] > array[y])
		{
			tmp = array[i];
			array[i] = array[y];
			array[y] = tmp;
			print_array(array, size);
		}
	}
}
