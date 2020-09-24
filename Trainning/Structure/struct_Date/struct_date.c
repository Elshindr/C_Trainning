#include	"struct_date.h"


DATE	ft_donne_date(DATE *date)
{
	printf("saisir jour:\n");
	scanf("%d", &(date -> jour));
	printf("saisir mois:\n");
	scanf("%s", (date -> mois));
	printf("saisir annee:\n");
	scanf("%d", &(date -> annee));

	return (*date);
}

void	ft_print_date(DATE *date)
{
	printf("jour: %d, mois:%s, annee:%d\n", date -> jour, date -> mois, date -> annee);
}

int 	main()
{
	DATE date;
	ft_donne_date(&date);
	ft_print_date(&date);
	return 0;
}