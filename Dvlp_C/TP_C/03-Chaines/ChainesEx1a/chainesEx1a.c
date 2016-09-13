/* ========================================================================== */
/* projet : TP_Chaine       exercice 1 (version a)                            */
/* fichier : chaineEx1a.c                                                     */
/* -------------------------------------------------------------------------- */
/* Compter le nombre de 'e' contenus dans une chaine saisie au clavier        */
/* (maximum 80 caracteres)                                                    */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>

int main()
{
    char ligne[81];
    int i;
    int compteur;

    printf("Entrer une ligne (maximum 80 caracteres) :\n");
    gets(ligne);

    i = 0;
    compteur = 0;
    while (ligne[i] != 0)
   {
        if (ligne[i] == 'e') compteur++;
        i++;
    }

    printf("\n\nNombre de 'e' : %d\n", compteur);

    return 0;
}
/*
int main()
{
    char ligne[81];
    int compteur;
    char* pLigne;

    printf("Entrer une ligne (maximum 80 caracteres) :\n");
    pLigne = gets(ligne);   // pLigne pointe sur la chaine ligne

    compteur = 0;
    while (*pLigne != 0)    // on boucle tantque pLigne ne pointe pas sur la fin de chaine
   {
        if (*pLigne == 'e') compteur++;
       pLigne++;    // incrémentation de pLigne qui pointe sur le caractère suivant
    }

    printf("\n\nNombre de 'e' : %d\n", compteur);

    return 0;
}
*/
