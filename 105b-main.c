#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	size_t n = 20;
	int *array = rand_array(n, 10000);

	print_array(array, n);
	printf("\n");
	radix_sort(array, n);
	printf("\n");
	print_array(array, n);
	check_array(array, n);
	return (0);
}

