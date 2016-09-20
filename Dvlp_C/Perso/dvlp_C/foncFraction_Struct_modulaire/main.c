#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"


/* ========================================================================== */
/* Programme principal                                                        */
/* ========================================================================== */


int main(int argc, char const *argv[])
{
	int r;
    Fraction fraction_1;
    Fraction fraction_2;
    Fraction fraction_3;

    /* -------------------------------------------------------------------------- */
    /* Saisie des fractions                                                       */
    /* -------------------------------------------------------------------------- */

    printf("Saisie fraction 1\n");
    r = saisie(&fraction_1);

    while(r < 0)
    {
        printf("Denominateur fraction 1 nul !\n\n");
        r = saisie(&fraction_1);
    }

    printf("\n\nSaisie fraction 2\n");
    r = saisie(&fraction_2);

    while(r < 0)
    {
        printf("Denominateur fraction 2 nul !\n\n");
        r = saisie(&fraction_2);
    }


    /* -------------------------------------------------------------------------- */
    /* Calcul de la somme (simplifiee)                                            */
    /* -------------------------------------------------------------------------- */
    fraction_3 = somme(fraction_1, fraction_2); // somme(n1, d1, n2, d2, &n3, &d3);

    /* -------------------------------------------------------------------------- */
    /* Affichage de la somme                                                      */
    /* -------------------------------------------------------------------------- */
    affiche(fraction_3);

	return 0;
}
