/* Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------
Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.
If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.
Yes, the examples are right.

Examples:
$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$> */

#include <stdio.h>
#include <unistd.h>

int ft_atoi(char *str) //ex => "255"
{
	int i = 0, res = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9') {
		res *= 10; // 0 - 20 - 250
		res += str[i] - '0'; // 2 - 25 - 255
		i++;
	}
	return res; // => 255
}

/**
 * @brief Verifica se um número é primo.
 *
 * A função testa se o número passado é divisível apenas por 1 e por ele mesmo.
 * Começa testando divisores a partir de 2 até num - 1.
 * 
 * Lógica passo a passo:
 * - Se o número for menor ou igual a 1, retorna 0 (não é primo).
 * - Testa cada valor de i começando em 2:
 *   - Se num % i == 0, o número é divisível por outro número → não é primo.
 *   - Caso contrário, incrementa i e continua testando.
 * - Se o loop termina com i == num, significa que nenhum divisor foi encontrado → é primo.
 *
 * @param num Número inteiro a ser verificado.
 * @return 1 se o número for primo, 0 caso contrário.
 *
 * @example
 * is_prime(5);  // Retorna 1 (5 é primo)
 * is_prime(8);  // Retorna 0 (8 não é primo)
 */
int is_prime(int num) // 5 - é primo esse caraio
{
	int i = 2;
	if (num <= 1) // pula
	{
		return 0;// não é primmo
	}
	else
	{
		while (i < num) // 2 3 4 5
		{
			if(num % i == 0)
			{
				break; // não é primo
			}
			i++;
		}
		if (i == num)
		{
			return 1; // é primo
		}
	}
	return 0;
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nbr) //255
{
	unsigned int nb;
	
	if (nbr < 0)
	{
		ft_putchar('-');
		nb = -nbr;
	}
	else
		nb = nbr;
	if (nb >= 10) 
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int main(int argc, char **argv)
{
		if (argc != 2)
	{
		putchar('0');
		putchar('\n');
		return 0;
	}
	int num = ft_atoi(argv[1]);
	int acc = 0;
	int i = 0;
 
	while (i < num)
	{
		if(is_prime(i) == 1)
		{
			acc += i;
		}
		i++;
	}
	if (acc > 0)
	{
		ft_putnbr(acc);
	}
	else
	{
		printf("cheguei aqui");
		putchar('0');
		putchar('\n');
		return 0;
	}
}
