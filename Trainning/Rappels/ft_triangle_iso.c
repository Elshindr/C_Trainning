

#include <stdio.h>

int	ft_taille_base(int lenght)
{
	int i;
	int taille_base;

	i = 1;
	taille_base = 1;
	while (i < lenght)
	{
		taille_base = taille_base + 2;
		i++;
	}
	printf("%d\n", taille_base);
	return (taille_base);
}


void	ft_print_iso(int lenght)
{
	int base;
	int	nb_car;
	int i;
	int j;
	int k;

	base = ft_taille_base(lenght);
	i = 1;
	k = 1;
	nb_car = 1;

	while (i <= lenght)
	{
		j = 1;
		k = 1;
		while (j <= (base - nb_car) / 2)
		{
			printf(".");
			j++;
		}
		while (k <= nb_car)
		{
			printf("*");
			k++;
		}
		j = 1;
		while (j <= (base - nb_car) / 2)
		{
			printf(".");
			j++;
		}
		printf("\n");
		nb_car = nb_car + 2;
		i++;
	}
}

int	main()
{
	int lenght;
	lenght = 8;
	ft_print_iso(lenght);

	return (0);
}