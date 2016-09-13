/* ========================================================================== */
/* projet : affichage de chaines de caracteres (printf, puts)                                              */
/* fichier : chaiPutsPrintf.c                                                     */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>

int main()
{
    char* adresse;

    adresse = "Vieux bouc...";

    /* -------------------------------------------------------------------------- */
    /* Les deux fonctions suivantes produisent le même résultat.                  */
    /* -------------------------------------------------------------------------- */
    /* Elles prennent comme parametre une adresse (char*).                        */
    /* Elles affichent le caractere correspondant a l'octet qui se trouve a cette */
    /* adresse, puis tous les octets qui suivent jusqu'a l'octet qui contient la  */
    /* valeur 0.                                                                  */
    /* -------------------------------------------------------------------------- */
    puts(adresse);
    printf("%s\n", adresse);

    /* -------------------------------------------------------------------------- */
    /* Experience "amusante" de modification de l'adresse :                       */
    /* -------------------------------------------------------------------------- */
    printf("\n\n");
    puts(adresse);

    do
    {
        adresse++;
        puts(adresse);
    }
    while(*adresse != 0);

    return 0;
}
