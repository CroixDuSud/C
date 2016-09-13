/* ========================================================================== */
/* projet : Utilisation des operateurs de conversion (cast)                   */
/* fichier : initOpeCast.c                                                    */
/* -------------------------------------------------------------------------- */
/* Calcul du ratio de deux nombres entiers.                                   */
/* L'un des trois appels de "printf" dans le programme ci-dessous affiche le  */
/* résultat de la division entière de a par b, (3.000000)                     */
/*----------------------------------------------------------------------------*/
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>

int main()
{
    int a, b;
    float f;

    f = 25.50;
     a = f;
    //a = 10;
    b = 3;
    f = a;

    printf("f= %f \n", f);
    printf("Le rapport est %f\n", (float) a / b);
    printf("Le rapport est %f\n", (float) a / (float) b);
    printf("Le rapport est %f\n", a / (float) b);
    printf("Le rapport est %f\n", (float) (a / b));
    printf("Le rapport est %d\n", a / b);

    return 0;
}

