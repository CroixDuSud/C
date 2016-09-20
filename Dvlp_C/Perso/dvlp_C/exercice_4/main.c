#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nombre = 0;
    int compteur = 0;


    for (compteur = 0; compteur < 5; compteur++)
    {
        printf("Tapez un nombre n : ");
        scanf("%d", &nombre);
        int diviseur = 2;

        while (nombre % diviseur != 0) //reste différent de 0 -> reste = n % diviseur
        {
        diviseur++;
        }

        if (diviseur == nombre)
        {
        printf("n est un nombre premier\n");
        }
        else
        {
        printf("diviseur : %d\n", diviseur);
        }
    }

    return 0;
}
