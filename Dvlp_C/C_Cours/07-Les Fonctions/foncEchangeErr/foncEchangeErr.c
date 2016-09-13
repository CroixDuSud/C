/* ========================================================================== */
/* projet : Fonction : echange de deux valeurs entieres                       */
/* fichier : foncEchangeErr.c                                                 */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>                      /* Pour printf                        */
#include <conio.h>                      /* Pour _getch                        */

/* -------------------------------------------------------------------------- */
/* Declaration de la fonction "echange"                                       */
/* -------------------------------------------------------------------------- */

void echange(int n1, int n2);


/* ========================================================================== */
/* PROGRAMME PRINCIPAL                                                        */
/* ========================================================================== */

int main()
{
    int i;
    int j;

    i = 10;
    j = 20;

    printf("Avant echange : i  = %d, j  = %d\n", i, j);
    echange(i, j);
    printf("Apres echange : i  = %d, j  = %d\n", i, j);

    return 0;
}



/* ========================================================================== */
/* FONCTION "echange"                                                         */
/* ========================================================================== */

void echange(int n1, int n2)
{
    int permut;

    printf("Avant echange : n1 = %d, n2 = %d\n", n1, n2);
    permut = n1;
    n1 = n2;
    n2 = permut;
    printf("Apres echange : n1 = %d, n2 = %d\n", n1, n2);
}
