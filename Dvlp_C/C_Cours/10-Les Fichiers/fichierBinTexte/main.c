/* ========================================================================== */
/* Projet : fichierBinTexte -- Ecriture dans un fichier binaire               */
/*                             Ecriture dans un fichier texte                 */
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
} STAGIAIRE;


int main()
{
                        /* -------------------------------------------------- */
   FILE* binaire;       /* Pointeur vers le fichier binaire                   */
                        /*                                                    */
   FILE* texte;         /* Pointeur vers le fichier texte                     */
                        /*                                                    */
   int i;               /* entier a ecrire sur les deux fichiers              */
                        /* -------------------------------------------------- */

   char nomFichier[81];

/* -------------------------------------------------------------------------- */
/* Nom du fichier binaire a ecrire                                            */
/* -------------------------------------------------------------------------- */
   strcpy(nomFichier,
      "u:\\bip\\formateur\\gnmi\\c\\cours_c\\fichiers\\binaire");

/* -------------------------------------------------------------------------- */
/* Ouverture en ecriture (w) du fichier binaire (b)                           */
/* -------------------------------------------------------------------------- */
   binaire = fopen(nomFichier, "wb");
   if (binaire == 0)
   {
      printf(" *** Erreur d'ouverture du fichier binaire ***");
      exit(0);
   }

/* -------------------------------------------------------------------------- */
/* Nom du fichier texte a ecrire                                              */
/* -------------------------------------------------------------------------- */
   strcpy(nomFichier,
          "u:\\bip\\formateur\\gnmi\\c\\cours_c\\fichiers\\texte");

/* -------------------------------------------------------------------------- */
/* Ouverture en ecriture (w) du fichier texte (t)                             */
/* -------------------------------------------------------------------------- */
   texte = fopen(nomFichier, "wt");
   if (texte == 0)
   {
      printf(" *** Erreur d'ouverture du fichier texte ***");
      exit(1);
   }

/* -------------------------------------------------------------------------- */
/* Ecritures de i                                                             */
/* -------------------------------------------------------------------------- */
   i = 17;


   fwrite(&i, sizeof(int), 1, binaire);
   fprintf(texte, "%d", i);

   fclose(binaire);
   fclose(texte);

   return 0;
}
