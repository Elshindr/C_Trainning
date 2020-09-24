#include 	"liste_nb.h"
void 	ft_free_liste(Liste *liste)
{
	Element suppr = liste -> premier;
	while (suppr != NULL)
	{
		free(suppr);
		suppr = suppr -> next;
	}
}

void 	ft_print_liste(Liste *liste)
{
	Element *actuel = liste -> premier;

	while (actuel != NULL)
	{
		printf("%d -> ", actuel -> nb);
		actuel = actuel -> next;
	}
}

void 	ft_ajout_fin(Liste *liste, int nb_ajout)
{
	int 	i;

	i = 0;
	while (i < nb_ajout)
	{
		Element *ajout = malloc(sizeof(*ajout));
		if (ajout == NULL)
			exit(EXIT_FAILURE);

		ajout -> nb = i;
		ajout -> next = NULL;

		Element *inter = liste -> premier;
		
		while (inter -> next != NULL)
		{
			inter = inter -> next;
		}

		inter -> next = ajout;
		i++;
	}
}

Liste	*ft_init_liste()
{
	Element *elem = malloc(sizeof(*elem));
	Liste *liste = malloc(sizeof(*liste));

	if (elem == NULL || liste == NULL)
	{
		exit(EXIT_FAILURE);
	}
	elem -> nb = 0;
	elem -> next = NULL;
	liste -> premier = elem;
	return (liste);
}

int 	main()
{
	Liste *pouet;

	pouet = ft_init_liste();
	ft_ajout_fin(pouet, 3);
	ft_print_liste(pouet);
	ft_free_liste(pouet);
	return (0);
}