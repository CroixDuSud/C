/* ========================================================================== */
/* projet : Tableau à une dimension                                           */
/* fichier : tablExemple.c                                                    */
/* -------------------------------------------------------------------------- */
/* Calcul de la moyenne de 10 notes entrees au clavier.                       */
/* Nombre d'eleves ayant plus de la moyenne.                                  */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>

int main()
{
    int i;
    int somme;                /* Somme des notes                               */
    float moyenne;            /* Moyenne des dix notes                         */
    int nombre;               /* Nombre d'eleves ayant plus de la moyenne      */
    int t[10];                /* Tableau qui va contenir les dix notes saisies */

    /* -------------------------------------------------------------------------- */
    /* Saisie des 10 notes                                                        */
    /* -------------------------------------------------------------------------- */
    for (i = 0; i < 10; i++)
    {
        printf("Entrez la note numero %d : ", i+1);
        scanf("%d", &t[i]);
    }

    /* -------------------------------------------------------------------------- */
    /* Calcul de la somme des notes puis de la moyenne                            */
    /* -------------------------------------------------------------------------- */
    somme = 0;
    for (i = 0; i < 10; i++)
    {
        somme += t[i];
    }

    moyenne = (float) somme / 10;
    printf("\n\nMoyenne de la classe : %6.2f\n", moyenne);

    /* -------------------------------------------------------------------------- */
    /* Recherche du nombre de notes supérieures à la moyenne                      */
    /* -------------------------------------------------------------------------- */
    nombre = 0;
    for (i = 0; i < 10; i++)
    {
        if (t[i] > moyenne) nombre++;
    }

    printf("%d eleve(s) ont plus de la moyenne (%6.2f)\n\n", nombre, moyenne);

    return 0;
}
