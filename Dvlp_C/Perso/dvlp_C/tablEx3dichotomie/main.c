#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    //int taille;
    int tableau [10];
    //int tailleMax = 20;
    int i = 0;
    int j = 0; //variable de tri
    int limite = 10;
    int tmp = 0;
    int chiffre;
    int compteur = 0;


    // INITIALISATION DU TABLEAU


/*
    do
    {
        printf("Taille du tableau ? (taille max = %d)\n", tailleMax);
        scanf("%d", &taille);

    } while (taille > tailleMax);
*/

     //DEBUG
    //printf("%d\n", taille);




    srand(time(NULL));
    for (i = 0; i < 10; i++)
    {
        tableau [i] = rand() % limite;
        printf("%d", tableau [i]);
        //printf("a");
    }


    //printf("%d\n", i);



    // DEMANDE UNE VALEUR


    do
    {
        printf("\n");
        printf("Entrez un chiffre entre 0 et 10 :\n");
        scanf("%d", &chiffre);
        printf("\n");
    } while(chiffre > 10);


    // TRI DU TABLEAU



    //int borne = 10;
    for (i = 0; i < 9;  i++)
    {
        for (j = i + 1; j < 10; j++)
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
        printf("%d", tableau [i]);
    }


    // TEST PRESENCE TABLEAU TRIE


    i = 0;
    int indexD = 0;
    int indexF = 9;
    int indexM = (indexD + indexF)/2;

    do
	{
		if (chiffre > tableau [indexM])
		{
			indexD = indexM;
			compteur++;
		}
		else //(chiffre < tableau [indexM])
		{
			indexF = indexM;
			compteur++;
		}


	} while (chiffre != tableau [indexM] && indexD <= indexF);


    if (indexD == 0 || indexF == 10)
    {
        printf("\n");
        printf("Votre chiffre n'est pas present dans le tableau.\n");
    }
    else
    {
        printf("\n");
        printf("Votre chiffre est present dans le tableau.\n");
    }

    printf("%d", compteur);

    return 0;
}
