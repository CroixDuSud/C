/* ========================================================================== */
/* Travail pratique typeFractions : Fonctions - Fractions - Structures        */
/* ========================================================================== */
/* ========================================================================== */
/* projet : Fonctions - Fractions - Structures                                */
/* fichier : typeFractions.c                                                  */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* ========================================================================== */
/* DECLARATIONS                                                               */
/* ========================================================================== */
typedef struct
{
    int num;
    int den;
} FRACTION;

int saisie(FRACTION*);
void affiche(FRACTION);
FRACTION somme(FRACTION, FRACTION);
int pgcd(int, int);

/* ========================================================================== */
/* Programme principal                                                        */
/* ========================================================================== */

int main()
{
    int r;
    FRACTION f1, f2, f3;

    f2.num = 5;
    f2.den = 2;

    /* -------------------------------------------------------------------------- */
    /* Saisie de la fraction f1                                                   */
    /* -------------------------------------------------------------------------- */
    printf("Saisie de la fraction f1\n");
    r = saisie(&f1);

    while(r < 0)
    {
        printf("Denominateur de la fraction f1 nul !\n\n");
        r = saisie(&f1);
    }

    /* -------------------------------------------------------------------------- */
    /* Calcul de la somme (simplifiee)                                            */
    /* -------------------------------------------------------------------------- */
    f3 = somme(f1, f2);

    /* -------------------------------------------------------------------------- */
    /* Affichage de la somme                                                      */
    /* -------------------------------------------------------------------------- */
    printf("\nSomme de ");
    affiche(f1);
    printf(" et de ");
    affiche(f2);
    printf(" = ");
    affiche(f3);
    printf("\n");

    return 0;
}

/* ========================================================================== */
/* Fonctions de gestion des fractions                                         */
/* ========================================================================== */

/* ========================================================================== */
/* Saisie de la fraction                                                      */
/* ========================================================================== */

int saisie(FRACTION* pf)
{
    int retour;
    char ligne[81];

    printf("Introduisez le numerateur : ");
    gets(ligne);
    pf->num = atoi(ligne);

    printf("Introduisez le denominateur : ");
    gets(ligne);
    pf->den = atoi(ligne);

    if (pf->den <0)
    {
        pf->den = -(pf->den);
        pf->num = -(pf->num);
    }

    if (pf->den == 0)
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

FRACTION somme(FRACTION f1, FRACTION f2)
{
    int PGCD;
    FRACTION f3;

    f3.num = (f1.num * f2.den) + (f2.num * f1.den);
    f3.den = f1.den * f2.den;

    if (f3.num == 0)
    {
        f3.den = 1;
    }
    else
    {
        if (f3.num > 0) PGCD = pgcd(f3.num, f3.den);
        else            PGCD = pgcd(-f3.num, f3.den);

        f3.num = f3.num / PGCD;
        f3.den = f3.den / PGCD;
    }

    return f3;
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
/* Affichage de la fraction                                                   */
/* ========================================================================== */

void affiche(FRACTION f)
{
    if (f.den != 1)
    {
        printf("%d/%d", f.num, f.den);
    }
    else
    {
        printf("%d", f.num);
    }
}
