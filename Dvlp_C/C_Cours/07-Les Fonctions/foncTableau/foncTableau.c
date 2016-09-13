/* ========================================================================== */
/* projet : Fonction et tableau                                               */
/*                    Calcul de la moyenne des valeurs d'un tableau           */
/* fichier : foncTableau.c                                                    */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>                                 /* Pour le tirage aleatoire */

#define DIMENSION 15

/* -------------------------------------------------------------------------- */
/* Declaration de la fonction "moyenne"                                       */
/* -------------------------------------------------------------------------- */
/* int tab[] est une autre syntaxe pour int* tab, que l'on peut utiliser      */
/* le pointeur tab pointe vers un tableau...                                  */
/* -------------------------------------------------------------------------- */

float moyenne(int tab[], int nombrePostes);


int main()
{
    int tableau[DIMENSION];
    int i;
    float moy;

    srand(time(NULL));

    for(i = 0; i < DIMENSION; i++)
    {
        tableau[i] = rand() % 1000;
        printf("\n%5d", tableau[i]);
    }

    moy = moyenne(tableau, DIMENSION);
    printf("\n\nMoyenne : %8.2f\n", moy);

    return 0;
}


/* -------------------------------------------------------------------------- */
/* Fonction "moyenne"                                                         */
/* -------------------------------------------------------------------------- */

float moyenne(int tab[], int nombrePostes)
{
    int i;
    float moy;

    moy = 0;
    for (i = 0; i < nombrePostes; i++)
    {
        moy += tab[i];
    }

    return moy / nombrePostes;
}
