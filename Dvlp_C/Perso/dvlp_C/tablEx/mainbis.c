#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int tableau [10];
    int i = 0;
    int j = 0; //variable de tri
    int limite = 10;
    int tmp = 0;
    int chiffre;
    int compteur = 0;


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


    // TRI DU TABLEAU


    for (i = 0; i < 10;  i++)
    {
        for (j = i; j < 10; j++)
        {
           if (tableau [i] > tableau [j])
            {
                tmp = tableau [i];
                tableau [i] = tableau [j];
                tableau [j] = tmp;
            }
        }
    }


    // AFFICHER TABLEAU TRIE


    for (i = 0; i < 10; i++)
    {
        printf("%d\n", tableau [i]);
    }


    // TEST PRESENCE TABLEAU


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

    return 0;
}
