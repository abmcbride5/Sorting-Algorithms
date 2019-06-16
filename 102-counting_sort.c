#include "sort.h"
/**
*integer_count- number of times integer appears in an array
*
*@array: array given
*@size: size of array
*@range: number to check for occurance
*
*Return: number of occurances
*/
int integer_count(int *array, size_t size, int range)
{
	int total = 0;
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] == range)
			total++;
	}
	return (total);
}

/**
*counting_sort - counting sort algorithm
*
*@array: array to be sorted
*@size: size of the array
*/
void counting_sort(int *array, size_t size)
{
	int k = 0, b = 0, r = 1;
	size_t i, c;
	int *array2;

	for (i = 0; i < size; i++)
	{
		if (array[i] > k)
		{
			k = array[i];
		}
	}
	array2 = malloc(sizeof(int) * (k + 1));
	for (c = 0; c < ((size_t)k + 1); c++)
	{
		if (c == 0)
		{
			array2[c] = 0;
		}
		else
		{
			b = array2[c - 1] + integer_count(array, size, r);
			array2[c] = b;
			r++;
			printf("r %d, c %lu, b %d\n", r, c, b);
		}
	}
	print_array(array2, (k + 1));
}
