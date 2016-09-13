/* ========================================================================== */
/* projet : TP sur les Tableaux     triangle de Pascal  (version 1)           */
/* fichier : tablPascal1.c                                                    */
/* -------------------------------------------------------------------------- */
/* Triangle de Pascal : Utilisation d'un tableau � deux dimensions.           */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>                            /* Pour scanf, printf...        */
#include <conio.h>                            /* Pour _getch                  */

int main()
{
    int tab[16][16];                           /* Tableau de travail           */
    int lig,col;                               /* indices de ligne, de colonne */
    int nbl;                                   /* nombre de lignes a afficher  */

    /* -------------------------------------------------------------------------- */
    /* Nombre de lignes du triangle de Pascal a afficher                          */
    /* -------------------------------------------------------------------------- */
    printf("Entrez le nombre de ligne(s) du tableau : ");
    scanf("%d", &nbl);

    /* -------------------------------------------------------------------------- */
    /* Initialisation de la premiere ligne du triangle : premiere colonne a 1     */
    /* -------------------------------------------------------------------------- */
    tab[0][0] = 1;
    printf("%-5d\n", tab[0][0]);

    /* -------------------------------------------------------------------------- */
    /* Boucle de calcul et d'affichage des lignes suivantes                       */
    /* -------------------------------------------------------------------------- */
    for (lig = 1; lig < nbl; lig++)
    {

        /* -------------------------------------------------------------------------- */
        /* Affichage de la premiere colonne                                           */
        /* -------------------------------------------------------------------------- */
        tab[lig][0] = 1;
        printf("%-5d", tab[lig][0]);

        /* -------------------------------------------------------------------------- */
        /* Boucle sur les colonnes (calcul et affichage)                              */
        /* -------------------------------------------------------------------------- */
        for (col = 1; col < lig; col++)
        {
            tab[lig][col] = tab[lig - 1][col] + tab[lig - 1][col - 1];
            printf("%-5d", tab[lig][col]);
        }

        /* -------------------------------------------------------------------------- */
        /* Affichage de la diagonale                                                  */
        /* -------------------------------------------------------------------------- */
        tab[lig][lig] = 1;
        printf("%-5d\n", tab[lig][lig]);
    }

    return 0;
}
