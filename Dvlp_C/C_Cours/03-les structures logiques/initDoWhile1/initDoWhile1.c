/* ========================================================================== */
/* projet : Utilisation de la structure répétitive DO ... WHILE               */
/* fichier : initDoWhile1.c                                                   */
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

    do
    {
        _putch(ch);
        len++;
        ch = _getch();
    }
    while (ch != '\r');

    printf("\nVous avez tape une phrase de %d caracteres\n", len);

    return 0;
}
