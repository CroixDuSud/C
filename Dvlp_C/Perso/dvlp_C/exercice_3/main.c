#include <stdio.h>
#include <stdlib.h>

int main()
{
    double nombre;
    double total = 0.0;

    do
    {
        printf("Entrez un nombre :");
        scanf("%lf", &nombre);
        total = total + nombre;
        printf("total : %lf\n", total);
    }while (total < 100.0);

    return 0;
}
