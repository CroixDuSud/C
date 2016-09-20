#include <stdio.h>
#include <stdlib.h>

void ex1()
{
    double nbr = 0;
    double sqrt (double);
    double racine;
    double sum = 0;

    for (nbr = 0 ; nbr < 10 ; nbr++)
    {
        racine = sqrt (nbr);
        printf("Racine de %lf : %lf\n", nbr, racine);

        sum = sum + racine;
    }

    printf("Cumul des racines carrées : %lf\n", sum);
}

void ex2()
{
    double nbr = 0.0;
    double sqrt (double);
    double racine;
    double sum = 0;

    do
    {
        racine = sqrt (nbr);
        printf("Racine de %lf : %lf\n", nbr, racine);
        nbr++;
        sum = sum + racine;
    } while (sum < 30);

    printf("Cumul des racines carrées : %lf\n", sum);
}

void ex3()
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
}

void ex4()
{
    int nombre = 0;
    int compteur = 0;


    for (compteur = 0; compteur < 5; compteur++)
    {
        printf("Tapez un nombre n : ");
        scanf("%d", &nombre);
        int diviseur = 2;

        while (nombre % diviseur != 0) //vérifie les diviseurs
        {
        diviseur++;
        }

        if (diviseur == nombre)
        {
        printf("n est un nombre premier\n");
        }
        else
        {
        printf("%d\n", diviseur);
        }
    }
}

void ex5()
{
    int nombre = 0;
    int compteur = 0;

    do
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
        compteur++; //compte le nombre de nombres premiers
        }
        else
        {
        printf("diviseur : %d\n", diviseur);
        }
    }while (compteur != 3);
}
