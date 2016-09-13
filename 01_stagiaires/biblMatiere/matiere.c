/* ========================================================================== */
/* Projet : biblMatiere                                                       */
/* -------------------------------------------------------------------------- */
/* matiere.c : fonction de lecture du fichier des matieres                    */
/* -------------------------------------------------------------------------- */
/* litMatiere : lecture d'un enregistrement du fichier matiere connaissant    */
/*              la clef (numero de la matiere : n_mat                         */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */

#include <string.h>
#include <stdio.h>
#include "matiere.h"


int litMatiere(MATIERE *pMatiere, FILE *fichierMatieres)
{
   MATIERE matiere;
   int trouve;
   int i;

/* -------------------------------------------------------------------------- */
/* Boucle de recherche séquentielle                                           */
/* -------------------------------------------------------------------------- */
   trouve = 0;

   i = 0;
   fseek(fichierMatieres, i * sizeof(MATIERE), SEEK_SET);
   fread(&matiere, sizeof(MATIERE), 1, fichierMatieres);

   while (!feof(fichierMatieres) && trouve == 0)
   {
      if(matiere.numMatiere == pMatiere->numMatiere)
      {
         trouve = 1;
         *pMatiere = matiere;
      }

      i++;
      fseek(fichierMatieres, i * sizeof(MATIERE), SEEK_SET);
      fread(&matiere, sizeof(MATIERE), 1, fichierMatieres);
   }

   return trouve;
}
