#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i = 0;
    char tab [10];
    //char nombre;
    char test;
    getche();

    printf("Tapez un nombre entier :\n");

    //nombre = _getch();
    //printf("%d", nombre);
/*
    tab [1] = _getch();
    test = (int)tab[1];
    _putch(test);
*/

while((test=getche())<45 ||test>55)
{
    printf("%c\n",test);
}








/*
    while (tab [i] != '\0');
    {
        tab [i] = _getch();

        if (tab [i] > '0' || tab [i] < '9')
        {
            tab [i] = _getche();
            //_putch(tab [i]);
            i++;
        }
        else
        {
            printf("Veuillez taper un chiffre");
        }
            //printf("%c", mdp [i]// || i < 11);
    }

*/

/*
    printf("\n");
    printf("%s", tab);
    printf("stop");
    */

    return 0;
}
