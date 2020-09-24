#ifndef 	STRUCT_ETU
#define		STRUCT_ETU
#define 	NBNOTE 4
#include	<stdio.h>
#include 	<string.h>
typedef		struct 
{
	char	nom[10];
	float 	moy;
	int 	age;
} ETU;
void 	ft_print_moy(ETU *etud, int taille);
void	ft_actua_moy(ETU *etud, int taille);
void	ft_saisi_etu(ETU *etud, int taille);
int 	ft_ajout_etu(ETU *etud, int taille);
void	ft_tri_age(ETU *etud, int taille);
void 	ft_print_fin(ETU *etud, int nb_etu);
#endif