void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0;
	unsigned int j = 0;

	int tmp = 0;

	while (i < size - 1)
	{
		j = i;
		while (j < size)
		{
			if(tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
#include <unistd.h>


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int	main(void)
{
	int tab[] = {5, 3, 4, 1};
	unsigned int size = 4;
	unsigned int i = 0;

	sort_int_tab(tab, size);

	while (i < size)
	{
		ft_putnbr(tab[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');

	return (0);
}

// tab = [5, 3, 4, 1]
// size = 4
