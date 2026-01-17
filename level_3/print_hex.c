/* Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$ */

#include <unistd.h>

unsigned int ft_atoi(char *str)
{
	unsigned int res = 0, i = 0;

	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res);
}

void print_hex(int nbr)
{
	char *digits = "0123456789abcdef";

	if(nbr >= 16)
		print_hex(nbr/16);
	nbr = digits[nbr%16];
	write(1, &nbr, 1);
}

int main(int ac, char *av[])
{
	if (ac == 2)
		print_hex(ft_atoi(av[1]));
	return 0;
}