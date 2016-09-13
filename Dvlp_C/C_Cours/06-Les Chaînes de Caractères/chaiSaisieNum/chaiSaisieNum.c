/* ========================================================================== */
/* projet : Utilisation des chaines pour les saisies numeriques               */
/* fichier : chaiSaisieNum.c                                                  */
/* -------------------------------------------------------------------------- */
/* Le couple :                                                                */
/*    gets(ligne); i = atoi(ligne);                                           */
/*                                                                            */
/* est preferable a :                                                         */
/*    scanf("%d", &i);                                                        */
/*                                                                            */
/* car il permet de verifier la saisie avant de faire la conversion en int.   */
/* De plus, en cas de mauvaise saisie, scanf a un comportement "bizarre"...   */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */


#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
   int i;
   double x;

   char ligne[81];

   printf("Saisir l'entier i : ");
   gets(ligne);
   i = atoi(ligne);

   printf("\n\nSaisir le double x : ");
   gets(ligne);
   x = atof(ligne);

   printf("\n\nValeurs saisies : ");
   printf("i = %d  x = %f\n", i, x);

   return 0;
}
