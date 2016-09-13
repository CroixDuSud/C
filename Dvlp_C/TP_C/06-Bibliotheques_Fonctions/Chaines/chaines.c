/* ========================================================================== */
/* projet : Bibliotheque des fonctions developpees dans le TP Chaines         */
/* fichier : chaines.c                                                        */
/* -------------------------------------------------------------------------- */
/* fichier contenant l'ensemble des fonctions de la bibliothèque              */
/*           int compteLettres(char*, char) : compter un caractere            */
/*           void enleveLettres(char*, char) : supprimer un caractere         */
/*           void inverse(char*) : inverser unechaine                         */
/*           void placeSousChaine(char*, char*, int, char) : placer sous-ch   */
/*           int pcdc(char* chaine, int* pc, int *dc) : premier/dernier       */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>
#include <string.h>

#include "chaines.h"

/* ========================================================================== */
/* Fonction compteLettres :                                                   */
/* -------------------------------------------------------------------------- */
/* Parametres : ligne  : chaine examinee                                      */
/*              lettre : lettre cherchee                                      */
/* ========================================================================== */

int compteLettres(char* ligne, char lettre)
{
   int i;               /* Indice de parcours de ligne                        */
   int compteur;        /* Nombre de 'lettre' deja trouves                    */

   i = 0;
   compteur = 0;
   while (ligne[i] != 0)
   {
      if (ligne[i] == lettre) compteur++;
      i++;
   }

   return compteur;
}


/* ========================================================================== */
/* Fonction enleveLettres :                                                   */
/* -------------------------------------------------------------------------- */
/* Parametres : ligne  : chaine a traiter                                     */
/*              lettre : lettre a enlever                                     */
/* ========================================================================== */

void enleveLettres(char* ligne, char lettre)
{
   int i;
   int j;

   i = 0;             /* Numero du caractere examine                          */
   j = 0;             /* Numero du poste ou on le recopie                     */

   while (ligne[i] != 0)
   {
      if (ligne[i] != 'e')
      {
         ligne[j] = ligne[i];
         j++;
      }
      i++;
   }
   ligne[j] = 0;
}


/* ========================================================================== */
/* Fonction inverse :                                                         */
/* -------------------------------------------------------------------------- */
/* Parametre : ligne  : chaine a inverser                                     */
/* ========================================================================== */

void inverse(char* ligne)
{
   int i1;            /* Poste de gauche a inverser                           */
   int i2;            /* Poste de droite a inverser                           */
   char permut;       /* Caractere de permutation                             */

   i1 = 0;
   i2 = strlen(ligne) - 1;

   while (i1 < i2)
   {
      permut = ligne[i1];
      ligne[i1] = ligne[i2];
      ligne[i2] = permut;
      i1++;
      i2--;
   }
}


/* ========================================================================== */
/* Recherche de la position du premier(pc) et du dernier(dc) caractere non    */
/* blanc d'une chaine.                                                        */
/*                                                                            */
/* Valeur retournee : 0    ==> normal                                         */
/*                    1    ==> chaine vide                                    */
/*                    2    ==> chaine entierement a blanc                     */
/* ========================================================================== */

int pcdc(char* chaine, int* pc, int *dc)
{
   int longChaine;
   int retour;

   retour = 0;
   longChaine = strlen(chaine);

   if (longChaine == 0)
   {
      retour = 1;
   }
   else
   {
      *pc = 0;

      while ((chaine[*pc] == ' ') && (*pc < longChaine))
      {
         (*pc)++;
      }

      if (*pc == longChaine)
      {
         retour = 2;
      }
      else
      {
         *dc = longChaine - 1;
         while (chaine[*dc] == ' ')
         {
            (*dc)--;
         }
      }
   }
   return retour;
}



/* ========================================================================== */
/* Placer une sous-chaine dans une chaine, a une certaine position, avec      */
/* cadrage a gauche ou a droite de la position                                */
/* -------------------------------------------------------------------------- */
/* Parametres :                                                               */
/* chaine  : chaine a remplir                                                 */
/* sChaine : sous chaine a placer dans chaine                                 */
/* pos     : position de la sous-chaine dans la chaine (0 : debut)            */
/* cadrage : 'g' ==> la sous-chaine est placee a gauche de pos                */
/*           'd' ==> la sous-chaine est placee a droite de pos                */
/* ========================================================================== */

void placeSousChaine(char* chaine, char* sChaine, int pos, char cadrage)
{
   int lChaine;
   int posFinSChaine;
   int i;

/* -------------------------------------------------------------------------- */
/* Position de la fin de la sous chaine                                       */
/* -------------------------------------------------------------------------- */
   if (cadrage == 'd')
   {
      posFinSChaine = pos + strlen(sChaine);
   }
   else
   {
      posFinSChaine = pos + 1;
   }

/* -------------------------------------------------------------------------- */
/* Si la position d'insertion est au dela de la fin de la chaine a remplir,   */
/* il faut completer par des blancs                                           */
/* -------------------------------------------------------------------------- */
   lChaine  = strlen(chaine);

   if (lChaine < posFinSChaine)
   {
      for (i = lChaine; i < posFinSChaine; i++)
      {
         chaine[i] = ' ';
      }
      chaine[i] = 0;
   }

/* -------------------------------------------------------------------------- */
/* Placement de la sous-chaine                                                */
/* -------------------------------------------------------------------------- */
   if (cadrage == 'd')
   {
      memcpy(chaine + pos, sChaine, strlen(sChaine));
   }
   else
   {
      memcpy(chaine + pos - strlen(sChaine) + 1, sChaine, strlen(sChaine));
   }
}
