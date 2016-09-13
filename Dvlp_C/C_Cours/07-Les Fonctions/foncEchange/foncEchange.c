/* ========================================================================== */
/* projet : Fonction : echange de deux valeurs entieres                       */
/* fichier : foncEchange.c                                                    */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>                      /* Pour printf                        */
#include <conio.h>                      /* Pour _getch                        */

/* -------------------------------------------------------------------------- */
/* Declaration de la fonction "echange"                                       */
/* -------------------------------------------------------------------------- */

void echange(int* n1, int* n2);   /* On peut ecrire void echange(int*, int*); */


/* ========================================================================== */
/* PROGRAMME PRINCIPAL                                                        */
/* ========================================================================== */

int main()
{
    int i;
    int j;

    i = 10;
    j = 20;

    printf("Avant echange : i   = %d, j   = %d\n", i, j);
    echange(&i, &j);
    printf("Apres echange : i   = %d, j   = %d\n", i, j);

    return 0;
}



/* ========================================================================== */
/* FONCTION "echange"                                                         */
/* ========================================================================== */

void echange(int* p1, int* p2)
{
    int permut;

    printf("Avant echange : *p1 = %d, *p2 = %d\n", *p1, *p2);
    permut = *p1;
    *p1 = *p2;
    *p2 = permut;
    printf("Apres echange : *p1 = %d, *p2 = %d\n", *p1, *p2);
}
