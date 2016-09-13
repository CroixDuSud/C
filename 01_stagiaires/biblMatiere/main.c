/* ========================================================================== */
/* Projet : biblMatiere                                                       */
/* -------------------------------------------------------------------------- */
/* main.c : Lecture du fichier des matieres                                   */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "R:\C\evaluation\entetes\matiere.h"


/* ========================================================================== */
/* PROGRAMME PRINCIPAL                                                        */
/* ========================================================================== */

int main()
{
   MATIERE matiere;
   FILE* fichierMatieres;
   char nomfich[201];

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier des matieres                                          */
/* -------------------------------------------------------------------------- */

   strcpy(nomfich, "R:\\C\\evaluation\\fichiers\\matieres");

   fichierMatieres = fopen(nomfich, "rb");

   if (fichierMatieres == NULL)
   {
      printf("***** ERREUR OUVERTURE FICHIER matieres *****");
   }
   else
   {

      fread(&matiere, sizeof(MATIERE), 1, fichierMatieres);

/* -------------------------------------------------------------------------- */
/* Affichage des autres proprietes d'une matiere :                               */
/* -------------------------------------------------------------------------- */

      while (!feof(fichierMatieres))
      {
         printf("%d   %s\n", matiere.numMatiere, matiere.nomMatiere);
         fread(&matiere, sizeof(MATIERE), 1, fichierMatieres);
      }

      fclose(fichierMatieres);
   }

   return 0;
}
