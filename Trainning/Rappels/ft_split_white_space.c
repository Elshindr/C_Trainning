#include <stdio.h>
#include <stdlib.h>


int		ft_nb_mot(char *str)
{
	int		nb_mot;
	int		i;

	nb_mot = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 33 && str[i] <= 126) && (str[i + 1] >= 0 && str[i + 1] <= 32))
			nb_mot++;
		i++;
	}
	return (nb_mot - 1);
}

int		ft_nb_car(char *str, int i)
{
	int		nb_car;

	nb_car = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 33 && str[i] <= 126)
			nb_car++;
		i++;
	}
	return (nb_car);
}

char	**ft_split_whitespaces(char *str)
{
	int i;
	int j;
	int	k;
	char	**chaine_fin;

	i = 0;
	j = 0;
	k = 0;
	chaine_fin =  malloc(sizeof(char*) * (ft_nb_mot(str) + 1));
	if (chaine_fin == NULL)
		return (0);
	while (j <= ft_nb_mot(str))
	{
		k = 0;
		if (!(chaine_fin[j] = malloc(sizeof(char) * (ft_nb_car(str, j) + 1))))
			return (0);
		while (str[i] >= 0 && str[i] <= 32)
			i++;
		while (k < ft_nb_car(str, j) && str[i]>= 33 && str[i] <= 126) 
		{
			chaine_fin[j][k] = str[i];
			i++;
			k++;
		}
		chaine_fin[j][k] = '\0';
		j++;
	}
	chaine_fin[j] = NULL;
	return (chaine_fin);
}

void	ft_free_tab(char **tab, char *str)
{
	int i;
	for (i = 0; i < ft_nb_mot(str); i++)
	{	
		free(tab[i]);
	}
	free(tab);
}

int	main ()
{
	char src[] = "le resto ,   2      gfgf";

	char **result = ft_split_whitespaces(src);
	while(*result != 0)
		printf("%s ",*(result++));
	printf("\n");
	ft_free_tab(result, src);
	return (0);
}