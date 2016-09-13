/* ========================================================================== */
/* projet : Tableau à une dimension : remplissage aléatoire                   */
/* fichier : tablLogiqueIndices.c                                             */
/* -------------------------------------------------------------------------- */
/* Remplissage d'une table de 4 postes entiers par des valeurs tirees         */
/* aleatoirement (entre 0 et 7). La table doit contenir 4 valeurs differentes */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define TAILLE 4


int main()
{
    /* ---------------------------------------------------- */
    int table[TAILLE]; /* Tableau a remplir                                    */
    int iPoste;        /* Indice du poste que l'on remplit                     */
    int iPrec;         /* Indice des postes precedant iPoste (pour verif)      */
    int trouve;        /* La valeur tiree aleatoirement est deja dans          */
    /* le tableau (1), ou pas (0)                           */
    int tirage;        /* Entier tire aleatoirement */
    int cpt=1;
    /* ---------------------------------------------------- */

    /* -------------------------------------------------------------------------- */
    /* Initialisation du tirage aleatoire (on utilise l'horloge)                  */
    /* -------------------------------------------------------------------------- */
    /* La valeur retournee par la fonction time() peut etre aussi stockee dans    */
    /* une variable passee en parametre. Si ce parametre est a NULL, la valeur    */
    /* retournee n'est pas stockee.                                               */
    /* -------------------------------------------------------------------------- */
    srand(time(NULL));

    /* -------------------------------------------------------------------------- */
    /* Remplissage du premier poste                                               */
    /* -------------------------------------------------------------------------- */
    table[0] = rand() % 8;

    /* -------------------------------------------------------------------------- */
    /* Boucle de remplissage des autres postes                                    */
    /* -------------------------------------------------------------------------- */
    for(iPoste = 1; iPoste <= TAILLE - 1; iPoste++)
    {
        do
        {
            tirage = rand() % 8;
            cpt++;
            /* -------------------------------------------------------------------------- */
            /* Verifier que la valeur tiree n'est pas deja dans les postes precedents     */
            /* -------------------------------------------------------------------------- */
            trouve = 0;

            for(iPrec = 0; iPrec < iPoste; iPrec++)
            {
                if (table[iPrec] == tirage) trouve = 1;
            }
        }
        while (trouve != 0);

        table[iPoste] = tirage;
    }

    /* -------------------------------------------------------------------------- */
    /* Affichage du resultat                                                      */
    /* -------------------------------------------------------------------------- */
    for(iPoste = 0; iPoste <= TAILLE - 1; iPoste++)
    {
        printf("%d  ", table[iPoste]);
    }
    printf("Nombre de tirage : %d\n", cpt);

    return 0;
}
