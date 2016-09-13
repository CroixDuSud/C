/* ========================================================================== */
/* projet : Fonction : utilite de la declaration du fichier .h                */
/* fichier : foncSqrt.c                                                       */
/* -------------------------------------------------------------------------- */
/* Remarque : ce programme est declare dans un fichier d'extension .c         */
/*            S'il est declare dans un fichier .cpp, le compilateur genere    */
/*            une erreur...                                                   */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>                      /* Pour printf                        */
#include <conio.h>                      /* Pour _getch                        */

#include <math.h>                       /* Pour sqrt                          */


int main()                             /* En l'absence de math.h, le         */
{
    /* programme tourne mais donne un     */
    double x, y;                         /* resultat faux.                     */
    /* En l'absence du prototype de       */
    x = 4;                               /* sqrt, le type de valeur            */
    y = sqrt(x);                         /* retournee est considere comme      */
    /* un entier. Or sqrt doit retourner  */
    /* un reel (double)...                */

    printf("\nLa racine carree de %f est %f\n", x, y);

    return 0;
}
