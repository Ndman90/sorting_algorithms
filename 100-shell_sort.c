#include "sort.h"
/**
 * swapper - swap 2 values.
 * @a: First index
 * @b: Second index
 * Return: Nothing
 */
void swapper(int *a, int *b)
{
	int tmp;
	
	tmp = *a;
	*b = tmp;
	*a = *b;
}

/**
 * shell_sort - A function that sorts an array of integers in
 * ascending order using the shell sort algorithm,
 * using the Knuth sequence.
 *
 * @array: Array of integers
 * @size: Size of array
 * Return: no return
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1, i, j, tmp;
	
	if (!array || size < 2)
		return;
	
	while (gap <= (int)size / 3)
	{
		gap = gap * 3 + 1;
	}
	
	while (gap > 0)
	{
		for (i = gap; i < (int)size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = tmp;
		}
		
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
