#include	<stdio.h>
#include	<stdlib.h>

int 	*ft_crea_tab(int taille_tab)
{
	int		*tab;
	int		i;

	tab = malloc(sizeof(int*) * taille_tab);
	for (i = 0; i < taille_tab; i++)
	{
		printf("valeur %d?\n", i + 1);
		scanf("%d", &tab[i]);
	}
	return (tab);
}

int		*ft_tri_tab(int *tab, int taille_tab)
{
	int		i;
	int		inter;

	i = 0;
	inter = 0;
	while (i <= taille_tab)
	{
		if (tab[i] > tab[i + 1])
		{
			inter = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = inter;
			i = 0;
		}
		if (tab[i] <= tab[i + 1])
		{
			i++;
		}
	}

	for (i = 0; i < taille_tab; i++)
	{
		printf("pos:%d || val:%d\n", i, tab[i]);
	}
	return (tab);
}

int 	ft_find_value(int *tab, int taille_tab)
{
	int 	val;
	int 	i;
	int 	pos;

	i = taille_tab / 2;
	pos = -1;
	printf("saisir valeur recherche:\n");
	scanf("%d", &val);

	while ((pos == -1) && ((i <= taille_tab) && (i >= 0)))
	{
		printf("pouet: %d\n", i);
		if (tab[i] == val)
		{
			pos = i;
			printf("trouve %d\n", i);
		}
		else if (val < tab[i])
		{
			i--;
		}
		else if (val > tab[i])
		{
			i++;
		}
	}
	return (pos);
}

int		main()
{
	int		*tab;
	int 	pos;
	int 	taille_tab;

	printf("taille tab:\n");
	scanf("%d", &taille_tab);

	tab = ft_crea_tab(taille_tab);
	tab = ft_tri_tab(tab, taille_tab);
	pos = ft_find_value(tab, taille_tab);

	free(tab);
	tab = NULL;

	printf("%d\n", pos);
	printf("FIN\n");
	return (0);
}