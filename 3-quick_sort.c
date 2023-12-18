#include "sort.h"

/**
 * swap - swap 2 elements into an array
 * @array: array
 * @a: element1
 * @b: element2
 */
void swap(int *array, ssize_t a, ssize_t b)
{
	int tmp;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}
/**
 * lomuto_partition - lomuto partition sorting scheme implementation
 * @array: array
 * @first: first array element
 * @last: last array element
 * @size: size of array
 * Return: return the position of the high element sorted
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t i = first, j;

	for (j = first; j < last; j++)
	{
		if (array[j] < pivot)
		{
			if (array[i] != array[j])
			{
				swap(array, i, j);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[last])
	{
		swap(array, i, last);
		print_array(array, size);
	}
	return (i);
}
/**
 * quicksort - qucksort algorithm implementation
 * @array: array
 * @first: first array element
 * @last: last array element
 * @size: array of size
 */
void quicksort(int *array, ssize_t first, ssize_t last, int size)
{

	ssize_t position = 0;

	if (first < last)
	{
		position = lomuto_partition(array, size, first, last);

		quicksort(array, first, position - 1, size);
		quicksort(array, position + 1, last, size);
	}
}
/**
 * quick_sort - prepare the terrain to quicksort algorithm
 * @array: array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
