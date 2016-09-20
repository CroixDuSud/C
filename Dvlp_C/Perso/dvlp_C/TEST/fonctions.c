#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

void input(EMPLOYE *emp)
{
    char ligne[81];

    printf(" numero employe : ");
    gets (ligne);
    (*emp).numero = atoi(ligne);

    printf("\n nom : ");
    gets((*emp).nom);

    printf("\n prenom : ");
    gets((*emp).prenom);

    printf("\n numero agence : ");
    gets(ligne);
    (*emp).numeroAgence = atoi(ligne);
}

int confirmation(int *conf)
{
	int test;
	*conf = &test;

	printf("Entrer un nouvel employe ? (""entree pour annuler"")\n");
	if (getch() != '\r')
	{
		test = 1;
	}
	else
	{
		test = 0;
	}
	return *conf;
}

/*
void write(EMPLOYE emp)
{
    fprintf(fichEmploye, "%d\n", emp.numero);
	fprintf(fichEmploye, "%s\n", emp.nom);
	fprintf(fichEmploye, "%s\n", emp.prenom);
	fprintf(fichEmploye, "%d\n", emp.numeroAgence);
}
*/
