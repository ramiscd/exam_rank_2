/* Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010" */


#include <unistd.h>

void print_bits(unsigned char octet)
{
	int i = 7;
	unsigned char bit = 0;

	while (i >= 0) 
	{
		// Empurra o número para a direita, verifica se deu 1; se deu 1 salva 1 e imprime, se der 0 salva 0 e imprime 0
		bit = (octet >> i & 1) + 48;
		write (1, &bit, 1);
		i--;
	}
}

int	main(){
	print_bits(2);
	return 0;
}