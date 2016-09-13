/* ========================================================================== */
/* projet : Saisie de deux nombres, affichage de la somme                     */
/* fichier : initInt.c                                                        */
/*----------------------------------------------------------------------------*/
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>

int main()
{
    // déclaration des variables
    int a, b, sum;

    printf("Introduisez deux nombres : ");
    scanf("%d %d", &a, &b);
    sum = a + b;
    printf("La somme est %d\n\n", sum);

    return 0;
}

