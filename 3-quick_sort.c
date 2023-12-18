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
 * @low: first array element
 * @high: last array element
 * @size: size of array
 * Return: return the position of the last element sorted
 */
int lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = low, j;

	for (j = low; j < high; j++)
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
	if (array[i] != array[high])
	{
		swap(array, i, high);
		print_array(array, size);
	}
	return (i);
}
/**
 * quicksort - qucksort algorithm implementation
 * @array: array
 * @low: first array element
 * @high: last array element
 * @size: array of size
 */
void quicksort(int *array, ssize_t low, ssize_t high, int size)
{

	ssize_t position = 0;

	if (low < high)
	{
		position = lomuto_partition(array, size, low, high);

		quicksort(array, low, position - 1, size);
		quicksort(array, position + 1, high, size);
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
