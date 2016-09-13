/* ========================================================================== */
/* projet : Utilisation de la structure répétitive WHILE                      */
/* fichier : initWhile1.c                                                     */
/*----------------------------------------------------------------------------*/
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>

int main()
{
    int len;
    char ch;

    len = 0;
    puts("Tapez une phrase, puis validez (Entree)");

    ch = _getch();

    while (ch != '\r')
    {
        _putch(ch);
        len++;
        //printf("nombre de caracteres %d\n", len);
        ch = _getch();
    }

    printf("\nVous avez tape une phrase de %d caracteres\n", len);

    return 0;
}
