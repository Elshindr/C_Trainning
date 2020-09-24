#include	"struct_fiche.h"
void	ft_vide_buff()
{
	int c;

	c = 0;
	while (c != '\n' && c != EOF)
	{
		c = getchar();
	}	
}

void	ft_gestion_saisie(char* saisie, int taille)
{
	char *char_entre = NULL;
    
	if (fgets(saisie, taille, stdin) != NULL)  // Pas d'erreur de saisie ?
    {
        char_entre = strchr(saisie, '\n'); // On recherche l'"Entrée"
        if (char_entre != NULL) // Si on a trouvé le retour à la ligne
        {
            *char_entre = '\0'; // On remplace ce caractère par \0
        }
        else
        {
        	ft_vide_buff();
        }
    }
    else
    {
    	ft_vide_buff();
    }
}

float 	ft_moy_note(FICHE *fiche)
{
	int 	i;
	float 	moy;

	moy = 0;
	
	if ((fiche -> nbnote) > 0)
	{
		for (i = 0; i < (fiche -> nbnote); i++)
		{
			moy = moy + (fiche -> note[i]);
		}
		return (moy / (fiche -> nbnote));
	}
	else 
	{
		return (-1);
	}
}

void	ft_ajout_note(FICHE *fiche)
{
	char 	saisie;

	saisie = 'p';
	while ((fiche -> nbnote) < MAXNOTE && saisie != 'n')  
	{
		printf("voulez vous ajouter une note? (o/n)\n");
		scanf("%c", &saisie);
		ft_vide_buff();
		if (saisie != 'o' && saisie != 'n')
			printf("erreur saisir o ou n\n");
		else if (saisie == 'o')
		{
			printf("saisir note n%d:\n", ((fiche -> nbnote) + 1));
			scanf("%f", &(fiche -> note[fiche -> nbnote]));
			(fiche -> nbnote)++;
			ft_vide_buff();
		}
		else
			printf("bye bro\n");
	} 
}



FICHE 	ft_crea_fiche(FICHE *fiche)
{
	printf("nom\n");
	ft_gestion_saisie(fiche -> nom, 10);
	printf("prenom\n");
	ft_gestion_saisie(fiche -> prenom, 10);
    printf("formation\n");
	ft_gestion_saisie(fiche -> forma, 4);
	
	printf("redoublant? 1-0\n");
	scanf("%d", &(fiche -> redoubl));
	printf("groupe\n");
	scanf("%d", &(fiche -> groupe));
	printf("jour mois année naissance\n");
	scanf("%d %s %d", &(fiche -> date.jour), fiche -> date.mois, &(fiche -> date.annee));
	ft_vide_buff();
	
	fiche -> nbnote = 0;
	return (*fiche);
}

void	ft_print_fiche(FICHE *fiche)
{
	printf("\n\n");
	printf("%s, %s, %d, %d\n", fiche -> nom, fiche -> prenom, fiche -> groupe, fiche -> redoubl);
	printf("%d %s %d\n", fiche -> date.jour, fiche -> date.mois, fiche -> date.annee);
}

int		main()
{
	FICHE 	fiche;
	float 	moy;

	ft_crea_fiche(&fiche);
	ft_print_fiche(&fiche);
	ft_ajout_note(&fiche);
	moy = ft_moy_note(&fiche);

	if (moy == -1)
	{
		printf("moy impossible a calculer\n");
	}
	else
	{
		printf("moy = %f\n", moy);
	}
	return 0;
}
