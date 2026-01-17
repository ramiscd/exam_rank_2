/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/

#include <stdlib.h>

int ft_count_len(int nbr)
{
	int i = 0;

	if(nbr < 0)
		i++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	long num = nbr;
	int len = ft_count_len(nbr);
	char *str = (char *) malloc(len + 1 * sizeof(char));
	int i = len - 1;
	str[len] = '\0';

	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}

	while (num > 9)
	{
		str[i] = num % 10 + '0';
		num = num /10;
		i--;
	}
	str[i] = num + '0';
	return(str);
}

#include <stdio.h>
int main()
{
	char *str = ft_itoa(-42);
	printf("%s", str);
}