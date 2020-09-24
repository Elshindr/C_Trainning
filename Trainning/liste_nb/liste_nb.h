#ifndef		LISTE_NB
#define 	LISTE_NB
#include 	<stdio.h>
#include 	<stdlib.h>
typedef struct Element Element;
struct Element
{
	int 	nb;
	Element	*next;	

};

typedef	struct Liste Liste;
struct Liste
{
	Element	*premier;
};

Liste	*ft_init_liste();
void 	ft_ajout_fin(Liste *liste, int nb_ajout);
void 	ft_print_liste(Liste *liste);
void 	ft_free_liste(Liste *liste);
#endif 