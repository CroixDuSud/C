/* ========================================================================== */
/* Projet : fichierLecSeq                                                     */
/* -------------------------------------------------------------------------- */
/*          Lecture sequentielle du fichier binaire "formateurs"              */
/*          Ecriture dans un fichier texte "editFormateurs.doc"               */
/* -------------------------------------------------------------------------- */
/* Ce fichier contient une succession d'enregistrements de type FORMATEUR     */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
   int numero;
   char nom[51];
} FORMATEUR;


int main()
{
                        /* -------------------------------------------------- */
   FILE* fichier;       /* Pointeur vers le fichier                           */
                        /*                                                    */
   FILE* edition;       /* Pointeur vers le fichier texte d'edition           */
                        /*                                                    */
   FORMATEUR form;      /* Variable de type FORMATEUR destinée à la lecture   */
                        /* du fichier "formateurs"                            */
                        /*                                                    */
   int codeRetour;      /* Variable destinée à tester les codes retour des    */
                        /* fonctions liées au fichier. Ce code retour pourra  */
                        /* être commun à plusieurs fichiers                   */
                        /*                                                    */
   char nomFichier[81]; /* Tableau contenant le nom du fichier.               */
                        /* -------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/* Initialisation du nom du fichier a lire                                    */
/* -------------------------------------------------------------------------- */
   strcpy(nomFichier,
      "u:\\bip\\formateur\\gnmi\\c\\cours_c\\fichiers\\formateurs");

/* -------------------------------------------------------------------------- */
/* Ouverture en lecture (r) du fichier binaire (b)                            */
/* -------------------------------------------------------------------------- */
   fichier = fopen(nomFichier, "rb");
   if (fichier == 0)
   {
      printf(" *** Erreur d'ouverture du fichier %s ***", nomFichier);
      exit(0);
   }

/* -------------------------------------------------------------------------- */
/* Nom du fichier d'edition :                                                 */
/* -------------------------------------------------------------------------- */
   strcpy(nomFichier,
          "u:\\bip\\formateur\\gnmi\\c\\cours_c\\fichiers\\editFormateurs.doc");


/* -------------------------------------------------------------------------- */
/* Ouverture du fichier et controle d'erreur                                  */
/* -------------------------------------------------------------------------- */
   edition = fopen(nomFichier, "wt");
   if (edition == 0)
   {
      printf(" *** ERREUR OUVERTURE FICHIER EDITION ***");
      exit(1);
   }

/* -------------------------------------------------------------------------- */
/* Boucle de lecture et d'affichage du fichier                                */
/* -------------------------------------------------------------------------- */
   printf("LISTE DES FORMATEURS\n\n");
   fprintf(edition, "LISTE DES FORMATEURS\n\n");

   codeRetour = fread(&form, sizeof(FORMATEUR), 1, fichier);

   while (!feof(fichier))
   {
      printf("%3d  %s\n", form.numero, form.nom);
      fprintf(edition, "%3d  %s\n", form.numero, form.nom);
      codeRetour = fread(&form, sizeof(FORMATEUR), 1, fichier);
   }

   fclose(fichier);
   fclose(edition);

   return 0;
}
