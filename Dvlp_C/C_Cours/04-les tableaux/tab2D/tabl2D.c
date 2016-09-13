/* ========================================================================== */
/* projet : Tableau à deux dimension                                          */
/* fichier : tabl2D.c                                                         */
/* -------------------------------------------------------------------------- */
/* Remplissage aleatoire du tableau.                                          */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main()
{
    int tab[3][4];            /* Tableau de 3 lignes et 4 colonnes             */
    int i, j;                 /* Indices de parcours du tableau                */

    /* -------------------------------------------------------------------------- */
    /* Initialisation du tirage aleatoire (on utilise l'horloge)                  */
    /* -------------------------------------------------------------------------- */
    /* La valeur retournee par la fonction time() peut etre aussi stockee dans    */
    /* une variable passee en parametre. Si ce parametre est a NULL, la valeur    */
    /* retournee n'est pas stockee.                                               */
    /* -------------------------------------------------------------------------- */
    srand(time(NULL));

    /* -------------------------------------------------------------------------- */
    /* Remplissage du tableau                                                     */
    /* -------------------------------------------------------------------------- */
    /* Les nombres tires aleatoirement sont compris :                             */
    /*                                                                            */
    /*    entre 1 et 10 pour la premiere colonne (j == 0)                         */
    /*    entre 11 et 20 pour la deuxieme colonne (j == 1)                        */
    /*    entre 21 et 30 pour la troisieme colonne (j == 2)                       */
    /*    entre 31 et 40 pour la quatrieme colonne (j == 3)                       */
    /* -------------------------------------------------------------------------- */
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            tab[i][j] = (j * 10) + rand() % 10 + 1;
        }
    }

    /* -------------------------------------------------------------------------- */
    /* Impression du tableau                                                      */
    /* -------------------------------------------------------------------------- */
    printf("Tableau :\n\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%4d    ", tab[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    return 0;
}
