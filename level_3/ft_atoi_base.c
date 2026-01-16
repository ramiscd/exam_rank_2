/* Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base); */

#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base);
int	isspacee(int c);
int	isvalid(int ch, int baselen);

int ft_atoi_base(const char *str, int str_base)
{
	int i = 0, res = 0, sign = 1;

	while (isspacee(str[i]))
	{
		i++;
	}
	
	if(str[i] == '-' | str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	while (str[i] && isvalid(str[i], str_base))
	{
		res = res * str_base;

		if (str[i] >= '0' && str[i] <= '9')
			res += str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			res += str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			res += str[i] - 'F' + 10;
		i++;
 	}

	return(res * sign);
}

int	isspacee(int c)
{
	if (c == 9| c == 10 | c == 11 | c == 12 | c == 13 | c == 32)
		return (1);
	else
		return (0);
}

int isvalid(int ch, int baselen)
{
	char *lbase = "0123456789abcdef";
	char *ubase = "0123456789ABCDEF";
	int i = 0;

	while (i < baselen)
	{
		if (ch == lbase[i] | ch == ubase[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int main()
{
	printf("%d", ft_atoi_base("   		-1101", 2));
}
