/* ========================================================================== */
/* projet : Allocation dynamique d'un tableau d'entiers                       */
/* fichier : pointAllocDynTabl.c                                              */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define NOMBRE 8

int main()
{
    int* tableau;
    int i;

    /* -------------------------------------------------------------------------- */
    /* Initialisation du g�n�rateur de nombres al�atoires                         */
    /* -------------------------------------------------------------------------- */
    srand((unsigned)time(NULL));

    /* -------------------------------------------------------------------------- */
    /* Allocation dynamique du tableau                                            */
    /* -------------------------------------------------------------------------- */
    tableau = (int*) calloc(NOMBRE, sizeof(int));

    /* -------------------------------------------------------------------------- */
    /* Initialisation du tableau                                                  */
    /* -------------------------------------------------------------------------- */
    for (i = 0; i < NOMBRE; i++)
    {
        tableau[i] = rand();
    }

    /* -------------------------------------------------------------------------- */
    /* Affichage du tableau                                                       */
    /* -------------------------------------------------------------------------- */
    for (i = 0; i < NOMBRE; i++)
    {
        printf("tableau[%d] = %7d\n", i, tableau[i]);
    }

    return 0;
}