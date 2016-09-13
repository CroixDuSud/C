/* ========================================================================== */
/* projet : Test de la bibliotheque des fonctions developpees dans TP Chaines */
/* fichier : testChainess.c                                                   */
/* -------------------------------------------------------------------------- */
/* programme de test de la bibliothèque chaines                          */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#include "chaines.h"


int main()
{
   char ligne[81];        /* Ligne de saisie                                  */

   int pc;                /* Indice du premier caractere non blanc            */
   int dc;                /* Indice du dernier caractere non blanc            */
   int retour;            /* Code retour de pcdc()                            */
   char chaine[81];       /* Chaine a modifier pour placeSousChaine()         */
   char sousChaine[81];   /* Sous chaine a inserer                            */
   int pos;               /* Position de l'insertion                          */

/* -------------------------------------------------------------------------- */
/* Saisie de ligne                                                            */
/* -------------------------------------------------------------------------- */
   printf("Entrer une ligne (maximum 80 caracteres) :\n");
   gets(ligne);

/* -------------------------------------------------------------------------- */
/* Affichage du nombre de 'e'                                                 */
/* -------------------------------------------------------------------------- */
   printf("\nNombre de 'e' : %d.\n", compteLettres(ligne, 'e'));
   _getch();

/* -------------------------------------------------------------------------- */
/* Enlevement des 'e'                                                         */
/* -------------------------------------------------------------------------- */
   enleveLettres(ligne, 'e');
   printf("\n\n");
   puts(ligne);
   _getch();

/* -------------------------------------------------------------------------- */
/* Inversion de la chaine restante                                            */
/* -------------------------------------------------------------------------- */
   inverse(ligne);
   printf("\n\n");
   puts(ligne);
   _getch();

/* -------------------------------------------------------------------------- */
/* Position du premier et du dernier caractere non blanc                      */
/* -------------------------------------------------------------------------- */
   retour = pcdc(ligne, &pc, &dc);

/* -------------------------------------------------------------------------- */
/* Chaine vide                                                                */
/* -------------------------------------------------------------------------- */
   if (retour == 1)
   {
      printf("La chaine saisie est vide !\n");
   }
   else
   {
      if (retour == 2)
      {
         printf("La chaine saisie est entierement a blanc !\n");
      }
      else
      {
         printf("\nPremier caractere : %d\n", pc);
         printf("Dernier caractere : %d\n", dc);
         printf("Longueur : %d\n", dc - pc + 1);
      }
   }

   _getch();

/* -------------------------------------------------------------------------- */
/* Initialisation de chaine (chaine a modifier dans placeSousChaine)          */
/* -------------------------------------------------------------------------- */
   strcpy(chaine, ligne);

/* -------------------------------------------------------------------------- */
/* Saisie de sousChaine (a inserer dans ligne)                                */
/* -------------------------------------------------------------------------- */
   printf("\nEntrer une sous chaine a inserer (max 80 caracteres) :\n");
   gets(sousChaine);

/* -------------------------------------------------------------------------- */
/* Saisie de pos                                                              */
/* -------------------------------------------------------------------------- */
   printf("\nEntrer la position d'insertion (entier) :\n");
   gets(ligne);
   pos = atoi(ligne);

/* -------------------------------------------------------------------------- */
/* Insertion de la sous chaine                                                */
/* -------------------------------------------------------------------------- */
   placeSousChaine(chaine, sousChaine, pos, 'd');

/* -------------------------------------------------------------------------- */
/* Affichage du resultat                                                      */
/* -------------------------------------------------------------------------- */
   printf("\n\nChaine finale :\n");
   puts(chaine);

   return 0;
}
