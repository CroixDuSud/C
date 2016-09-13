/* ========================================================================== */
/* projet : TP sur les Tableaux     exercice 1                                */
/* fichier : tablEx1.c                                                        */
/* -------------------------------------------------------------------------- */
/* Tableau � une dimension                                                    */
/* Compter le nombre de fois qu'une valeur est presente dans un tableau       */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>

int main()
{
    int tableau[10] = {1, 3, 8, 5, 14, 3, 3, 5, 12, 7};      /* Tableau        */

    int i;                    /* Indice de parcours du tableau                 */
    int valeur;               /* Valeur a cherche dans le tableau              */
    int nombre;               /* Nombre de fois ou "valeur" est dans "tableau" */

    /* -------------------------------------------------------------------------- */
    /* Saisie de la valeur                                                        */
    /* -------------------------------------------------------------------------- */
    printf("Entrez la valeur a compter : ");
    scanf("%d", &valeur);

    /* -------------------------------------------------------------------------- */
    /* Calcul du nombre cherche                                                   */
    /* -------------------------------------------------------------------------- */
    nombre = 0;

    for (i = 0; i < 10; i++)
    {
        printf("%d\n", tableau[i]);
        if (tableau[i] == valeur) nombre++;
    }

    printf("\n\nLa valeur %d est presente %d fois dans le tableau\n\n",
           valeur,
           nombre);

    return 0;
}
