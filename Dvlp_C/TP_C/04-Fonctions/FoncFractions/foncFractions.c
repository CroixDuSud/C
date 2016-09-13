/* ========================================================================== */
/* projet : Fonctions - Fractions                                             */
/* fichier : foncFractions.c                                                  */
/* -------------------------------------------------------------------------- */
/* Calcul de la somme de deux fractions                                       */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

/* ========================================================================== */
/* DECLARATIONS                                                               */
/* ========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int saisie(int*, int*);
void somme(int, int, int, int, int*, int*);
int pgcd(int, int);
void affiche(const char*, int, int);



/* ========================================================================== */
/* Programme principal                                                        */
/* ========================================================================== */

int main()
{
    int r;
    int n1, d1, n2, d2, n3, d3;

    /* -------------------------------------------------------------------------- */
    /* Saisie des fractions                                                       */
    /* -------------------------------------------------------------------------- */
    printf("Saisie fraction 1\n");
    r = saisie(&n1, &d1);

    while(r < 0)
    {
        printf("Denominateur fraction 1 nul !\n\n");
        r = saisie(&n1, &d1);
    }

    printf("\n\nSaisie fraction 2\n");
    r = saisie(&n2, &d2);

    while(r < 0)
    {
        printf("Denominateur fraction 2 nul !\n\n");
        r = saisie(&n2, &d2);
    }

    /* -------------------------------------------------------------------------- */
    /* Calcul de la somme (simplifiee)                                            */
    /* -------------------------------------------------------------------------- */
    somme(n1, d1, n2, d2, &n3, &d3);


    /* -------------------------------------------------------------------------- */
    /* Affichage de la somme                                                      */
    /* -------------------------------------------------------------------------- */
    affiche("\nSomme des fractions :", n3, d3);

    return 0;
}



/* ========================================================================== */
/* Saisie de la fraction                                                      */
/* ========================================================================== */

int saisie(int* pNum, int* pDen)
{
    int retour;
    char ligne[81];

    printf("Introduisez le numerateur : ");
    gets(ligne);
    *pNum = atoi(ligne);

    printf("Introduisez le denominateur : ");
    gets(ligne);
    *pDen = atoi(ligne);

    if (*pDen == 0)
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

void somme(int num1, int den1, int num2, int den2, int* pNum3, int* pDen3)
{
    int diviseur;

    *pNum3 = (num1 * den2) + (num2 * den1);
    *pDen3 = den1 * den2;

    diviseur = pgcd(*pNum3, *pDen3);
    *pNum3 = *pNum3 / diviseur;
    *pDen3 = *pDen3 / diviseur;
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

void affiche(const char* texte, int num, int den)
{
    if (den != 1)
    {
        printf("%s %d/%d\n", texte, num, den);
    }
    else
    {
        printf("%s %d\n", texte, num);
    }
}
