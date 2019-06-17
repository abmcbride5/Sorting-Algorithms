#include "sort.h"

/**
 * get_digit - gets a digit from a number
 * @number: the integer
 * @digit: the digit position to get
 *
 * Return: the digit value at given position
**/
int get_digit(int number, int digit)
{
	int i = 0, pow = 1, ret;

	for (i = 0; i < digit; i++)
		pow *= 10;
	ret = ((number % (pow * 10)) / pow);
	return (ret);
}

/**
 * radix_pass - sorts by radix
 * @array: the integer array to sort
 * @size: the size of the array
 * @digit: the current digit to check
 * @new_array: target array of same size
 *
 * Return: void.
 */
int radix_pass(int *array, ssize_t size, int digit, int *new_array)
{
	ssize_t i;
	int buckets[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 0; i < size; i++)
		buckets[get_digit(array[i], digit)]++;
	if (buckets[0] == size)
		return (0);
	for (i = 1; i <= 9; i++)
	{
		if (buckets[i] == size)
			return (0);
		buckets[i] += buckets[i - 1];
	}
	for (i = size - 1; i > -1; i--)
		new_array[buckets[get_digit(array[i], digit)]-- - 1] = array[i];
	return (1);
}

/**
 * radix_sort - sorts by radix
 * @size: the size of the array
 * @array: the integer array to sort
 *
 * Return: the gap size
 */
void radix_sort(int *array, size_t size)
{
	int *old_array, *new_array, *temp_ptr, *ptr, changed;
	size_t i;

	if (!array || !size)
		return;

	old_array = array;
	new_array = ptr = malloc(sizeof(int) * size);
	if (!new_array)
		return;
	for (i = 0; i < 10; i++)
	{
		changed = radix_pass(old_array, (ssize_t)size, i, new_array);
		if (changed)
		{
			temp_ptr = old_array;
			old_array = new_array;
			new_array = temp_ptr;
			print_array(old_array, size);
		}
	}
	for (i = 0; i < size; i++)
		array[i] = old_array[i];
	free(ptr);
}
