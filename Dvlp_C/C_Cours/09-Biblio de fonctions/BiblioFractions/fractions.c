/* ========================================================================== */
/* projet : BIBLIOTHEQUE DE FONCTIONS DE GESTION DES FRACTIONS                */
/* fichier : fractions.c                                                      */
/* -------------------------------------------------------------------------- */
/* fichier contenant l'ensemble des fonctions de la bibliothèque              */
/*           int saisie(FRACTION) : saisie d'une fraction                     */
/*           FRACTION somme(FRACTION, FRACTION) : somme de deux fractions     */
/*           void affiche(FRACTION) : affichage d'une fraction                */
/*           int pgcd(int, int) : retourne le pgcd de 2 entiers               */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <stdlib.h>

#include "fractions.h"


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
    pf->Num = atoi(ligne);

    printf("Introduisez le denominateur : ");
    gets(ligne);
    pf->Den = atoi(ligne);

    if (pf->Den <0)
    {
        pf->Den = -(pf->Den);
        pf->Num = -(pf->Num);
    }

    if (pf->Den == 0)
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

    f3.Num = (f1.Num * f2.Den) + (f2.Num * f1.Den);
    f3.Den = f1.Den * f2.Den;

    if (f3.Num == 0)
    {
        f3.Den = 1;
    }
    else
    {
        if (f3.Num > 0) PGCD = pgcd(f3.Num, f3.Den);
        else            PGCD = pgcd(-f3.Num, f3.Den);

        f3.Num = f3.Num / PGCD;
        f3.Den = f3.Den / PGCD;
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
    if (f.Den != 1)
    {
        printf("%d/%d", f.Num, f.Den);
    }
    else
    {
        printf("%d", f.Num);
    }
}
