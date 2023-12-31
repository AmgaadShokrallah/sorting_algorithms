#include "sort.h"

/**
 * swap - the positions of two elements into an array
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
 * @first: first element of array
 * @last: last element of array
 * @size: size of array
 * Return: return the position of the last element sorted
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t c = first, j;

	for (j = first; j < last; j++)
	{
		if (array[j] < pivot)
		{
			if (array[c] != array[j])
			{
				swap(array, c, j);
				print_array(array, size);
			}
			c++;
		}
	}
	if (array[c] != array[last])
	{
		swap(array, c, last);
		print_array(array, size);
	}
	return (c);
}
/**
 * quicksort - qucksort algorithm implementation
 * @array: array
 * @first: first element of array
 * @last: last element of array
 * @size: size of array
 */
void quicksort(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t p = 0;


	if (first < last)
	{
		p = lomuto_partition(array, first, last, size);

		quicksort(array, first, p - 1, size);
		quicksort(array, p + 1, last, size);
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
