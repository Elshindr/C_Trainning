#include	"struct_Etu.h"
void	ft_print_fin(ETU *etud, int taille)
{
	int 	i;
	for (i = 0; i < taille; i++)
	{
		printf("etud %d: age = %d moy = %2f nom = %s\n", i, etud[i].age, etud[i].moy, etud[i].nom);
	}
}
void	ft_tri_age(ETU *etud, int taille)
{
	int 	i;
	int 	i_age;
	int 	i_moy;
	char 	i_nom[10] ="poeut";

	i_age = 0;
	i_moy = 0;
	i = 0;

	while (i < taille)
	{
		if (etud[i].age > etud[i + 1].age)
		{
			i_age = etud[i].age;
			etud[i].age = etud[i + 1].age;
			etud[i + 1].age = i_age;

			i_moy = etud[i].moy;
			etud[i].moy = etud[i + 1].moy;
			etud[i + 1].age = i_moy;

			strcpy(i_nom, etud[i].nom);
			strcpy(etud[i].nom, etud[i + 1].nom);
			strcpy(etud[i + 1].nom, i_nom);
			i = 0;
		}
		else
			i++;
	}

}
void	ft_actua_moy(ETU *etud, int taille)
{
	int 	i;
	for (i = 0 ; i < taille; i++)
	{
		if ((etud[i].moy) < 10)
		{
			(etud[i].moy) = (etud[i].moy) + 1;
		}
		else if ((etud[i].moy) >= 10 && (etud[i].moy) <= 15)
		{
			(etud[i].moy) = (etud[i].moy) + 0.5;
		}
		printf("Etudiant %d: %s, %2f\n", i, etud[i].nom, etud[i].moy);
	}
}

int 	ft_ajout_etu(ETU *etud, int taille)
{
	int 	i;
	int 	pos;

	i = taille  + 1;

	printf("saisir position:\n");
	scanf("%d", &pos);

	while (i > 0)
	{
		if (i > pos)
		{
			strcpy(etud[i].nom, etud[i - 1].nom);
			etud[i].moy = etud[i - 1].moy;
			etud[i].age = etud[i - 1].age;	
		}
		else if (i == pos)
		{
			/*ou nouvelle fonction ajout*/
			strcpy(etud[i].nom, "merde");
			etud[i].moy = 45;
			etud[i].age = 12;
		}
		i--;
	}
	return (taille + 1);
}

void	ft_saisi_etu(ETU *etud, int taille)
{
	int 	i;
	int 	c;
	char	*position;

	for (i = 0; i < taille; i++)
	{
		printf("saisir nom prenom etu %d\n", i);
		position = NULL;
		c = 0;
		if (fgets(etud[i].nom, 10, stdin) != NULL)
		{
			position = strchr((etud[i].nom), '\n');
			if (position != NULL)
			{
				*position = '\0';
			}
			else
			{
				while ( c != '\n' && c != EOF)
				{
					c = getchar();
				}
			}
		}
		else
		{
			while ( c != '\n' && c != EOF)
			{
				c = getchar();
			}
		}
		printf("note\n");
		scanf("%f", &(etud[i].moy));
		c = 0;
		while (c != '\n' && c != EOF)
			{
				c = getchar();
			}
		printf("age\n");
		scanf("%d", &(etud[i].age));
		c = 0;
		while (c != '\n' && c != EOF)
		{
			c = getchar();
		}
	}
}

int main()
{
	int nb_etu;

	nb_etu = 4;
	ETU etud[10];
	ft_saisi_etu(etud, nb_etu);
	nb_etu = ft_ajout_etu(etud, nb_etu);
	ft_actua_moy(etud, nb_etu);
	ft_tri_age(etud, nb_etu);
	ft_print_fin(etud, nb_etu);
	return 0;
}