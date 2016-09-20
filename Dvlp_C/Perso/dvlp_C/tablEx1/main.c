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
        printf("Entrez un chiffre entre 0 et 10 :\n");
        scanf("%d", &chiffre);
    } while(chiffre > 10);


    // LECTURE DU TABLEAU

    for (i = 0; i < 10;  i++)
    {
        if (tableau [i] == chiffre)
        {
            compteur++;
        }
    }

    printf("Il y a %d fois votre chiffre dans le tableau.\n", compteur);

    return 0;
}
