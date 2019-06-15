#include "sort.h"
/**
 *bubble_sort - function that sorts an array of ints
 *using bubble sort algorithm
 *
 *@array: array of ints
 *@size: size of array
 *
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, k;

	i = 0;
	while (i < size)
	{
		if (i != size - 1 && array[i] > array[i + 1])
		{
			for (k = 0; k < size; k++)
			{
				if (k != size - 1 && array[k] > array[k + 1])
				{
					temp = array[k];
					array[k] = array[k + 1];
					array[k + 1] = temp;
				}
				for (j = 0; j < size; j++)
				{
					printf("%d ", array[j]);
				}
				printf("\n");
			}
			i = 0;
		}
		else
		{
			i++;
		}
	}
}
