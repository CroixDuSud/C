/* ========================================================================== */
/* projet : Tours de Hanoi : récursivité                                      */
/* fichier : foncHanoi.c                                                      */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* -------------------------------------------------------------------------- */
/* Declaration de la fonction hanoi                                           */
/* -------------------------------------------------------------------------- */

void hanoi(int nplateaux, int plateau1, int plateau2);

int main()
{
    int nplateaux;
    char ligne[81];

    printf("Nombre de plateaux : ");
    gets(ligne);
    nplateaux = atoi(ligne);

    hanoi(nplateaux, 1, 2);

    return 0;
}

/* --------------------------------------------------------------------- */
/* Fonction hanoi                                                        */
/* --------------------------------------------------------------------- */

void hanoi(int nplateaux, int plateau1, int plateau2)
{
    if (nplateaux == 1)
    {
        printf("%d vers %d\n", plateau1, plateau2);
    }
    else
    {
        hanoi(nplateaux - 1, plateau1, 6 - plateau1 - plateau2);
        hanoi(1, plateau1, plateau2);
        hanoi(nplateaux - 1, 6 - plateau1 - plateau2, plateau2);
    }
}
