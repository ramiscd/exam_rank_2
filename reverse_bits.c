/* Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
     ||
     \/
 0110  0100 */

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	return(38);
}

int	main(void)
{
	unsigned char a = 38;
	unsigned char result = reverse_bits(38); // 38 = 0010 0110
	printf("%o", result);
	return (0);
}

