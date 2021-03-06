/* ========================================================================== */
/* projet : TP sur les Tableaux     triangle de Pascal  (version 3)           */
/* fichier : tablPascal3.c                                                    */
/* -------------------------------------------------------------------------- */
/* Triangle de Pascal : Allocation dynamique.                                 */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>                    /* Pour scanf, printf...                */
#include <conio.h>                    /* Pour _getch                          */
#include <malloc.h>                   /* Pour calloc                          */

int main()
{
    int* l1;                           /* ligne precedente                     */
    int* l2;                           /* ligne courante                       */
    int* permut;                       /* variable de permutation des adresses */
    int lig,col;                       /* indices de ligne,de colonne          */
    int nbl;                           /* nombre de lignes a afficher          */

    /* -------------------------------------------------------------------------- */
    /* Nombre de lignes du triangle de Pascal a afficher                          */
    /* -------------------------------------------------------------------------- */
    printf("Entrez le nombre de ligne(s) du tableau : ");
    scanf("%d", &nbl);

    /* -------------------------------------------------------------------------- */
    /* Allocation dynamique des deux tableaux                                     */
    /* -------------------------------------------------------------------------- */
    l1 = (int*) calloc(nbl, sizeof(int));
    l2 = (int*) calloc(nbl, sizeof(int));

    /* -------------------------------------------------------------------------- */
    /* Initialisation de la premiere ligne du triangle : premiere colonne a 1     */
    /* -------------------------------------------------------------------------- */
    l1[0] = 1;
    printf("%-5d\n", l1[0]);

    /* -------------------------------------------------------------------------- */
    /* Boucle de calcul et d'affichage des lignes suivantes                       */
    /* -------------------------------------------------------------------------- */
    for (lig = 1; lig < nbl; lig++)
    {

        /* -------------------------------------------------------------------------- */
        /* Affichage de la premiere colonne                                           */
        /* -------------------------------------------------------------------------- */
        l2[0] = 1;
        printf("%-5d", l2[0]);

        /* -------------------------------------------------------------------------- */
        /* Boucle sur les colonnes                                                    */
        /* -------------------------------------------------------------------------- */
        for (col = 1; col < lig; col++)
        {
            l2[col] = l1[col] + l1[col - 1];
            printf("%-5d", l2[col]);
        }

        /* -------------------------------------------------------------------------- */
        /* Affichage de la diagonale                                                  */
        /* -------------------------------------------------------------------------- */
        l2[lig] = 1;
        printf("%-5d\n", l2[lig]);

        /* -------------------------------------------------------------------------- */
        /* Transfert de l2 dans l1                                                    */
        /* -------------------------------------------------------------------------- */
        permut = l1;
        l1 = l2;
        l2 = permut;
    }

    return 0;
}
