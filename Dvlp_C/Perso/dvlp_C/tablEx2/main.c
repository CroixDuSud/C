#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int tableau [10];
    int i = 0;
    int limite = 10;
    int compteur = 0;
    int chiffre;

    // INITIALISATION DU TABLEAU

    srand(time(NULL));
    for (i = 0; i < 11; i++)
    {
        tableau [i] = rand() % limite;
        printf("%d\n", tableau [i]);
    }

    // DEMANDE UNE VALEUR

    do
    {
        printf("Entrez un nombre entre 0 et 10 :\n");
        scanf("%d", &chiffre);
    } while(chiffre > 10);


    // TEST PRESENCE TABLEAU


    i = 0;

    while (tableau [i] != chiffre && i < 10)
    {
        i++;
    }

    if (i == 10)
    {
        printf("Votre chiffre n'est pas present dans le tableau.\n");
    }
    else
    {
        printf("Votre chiffre est present dans le tableau.\n");
    }


    // Deuxième méthode de TEST


    /*
    for (i = 0; i < 10; i++)
    {
        if (tableau [i] == chiffre)
        {
            compteur++;
        }
    }

    if (compteur != 0)
    {
        printf("Votre chiffre est present dans le tableau.\n");
    }
    else
    {
        printf("Votre chiffre n'est pas present dans le tableau.\n");
    }

    */
    return 0;
}
