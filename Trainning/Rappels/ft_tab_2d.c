#include <stdio.h>
#include <stdlib.h>

int **ft_crea_tab(int nb_lig, int nb_col)
{
	int i, j;
	int **tab;
	int	valeur;

	i = 0;
	j = 0;
	valeur = 0;

	tab = malloc(sizeof(int*) * nb_lig);
	if (tab == NULL)
		return (0);
	
	while (i < nb_lig)
	{
		tab[i] = malloc(sizeof(int) * nb_col);
		if (*tab == NULL)
			return (0);
		j = 0;
		while ( j < nb_col)
		{		
			printf("lig:%d, col:%d\n", i + 1, j + 1);
			scanf("%d", &valeur);
			tab[i][j] = valeur;
			j++;
		}
		i++;
	}


	return (tab);
}

void	ft_print_tab(int **tab, int nb_lig, int nb_col)
{
	int i, j;
	int somme_c, somme_l;

	i = 0;
	j = 0;
	somme_l = 0;
	somme_c = 0;
	while (i < nb_lig)
	{
		j = 0;
		somme_l = 0;
		while (j < nb_col)
		{
			printf("%d ", tab[i][j]);
			somme_l = somme_l + tab[i][j];
			
			j++;
		}
		printf(" = %d\n", somme_l);
		i++;
	}

	for(j = 0; j < nb_col; j++)
	{
		somme_c = 0;
		for(i = 0; i < nb_lig; i++)
		{
			somme_c = somme_c + tab[i][j];	
		}
		printf("%d ", somme_c);
	}
	printf("\n");
}
void	ft_free_tab(int	**tab, int	nb_lig)
{
	int i;
	for (i = 0; i < nb_lig; i++)
	{	
		free(tab[i]);
		tab[i] = NULL; 
	}
	free(tab);
	tab = NULL.
}


int	main()
{
	int nb_lig, nb_col;
	int	**tab = NULL;
	printf("saisir nb lignes\n");
	scanf("%d", &nb_lig);
	printf("saisir nb colonnes.\n");
	scanf("%d", &nb_col);

	tab = ft_crea_tab(nb_lig, nb_col);
	ft_print_tab(tab, nb_lig, nb_col);
	ft_free_tab(tab, nb_lig);
	return (0);
}