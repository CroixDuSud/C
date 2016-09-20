#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

/* ========================================================================== */
/* Saisie de la fraction                                                      */
/* ========================================================================== */

int saisie(Fraction *pf)
{
    int retour;
    char ligne[81];

    printf("Introduisez le numerateur : ");
    gets(ligne);

    (*pf).num = atoi(ligne); // (*pf).num <=> pf->num

    printf("Introduisez le denominateur : ");
    gets(ligne);
    (*pf).den = atoi(ligne);

    if ((*pf).den == 0)
    {
        retour = -1;
    }
    else
    {
        retour = 0;
    }

    return retour;
}

/* ========================================================================== */
/* Somme de deux fractions                                                    */
/* ========================================================================== */

Fraction somme(Fraction fraction_1, Fraction fraction_2)
{
    int diviseur;
    Fraction fraction_3;

    (fraction_3.num) = ((fraction_1.num) * (fraction_2.den)) + ((fraction_2.num) * (fraction_1.den));
    (fraction_3.den) = (fraction_1.den) * (fraction_2.den);

    diviseur = pgcd((fraction_3.num), (fraction_3.den));
    (fraction_3.num) = (fraction_3.num) / diviseur;
    (fraction_3.den) = (fraction_3.den) / diviseur;

    return fraction_3;
}

/* ========================================================================== */
/* pgcd de deux entiers                                                       */
/* ========================================================================== */

int pgcd(int n1, int n2)
{
    while (n1 != n2)
    {
        if (n1 > n2) n1 -= n2;
        else         n2 -= n1;
    }
    return n1;
}

/* ========================================================================== */
/* affichage d'une fraction precedee d'un texte                               */
/* ========================================================================== */

void affiche(Fraction fraction_3)
{
    if (fraction_3.den != 1)
    {
        printf("\n%d/%d\n", fraction_3.num, fraction_3.den);
    }
    else
    {
        printf("\n%d\n", fraction_3.num);
    }
}




