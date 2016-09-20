#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ch [80];
    //char ch2 [80];
    int i = 0;
    int j;
    int firstP;
    int lastP;
    unsigned int lgr;

    //Saisie d'une chaine

    printf("Saisissez une phrase (limite 80 caracteres) :\n");

    fgets(ch, 80, stdin);
    lgr = strlen(ch); // ! ATTENTION ! lgr prend en compte le caractère '\O'

    printf("Vous avez tape :\n\n%s\n\n", ch);

    //Premier et dernier caractère non blanc

    // 1er caractère non blanc

    while ( ch [i] == ' ')
    {
    	i++;
    }
    firstP = i;
    printf("1er caractere non blanc : %c a la position %d\n\n", ch [i], i);

    // Dernier caractere non blanc

    j = lgr - 2;
    while ( ch [j] == ' ')
    {
    	j--;
    }
    lastP = j;
    printf("dernier caractere non blanc : %c a la position %d\n\n", ch [j], j);





}
