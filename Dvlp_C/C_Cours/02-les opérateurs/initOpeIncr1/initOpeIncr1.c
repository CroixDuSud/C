/* ========================================================================== */
/* projet : Utilisation des operateurs ++ --                                  */
/* fichier : initOpeIncr1.c                                                   */
/*----------------------------------------------------------------------------*/
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>

int main()
{
    int a, b, sum;

    a = b = 5;
    sum = a + b;   printf("a = %d    b = %d      sum = %d \n", a, b, sum);
    sum = a++ + b; printf("a = %d    b = %d      sum = %d \n", a, b, sum);
    sum = ++a + b; printf("a = %d    b = %d      sum = %d \n", a, b, sum);
    sum = --a + b; printf("a = %d    b = %d      sum = %d \n", a, b, sum);
    sum = a-- + b; printf("a = %d    b = %d      sum = %d \n", a, b, sum);
    sum = a + b;   printf("a = %d    b = %d      sum = %d \n", a, b, sum);

    return 0;
}




