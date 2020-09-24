#ifndef		STRUCT_DATE
#define		STRUCT_DATE
#include	<stdio.h>

typedef	struct
{
	int 	jour;
	int 	annee;
	char	mois[11];
} DATE;
DATE	ft_donne_date(DATE *date);
void	ft_print_date(DATE *date);
#endif		