/* ========================================================================== */
/* projet : Recursivite : calcul d'une factorielle                            */
/* fichier : foncRecurs.c                                                     */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* -------------------------------------------------------------------------- */
/* Declaration de la fonction                                                 */
/* -------------------------------------------------------------------------- */

int fact(int n);

int main()
{
    char ligne[81];
    int i;

    printf("Introduire un nombre entier : ");
    gets(ligne);
    i = atoi(ligne);

    printf("Factorielle(%d) = %d\n\n", i, fact(i));

    return 0;
}

/* -------------------------------------------------------------------------- */
/* Fonction factorielle                                                       */
/* -------------------------------------------------------------------------- */

int fact(int n)
{
    if (n > 1) return fact(n - 1) * n;
    else       return 1;
}
