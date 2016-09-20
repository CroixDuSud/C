#include <stdio.h>
#include <stdlib.h>

int main()
{
    int exercice;

    printf("Choisissez votre exercice (1 a 5) : \n");
    scanf("%d", &exercice);

    switch (exercice)
    {
    case 1:
        ex1();
        break;
    case 2:
        ex2();
        break;
    case 3:
        ex3();
        break;
    case 4:
        ex4();
        break;
    case 5:
        ex5();
        break;
    default:
        printf("Tu veux des lunettes ? Tape un chiffre de 1 a 5.\n\n\n");
        break;
    }

    return 0;
}
