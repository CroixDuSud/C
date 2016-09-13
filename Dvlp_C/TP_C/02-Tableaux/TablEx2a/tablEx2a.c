/* ========================================================================== */
/* projet : TP sur les Tableaux     exercice 2  (version a)                   */
/* fichier : tablEx2a.c                                                       */
/* -------------------------------------------------------------------------- */
/* Dire si une valeur est presente dans un tableau a une dimension            */
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
    while ((i <= 9) && (trouve == 'n'));

    if (trouve == 'o')
    {
        printf("\n\nLa valeur %d est trouvee dans le tableau\n\n", valeur);
        printf("la position est %d : ", i);
    }
    else
    {
        printf("\n\nLa valeur %d n'est pas trouvee dans le tableau\n\n", valeur);
    }

    return 0;
}
