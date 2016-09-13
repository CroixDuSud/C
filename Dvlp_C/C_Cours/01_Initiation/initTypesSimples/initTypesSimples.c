/* ========================================================================== */
/* projet : Taille des types simples                                          */
/* fichier : initTypesSimples.c                                               */
/*----------------------------------------------------------------------------*/
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>

int main()
{
    printf("Taille d'un entier      : %d octet(s)\n", sizeof(int));
    printf("Taille d'un entier court: %d octet(s)\n", sizeof(short int));
    printf("Taille d'un entier long : %d octet(s)\n", sizeof(long int));
    printf("Taille d'un caractere   : %d octet(s)\n", sizeof(char));
    printf("Taille d'un reel        : %d octet(s)\n", sizeof(float));
    printf("Taille d'un reel double : %d octet(s)\n", sizeof(double));
    printf("\n\n");

    return 0;
}


