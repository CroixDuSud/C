#include <stdio.h>
#include <stdlib.h>

/*===================================================================================================
==== Programme pour remplacer une valeur dans un tableau en passant par un pointeur =================
===================================================================================================*/

void move (int valeur, int *tableau, int pos); // prototype
void display (int *tableau);

int main(int argc, char const *argv[])
{
    int array[] = {1,10,100,1000,10000,1000000,10000000};
    int i = 0;
    int val;

    printf("Valeur a entrer dans le tableau : ");
    scanf("%d", &val); // demande de la valeur à mettre dans le tableau

    do
    {
        printf("\nPosition de l'element a remplacer : ");
        scanf("%d", &i);
    }while (i > 6);  // position de l'élément à remplacer dans le tableau

    printf("\nValeur a remplacer : %d\n\n", array[i]);

    move (val, array, i); // appel de la fonction move

    printf("Valeur ajoutee : %d\n\n", array[i]); // affichage du résultat

    display (array);

    return 0;
}

void move (int valeur, int *tableau, int pos) // code source de la fonction
{
    *(tableau + pos) = valeur;
}

void display (int *tableau)
{
    int i;

    for (i = 0; i < 7; i++)
    {
        printf(" %d ", tableau [i]);
    }
}
