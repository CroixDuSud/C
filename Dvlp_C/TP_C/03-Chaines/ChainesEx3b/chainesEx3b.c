/* ========================================================================== */
/* projet : TP_Chaine       exercice 3 (version b)                            */
/* fichier : chaineEx3b.c                                                     */
/* -------------------------------------------------------------------------- */
/* Inverser une chaine saisie au clavier                                      */
/* l'inversion se fait dans la même chaine                                    */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <string.h>
#include <conio.h>

int main()
{
    char ligne[81];
    int i1;
    int i2;
    char car;

    /* -------------------------------------------------------------------------- */
    /* Saisie de ligne1                                                           */
    /* -------------------------------------------------------------------------- */
    printf("Entrer une ligne (max 80 caracteres) :\n");
    gets(ligne);
    //i2 = strlen(ligne1) - 1;

    /* -------------------------------------------------------------------------- */
    /* Initialisation des indices (i1 : parcours de ligne1 par la fin)            */
    /*                            (i2 : parcours de ligne2 par le debut)          */
    /* -------------------------------------------------------------------------- */

    for (i1 = 0, i2 = strlen(ligne) - 1; i1 <= i2; i1++, i2--)
    {
        car = ligne[i2];
        ligne[i2] = ligne[i1];
        ligne[i1] = car;
    }

    printf("\n\n%s", ligne);

    return 0;
}
