/* ========================================================================== */
/* projet : Allocation dynamique d'un tableau à deux dimensions               */
/* fichier : poinAllocDynTabl2D.c                                              */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int* tab;
    int nLig, nCol;

    /* -------------------------------------------------------------------------- */
    /* Initialisation du générateur de nombres aléatoires                         */
    /* -------------------------------------------------------------------------- */
    srand((unsigned)time(NULL));

    /* -------------------------------------------------------------------------- */
    /* Allocation dynamique du tableau (2 lignes, 4 colonnes : 8 postes)          */
    /* -------------------------------------------------------------------------- */
    tab = (int*)calloc(8, sizeof(int));

    /* -------------------------------------------------------------------------- */
    /* On ne peut plus utiliser la notation tab[i][j] car cette notation          */
    /* suppose que l'on connaisse la taille d'une ligne. L'allocation dynamique   */
    /* ne permet pas d'avoir ce renseignement... On peut malgré tout utiliser     */
    /* deux indices, mais en se chargeant soit même du calcul...                  */
    /* -------------------------------------------------------------------------- */
    for (nLig = 0; nLig < 2; nLig++)
    {
        for (nCol = 0; nCol < 4; nCol++)
        {
            *(tab + (4 * nLig) + nCol) = rand();
        }
    }

    /* -------------------------------------------------------------------------- */
    /* Affichage du tableau                                                       */
    /* -------------------------------------------------------------------------- */
    for (nLig = 0; nLig < 2; nLig++)
    {
        for (nCol = 0; nCol < 4; nCol++)
        {
            printf("tab[%d][%d] = %5d ",
                   nLig, nCol, *(tab + (4 * nLig) + nCol));
        }
        printf("\n");
    }
    printf("\n\n");

    return 0;
}
