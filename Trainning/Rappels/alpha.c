#include <stdio.h>
#include <unistd.h>

void	ft_putnbr(int nbr)
{
	int numb;
	int mod;

	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nbr);
	}
	else if (nbr > 9)
	{
		mod = nbr % 10;
		numb = mod + 48;
		ft_putnbr(nbr / 10);
		write(1, &numb, 1);
	}
	else
	{
		numb = nbr + 48;
		write (1, &numb, 1);
	}
}

int	main()
{
	ft_putnbr(-125);
	return (0);
}

