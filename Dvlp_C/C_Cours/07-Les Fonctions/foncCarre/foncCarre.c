/* ========================================================================== */
/* projet : calcul du carre et du cube d'un nombre entier                     */
/* fichier : foncCarre.c                                                      */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

/* ========================================================================== */
/* DECLARATIONS                                                               */
/* ========================================================================== */

#include <stdio.h>                      /* Pour printf()                      */
#include <stdlib.h>                     /* Pour srand() et rand()             */
#include <conio.h>                      /* Pour _getch()                      */
#include <time.h>                       /* Pour time()                        */

/* -------------------------------------------------------------------------- */
/* Declaration des prototypes des fonctions carre() et cube()                 */
/* -------------------------------------------------------------------------- */
int carre(int nombre);
int cube(int);



/* ========================================================================== */
/* PROGRAMME PRINCIPAL                                                        */
/* ========================================================================== */

int main()
{
    int i;
    int n;

    /* -------------------------------------------------------------------------- */
    /* Tirage aleatoire de 10 valeurs. Affichage de ces valeurs et de leur carre. */
    /*                                                                            */
    /* La fonction srand() permet d'initialiser la serie de nombres aleatoires en */
    /* utilisant la date et l'heure systeme. A defaut de l'utilisation de cette   */
    /* fonction, la serie de nombres sera toujours la meme.                       */
    /*                                                                            */
    /* Une valeur constante RAND_MAX (0x7fff ou 32767) indique la valeur maximale */
    /* de l'entier que peut retourner la fonction rand().                         */
    /* -------------------------------------------------------------------------- */

    srand(time(NULL));

    for (i = 0; i < 10; i++)
    {
        n = rand() % 20;
        printf("Nombre : %2d   Carre : %3d   Cube : %5d\n", n, carre(n), cube(n));
    }

    return 0;
}



/* ========================================================================== */
/* FONCTION carre                                                             */
/* ========================================================================== */

int carre(int nombre)
{
    return nombre * nombre;
}


/* ========================================================================== */
/* FONCTION cube                                                              */
/* ========================================================================== */

int cube(int nombre)
{
    return nombre * nombre * nombre;
}
