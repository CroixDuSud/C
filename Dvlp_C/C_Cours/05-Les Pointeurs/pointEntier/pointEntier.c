/* ========================================================================== */
/* projet : Exemple de pointeur                                               */
/* fichier : pointEntier.c                                                    */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>

int main()
{
    int* p;           /* Pointeur sur un entier. Cette ecriture suggere que la */
    /* variable p est du type pointeur sur un entier (int*)  */
    /* On pourrait aussi ecrire int *p, qui suggere que la   */
    /* variable *p est du type entier, ce qui est aussi vrai */


    int n;

    n = 17;
    printf("n = %d\n", n);

    p = &n;                         /* Affectation de l'adresse de n dans p    */

    (*p)++;                         /* Incrementation (++) de la valeur situee */
    /* a l'adresse p (*p)                      */
    printf("n = %d\n", n);

    return 0;
}
