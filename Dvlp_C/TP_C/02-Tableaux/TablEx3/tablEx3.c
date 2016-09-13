/* ========================================================================== */
/* projet : TP sur les Tableaux     exercice 3                                */
/* fichier : tablEx3.c                                                       */
/* -------------------------------------------------------------------------- */
/* Tableau à une dimension                                                    */
/* Dire si une valeur est presente dans un tableau trie en ordre croissant    */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>

int main()
{
    int tableau[10] = {1, 3, 5, 7, 8, 14, 23, 33, 45, 112};    /* Tableau trie   */

    int i;                    /* Indice de parcours du tableau                 */
    int valeur;               /* Valeur a cherche dans le tableau              */
    int trouve;               /* 'o' valeur trouvee, 'n' non trouvee           */

    /* -------------------------------------------------------------------------- */
    /* Saisie de la valeur                                                        */
    /* -------------------------------------------------------------------------- */
    printf("Entrez la valeur a chercher : ");
    scanf("%d", &valeur);

    /* -------------------------------------------------------------------------- */
    /* Boucle de recherche : au debut, la valeur n'est pas trouvee (trouve = 'n') */
    /* -------------------------------------------------------------------------- */
    trouve = 'n';
    i = 0;

    do
    {
        printf("i : %d\n", i);
        if (tableau[i] == valeur) trouve = 'o';
        i++;
    }
    while ((i <= 9) && (trouve == 'n') && (tableau[i] <= valeur));

    if (trouve == 'o')
    {
        printf("\n\nLa valeur %d est trouvee dans le tableau\n\n", valeur);
    }
    else
    {
        printf("\n\nLa valeur %d n'est pas trouvee dans le tableau\n\n", valeur);
    }

    return 0;
}
