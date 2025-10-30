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

#include <stdio.h>
#include <unistd.h>

/**
 * @brief // Percorre os dígitos: ex "123" → result=0→1→12→123 (multiplica por 10 e soma o valor de cada caractere)
 * @param *str_num Texto que representa um número. ex => "123"
 * @return result Número convertido para int. ex => 123
 * */
int ft_atoi(char *str_num)
{
	unsigned int i = 0;
	unsigned int result = 0;


	while (str_num[i] != '\0' && str_num[i] >= '0' && str_num[i] <= '9')
	{
		result *= 10;
		result += str_num[i] - '0';
		i++;
	}

	return result;
}

/**
 * @brief Converte recursivamente o número em base 16, imprimindo o dígito mais significativo primeiro (ex: 255 → "ff")
 * Exemplo com nbr = 255:
 * 
 * 1ª chamada: 255 > 16 → chama print_hex(255 / 16) → print_hex(15)
 * 
 * 2ª chamada: 15 <= 16 → não chama recursão
 * 
 *             nbr % 16 = 15 → digits[15] = 'f' → imprime 'f'
 * 
 * Retorna à 1ª chamada: nbr % 16 = 255 % 16 = 15 → digits[15] = 'f' → imprime 'f'
 * 
 * Saída final: "ff"
 * @param nbr número a ser impresso na tela (decimal)
*/
void print_hex(int nbr)
{
	char *digits = "0123456789abcdef";

	if (nbr >= 16)
	{
		print_hex(nbr / 16);
	}
	nbr = digits[nbr %16];
	write(1, &nbr, 1);
}

int main(int argc, char *argv[])
{
	printf("Numero de argumentos: %d \n", argc);
	printf("Valor do argumento:   \"%s\" \n", argv[1]);

	int value = ft_atoi(argv[1]);
	print_hex(value);
	return (0);
}