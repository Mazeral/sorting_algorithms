#include"sort.h"

/**
 * bubble_sort - a fucntion sorts an array with bubble sorting algorithms
 * @array: The array to be sorted
 * @size: The size of the array
 * Return: Nothing, just sorts the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	int x, y;
	int check  = 0;

	if (size >= 2)
	{
		while (check == 0)
		{
			for (i = 0; i < size - 1; i++)
			{
				if (array[i] > array[i + 1])
				{
					x = array[i];
					y = array[i + 1];
					array[i] = y;
					array[i + 1] = x;
					print_array(array, size);
				}
			}
			for (i = 0; i < size - 1; i++)
			{
				if (array[i] > array[i + 1])
				{
					check = 0;
					break;
				}
				else
				{
					check = 1;
				}
			}
		}
	}
}
