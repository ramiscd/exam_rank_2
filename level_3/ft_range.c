/* Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3. */

#include <stdio.h>
#include <stdlib.h>

// ft_range(1, 3); -> [1, 2, 3]
// ft_range(3, 1); -> [3, 2, 1]

int	*ft_range(int start, int end)
{
	int i = 0;
	int len = (end - start) < 0
		? ((end - start) * -1) + 1
		: (end - start) + 1;
	
	int *range = (int *) malloc(len * sizeof(int));

	while (i < len) // Enquanto i < que o tamanho do range Ex: 3
	{
		if (start < end) // Se for incremento
		{
			range[i] = start++; // i = 0 [3]
		}
		else // decrenento
		{
			range[i] = start--;
		}
		i++;
	}

	return (range);
}

int main(void)
{
	ft_range(1, 3);
	
	return (0);
}