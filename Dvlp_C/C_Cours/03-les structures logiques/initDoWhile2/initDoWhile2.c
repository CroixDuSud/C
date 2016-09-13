/* ========================================================================== */
/* projet : Utilisation de la structure répétitive DO ... WHILE  avec IF      */
/* fichier : initDoWhile2.c                                                   */
/*----------------------------------------------------------------------------*/
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>

int main()
{
    float a, b, ratio;
    char ch;

    do
    {
        printf("Introduisez deux nombres : ");
        scanf("%f %f", &a, &b);

        if (b == 0)
        {
            printf("Le rapport n'est pas defini.\n");
        }
        else
        {
            ratio = a / b;
            printf("Le rapport est %g %f %e \n", ratio, ratio, ratio);
        }

        printf("Taper touche ESC pour sortir\n");
        ch = _getch();
    }
    while (ch != 27);

    return 0;
}
