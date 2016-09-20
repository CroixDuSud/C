#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x; //ligne
    int y; //colonne
    int n; //taille du tableau, nombre de lignes du triangle de Pascal
    int tab [16][16];

    do
    {
        printf("Entrez un nombre compris entre 1 et 15 (inclus) :\n");
        scanf("%d", &n);
    } while (n < 0 || n > 15);


    for (x = 0; x <= n; x++)
    {
        tab [x][x] = 1;
        tab [x][0] = 1;

        for (y = 1; y < x; y++)
        {
            tab [x][y] = tab [x-1][y] + tab [x-1][y-1];
        }
    }

    for (x = 0; x <= n; x++)
    {
        for (y = 0; y <= x; y++)
        {
            if (tab[x][y])
            {
                printf("%5d", tab[x][y]);
            }
        }
        printf("\n");
    }

    return 0;
}
