#ifndef		STRUCT_FICHE
#define		STRUCT_FICHE
#include	<stdio.h>
#include <string.h>
/*#include	"..\struct_date.c"
#include	"..\struct_date.h"*/
#define		MAXNOTE 5

typedef	struct
{
	int 	jour;
	char	mois[11];
	int 	annee;
	
} DATE;

typedef		struct
{
	char	nom[10];
	char	prenom[10];
	char	forma[3];
	int		redoubl;
	int		groupe;
	int		nbnote;
	float	note[MAXNOTE];
	DATE	date;
} FICHE;
void	ft_vide_buff();
void	ft_gestion_saisie(char* saisie, int taille);
FICHE 	ft_crea_fiche(FICHE *crea_fiche);
void	ft_print_fiche(FICHE *affich_fiche);
void	ft_ajout_note(FICHE *ajout_note);
float 	ft_moy_note(FICHE *fiche);
#endif