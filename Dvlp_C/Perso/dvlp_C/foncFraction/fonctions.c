#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

// Fonction de saisie de la fraction

int fractionDef(int *num, int *den)
{
    printf("Introduisez le numérateur\n");
    scanf("%d", num);
    printf("Introduisez le dénominateur\n");
    scanf("%d", den);

    if (den == 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

// Fonction pour faire la somme des fractions

void fractionSum(int num1, int num2, int den1, int den2, int *numSum, int *denSum)
{
    int *numSum; // numérateur de la fraction somme
    int *denSum; // quotient de la fraction sommme

    *numSum = num1*den2 + num2*den1;
    *denSum = den1*den2;
}

// Fonction pour afficher la fraction obtenue par somme

void fractionDisplay(const char*, int numSum, int denSum)
{
    printf("La fraction somme est %d / %d .", numSum, denSum);
}



