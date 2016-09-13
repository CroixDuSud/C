/* ========================================================================== */
/* projet : Exemple de pointeur illegal                                       */
/* fichier : pointEntierErr.c                                                 */
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


    p = 0;            /* Attention, cette affectation met l'adresse memoire 0  */
    /* dans le pointeur p... danger !                        */

    *p = 10;

    return 0;
}
