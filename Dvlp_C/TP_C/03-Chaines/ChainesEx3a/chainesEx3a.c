/* ========================================================================== */
/* projet : TP_Chaine       exercice 3 (version a)                            */
/* fichier : chaineEx3a.c                                                     */
/* -------------------------------------------------------------------------- */
/* Inverser une chaine saisie au clavier                                      */
/* Utilisation d'une chaine intermédiaire pour l'inversion                    */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <string.h>
#include <conio.h>

int main()
{
    char ligne1[81];
    char ligne2[81];
    int i1;
    int i2;
    int longueurLigne;

    /* -------------------------------------------------------------------------- */
    /* Saisie de ligne1                                                           */
    /* -------------------------------------------------------------------------- */
    printf("Entrer une ligne (max 80 caracteres) :\n");
    gets(ligne1);
    longueurLigne = strlen(ligne1);

    /* -------------------------------------------------------------------------- */
    /* Initialisation des indices (i1 : parcours de ligne1 par la fin)            */
    /*                            (i2 : parcours de ligne2 par le debut)          */
    /* -------------------------------------------------------------------------- */
    i1 = longueurLigne - 1;

    for (i2 = 0; i2 < longueurLigne; i2++)
    {
        ligne2[i2] = ligne1[i1];
        i1--;
    }
    ligne2[i2] = 0;                            /* N'oublions pas le 0 final !  */

    strcpy(ligne1, ligne2);
    printf("\n\n%s", ligne1);

    return 0;
}
