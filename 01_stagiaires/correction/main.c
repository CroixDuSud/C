/* ========================================================================== */
/* Projet : correction  --  correction de l'evaluation stagiaire              */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "R:\C\evaluation\entetes\stagiaire.h"
#include "R:\C\evaluation\entetes\matiere.h"
#include "R:\C\evaluation\entetes\note.h"


/* ========================================================================== */
/* PROGRAMME PRINCIPAL                                                        */
/* ========================================================================== */

int main()
{

/* -------------------------------------------------------------------------- */
/* VARIABLES                                                                  */
/* -------------------------------------------------------------------------- */
/* Variables pour l'utilisation des fichiers                                  */
/* -------------------------------------------------------------------------- */
   char nomfich[201];

   FILE* fichierStagiaires;
   FILE* fichierMatieres;
   FILE* fichierNotes;
   FILE* edition;

   STAGIAIRE stagiaire;
   MATIERE matiere;
   NOTE note;

   int cr_numMatiere;          /* Critere de référence matiere                */

   int totalNotes;
   int nombreNotes;
   float moyenne;


/* -------------------------------------------------------------------------- */
/* DEBUT DU PROGRAMME : OUVERTURE DES FICHIERS                                */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier des stagiaires, en lecture                            */
/* -------------------------------------------------------------------------- */
   strcpy(nomfich,
      "U:\\Bip\\Formateur\\gnmi\\c\\evaluations\\fichiers\\stagiaires");

   fichierStagiaires = fopen(nomfich, "rb");

   if (fichierStagiaires == NULL)
   {
      printf("*** ERREUR OUVERTURE FICHIER stagiaires ***\n");
      exit(0);
   }

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier des matieres, en lecture                              */
/* -------------------------------------------------------------------------- */
   strcpy(nomfich, "R:\\C\\evaluation\\fichiers\\matieres");

   fichierMatieres = fopen(nomfich, "rb");

   if (fichierMatieres == NULL)
   {
      printf("*** ERREUR OUVERTURE FICHIER matieres ***\n");
      exit(0);
   }

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier des notes, en lecture                                 */
/* -------------------------------------------------------------------------- */
   strcpy(nomfich,
      "U:\\Bip\\Formateur\\gnmi\\c\\evaluations\\fichiers\\notes");

   fichierNotes = fopen(nomfich, "rb");

   if (fichierNotes == NULL)
   {
      printf("*** ERREUR OUVERTURE FICHIER notes ***\n");
      exit(0);
   }

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier d'edition (edition)                                   */
/* -------------------------------------------------------------------------- */
   strcpy(nomfich,
      "U:\\Bip\\Formateur\\gnmi\\c\\evaluations\\fichiers\\evalStag.txt");

   edition = fopen(nomfich, "wt");

   if (edition == NULL)
   {
      printf("*** ERREUR OUVERTURE FICHIER fichiersEfmStag.doc ***\n");
      exit(0);
   }

/* -------------------------------------------------------------------------- */
/* Lectures initiales                                                         */
/* -------------------------------------------------------------------------- */
   fread(&stagiaire, sizeof(STAGIAIRE), 1, fichierStagiaires);
   fread(&note, sizeof(NOTE), 1, fichierNotes);

/* -------------------------------------------------------------------------- */
/* Boucle sur les stagiaires                                                  */
/* -------------------------------------------------------------------------- */
   do
   {
      fprintf(edition, "\n%2d %s %s\n\n", stagiaire.numero,
                                          stagiaire.prenom,
                                          stagiaire.nom);

/* -------------------------------------------------------------------------- */
/* Le stagiaire a-t'il des notes ?                                            */
/* -------------------------------------------------------------------------- */
      if((note.numStagiaire == stagiaire.numero) &&
         (!feof(fichierNotes)))
      {

/* -------------------------------------------------------------------------- */
/* Oui : boucle sur les matieres                                              */
/* -------------------------------------------------------------------------- */
         do
         {
            cr_numMatiere = note.numMatiere;
            totalNotes = 0;
            nombreNotes = 0;

/* -------------------------------------------------------------------------- */
/* Boucle sur les notes d'une meme matiere                                    */
/* -------------------------------------------------------------------------- */
            do
            {
               totalNotes += note.note;
               nombreNotes++;
               fread(&note, sizeof(NOTE), 1, fichierNotes);
            }
            while((note.numMatiere == cr_numMatiere) &&
                  (note.numStagiaire == stagiaire.numero) &&
                  (!feof(fichierNotes)));

/* -------------------------------------------------------------------------- */
/* Calcul et affichage de la moyenne avec lecture du nom de la matiere        */
/* -------------------------------------------------------------------------- */
            moyenne = (float)totalNotes / (float)nombreNotes;
            matiere.numMatiere = cr_numMatiere;
            litMatiere(&matiere, fichierMatieres);
            fprintf(edition, "   %-30s :  %5.1f\n", matiere.nomMatiere,
                                                    moyenne);
         }
         while((note.numStagiaire == stagiaire.numero) &&
               (!feof(fichierNotes)));

         fprintf(edition, "\n");
      }
      else

/* -------------------------------------------------------------------------- */
/* Cas du stagiaire qui n'a aucune note (pour aucune matiere)                 */
/* -------------------------------------------------------------------------- */
      {
         fprintf(edition, "   Ce(tte) stagiaire n'a pas de note.\n\n");
      }
      fread(&stagiaire, sizeof(STAGIAIRE), 1, fichierStagiaires);
   }
   while(!feof(fichierStagiaires));

   fclose(fichierStagiaires);
   fclose(fichierMatieres);
   fclose(fichierNotes);
   fclose(edition);

   return 0;
}
