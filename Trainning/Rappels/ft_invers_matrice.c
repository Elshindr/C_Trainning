#include	<stdlib.h>
#include 	<stdio.h>

char	**ft_crea_matrice(int nb_lig, int nb_col)
{
	int 	i, j;
	char **matrice;
	int c;

	matrice = malloc(sizeof(char*) * (nb_lig + 1));
	for (i = 0; i < nb_lig; i++)
	{
		matrice[i] = malloc(sizeof(char) * (nb_col + 1));
		for (j = 0; j < nb_col; j++)
		{
			printf("lig:%d col:%d\n valeur?\n", i, j);
			scanf("%c", &matrice[i][j]);
			while (((c = getchar()) != '\n') && (c != EOF))
			{

			}
		}
	}
	return (matrice);
}

char	**ft_inversion_matrice(char **matrice, int nb_lig, int nb_col)
{
	int 	j, i, k;
	char	*inter;
	char 	**invers;

	k = 0;

	inter = malloc(sizeof(char) * nb_col * nb_lig);
	for (i = 0; i < nb_lig; i++)
	{
		for (j = 0; j < nb_col; j++)
		{
			inter[k] = matrice[i][j];
			k++;
		}
	}

	k = 0;
	invers = malloc(sizeof(char*) * nb_col);
	for (i = 0; i < nb_col; i++)
	{
		invers[i] = malloc(sizeof(char) * (nb_lig));
		for (j = 0; j < nb_lig; j++)
		{
			invers[i][j] = inter[k];
			k++;
		}
	}
	free(inter);
	return (invers);
}


void	ft_print_invers(char **invers, int nb_lig, int nb_col)
{
	int 	j, i;

	for (i = 0; i < nb_col; i++)
	{
		for (j = 0; j < nb_lig; j++)
		{
			printf("%c ", invers[i][j]);
		}
		printf("\n");
	}
}

void	ft_free_mem(char **matrice, char **invers, int nb_lig, int nb_col)
{
	int i;

	for (i = 0; i < nb_lig; i++)
	{
		free(matrice[i]);
		matrice[i] = NULL;
	}
	free(matrice);
	matrice = NULL;
	for (i = 0; i < nb_col; i++)
	{
		free(invers[i]);
		invers[i] = NULL;
		printf("\n%d\n", i);
	}
	free(invers);
	invers = NULL;
}
int		main()
{
	int		nb_lig, nb_col;
	int 	c;
	char	**matrice;
	char	**invers;

	printf("nb_lig:\n");
	scanf("%d", &nb_lig);
	printf("nb_col:\n");
	scanf("%d", &nb_col);
	
	while (((c = getchar()) != '\n') && (c != EOF))
	{
	}

	matrice = ft_crea_matrice(nb_lig, nb_col);
	printf("pouet\n");
	invers = ft_inversion_matrice(matrice, nb_lig, nb_col);
	printf("***\n");
	ft_print_invers(invers, nb_lig, nb_col);
	printf("***\n");
	ft_free_mem(matrice, invers, nb_lig, nb_col);
	printf("*FIN*\n");
	return (0);
}