/* ========================================================================== */
/* projet : Saisie de deux nombres, affichage du ratio                        */
/* fichier : initFloat.c                                                      */
/*----------------------------------------------------------------------------*/
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>

int main()
{
    // déclaration des variables
    float a, b, ratio;

    printf("Introduisez deux nombres : ");
    scanf("%f %f", &a, &b);
    printf("a = %f b = %f\n", a, b);
    if (b == 0.0){
        printf("Ratio impossible !");
    } else {
        ratio = a / b;
        printf("Le rapport est %f \n\n", ratio);
    }

    return 0;
}
