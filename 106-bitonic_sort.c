#include "sort.h"

/**
 * swap - swaps 2 int values
 * @a: address of first value
 * @b: address of second value
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
	}
}

int bitonic_compare(int up, int *array, size_t size, size_t start, size_t end)
{
	size_t half = (end - start + 1) / 2, i;
	int swapped = 0;

	(void)size;
/*
	printf("       compare(%s, %lu, %lu, %lu)\n", up ? "UP" : "DOWN", start, half, end);
	print_array(array + start, end - start + 1);
	*/
	for (i = start; i < start + half; i++)
		if ((array[i] > array[i + half]) == up)
		{
			swap(&array[i], &array[i + half]);
			swapped = 1;
		}

	return (swapped);
}

int bitonic_merge(int up, int *array, size_t size, size_t start, size_t end)
{
	size_t mid = (start + end) / 2;
	int a, b, c;
/*
	printf("    MERGE(%s, %lu, %lu, %lu)\n", up ? "UP" : "DOWN", start, mid, end);
*/
	if (end - start < 1)
		return (0);
	c = bitonic_compare(up, array, size, start, end);
	a = bitonic_merge(up, array, size, start, mid);
	b = bitonic_merge(up, array, size, mid + 1, end);
	return (a + b + c);
}

int _bitonic_sort(int up, int *array, size_t size, size_t start, size_t end)
{
	size_t mid = (start + end) / 2;
	int a, b, c;

	if (end - start < 1)
		return (0);
	printf("Merging [%lu/%lu] (%s):\n", end - start + 1, size,
		up ? "UP" : "DOWN");
	print_array(array + start, end - start + 1);
	a = _bitonic_sort(1, array, size, start, mid);
	b = _bitonic_sort(0, array, size, mid + 1, end);
	c = bitonic_merge(up, array, size, start, end);
	printf("Result [%lu/%lu] (%s):\n", end - start + 1, size,
		up ? "UP" : "DOWN");
	print_array(array + start, end - start + 1);
	return (a + b + c);
}

void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	_bitonic_sort(1, array, size, 0, size - 1);
}
