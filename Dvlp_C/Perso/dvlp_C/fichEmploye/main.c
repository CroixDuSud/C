#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

int main(int argc, char const *argv[])
{
    /* ===================================================
	================ D�clarations ========================
	====================================================*/

	FILE *fichEmploye;
	EMPLOYE tabEmploye;
	char path[81];
	int codeRetour;

	strcpy(path, "C:\\Users\\afpa1800\\Desktop\\fichEmploye.txt");

    /* ===================================================
	================ Saisie des donn�es ==================
	====================================================*/

    input(&tabEmploye);

    /* ===================================================
	=============== Ouverture du fichier =================
	====================================================*/

	fichEmploye = fopen(path, "wt");

	if(fichEmploye == NULL)
	{
		printf("Erreur lors de la creation ou l'ouverture du fichier !\n");
		exit(1);
	}

	/* ===================================================
	=============== Ecriture des donn�es =================
	====================================================*/

	printf("Liste des employes\n\n");
	fprintf(edition, "Liste des employes\n\n");

	codeRetour = fread(&form, sizeof(EMPLOYE), )



	fprintf(fichEmploye, "%d\n", tabEmploye.numero);
	fprintf(fichEmploye, "%s\n", &tabEmploye.nom);
	fprintf(fichEmploye, "%s\n", &tabEmploye.prenom);
	fprintf(fichEmploye, "%d\n", tabEmploye.numeroAgence);

	fclose(fichEmploye);

	return 0;
}
