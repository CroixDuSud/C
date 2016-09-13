/* ========================================================================== */
/* Projet : initMatieres  --  Initialisation du fichier des matieres          */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "R:\c\evaluation\entetes\matiere.h"


/* ========================================================================== */
/* PROGRAMME PRINCIPAL                                                        */
/* ========================================================================== */

int main()
{
   MATIERE matiere;
   FILE* fichierMatieres;
   char nomfich[201];
   char ligne[81];

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier des matieres                                          */
/* -------------------------------------------------------------------------- */

   strcpy(nomfich, "R:\\c\\evaluation\\fichiers\\matieres");

   fichierMatieres = fopen(nomfich, "wb");

   if (fichierMatieres == NULL)
   {
      printf("***** ERREUR OUVERTURE FICHIER matieres *****");
   }
   else
   {

/* -------------------------------------------------------------------------- */
/* Saisie du premier numero de matiere :                                      */
/* -------------------------------------------------------------------------- */

      printf("\n\nNumero de matiere : ");
      gets(ligne);
      matiere.numMatiere = atoi(ligne);

/* -------------------------------------------------------------------------- */
/* Saisie des autres proprietes d'une matiere :                               */
/* -------------------------------------------------------------------------- */

      while (ligne[0] != 0)
      {
         printf("Nom : ");
         gets(matiere.nomMatiere);

         fwrite(&matiere, sizeof(MATIERE), 1, fichierMatieres);

         printf("\n\nNumero de matiere : ");
         gets(ligne);
         matiere.numMatiere = atoi(ligne);
      }

      fclose(fichierMatieres);
   }

   return 0;
}
