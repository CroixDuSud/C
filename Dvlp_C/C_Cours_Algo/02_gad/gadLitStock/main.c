/* ========================================================================== */
/* Projet : gadLitStock                                                       */
/* -------------------------------------------------------------------------- */
/* Affichage d'un fichier stock (ancienStock ou nouveauStock)                 */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* -------------------------------------------------------------------------- */
/* Structure PRODUIT                                                          */
/* -------------------------------------------------------------------------- */

typedef struct
{
   char numero[3];
   char libelle[21];
   int  quantite;
} PRODUIT;


int main()
{
   FILE* fichierStock;
   PRODUIT produit;

   char nomfich[81];
   char ligne[81];

   printf("Afficher fichier ancienStock (o/n) ? ");
   gets(ligne);

   if ((ligne[0] == 'o') || (ligne[0] == 'O'))
   {
      strcpy(nomfich,
         "u:\\bip\\formateur\\gnmi\\c\\cours_algo\\fichiers\\ancienStock");
   }
   else
   {
      strcpy(nomfich,
         "u:\\bip\\formateur\\gnmi\\c\\cours_algo\\fichiers\\nouveauStock");
   }

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier                                                       */
/* -------------------------------------------------------------------------- */
   fichierStock = fopen(nomfich, "rb");

   if (fichierStock == NULL)
   {
      if ((ligne[0] == 'o') || (ligne[0] == 'O'))
      {
         printf(" *** ERREUR OUVERTURE FICHIER ancienStock ***\n");
      }
      else
      {
         printf(" *** ERREUR OUVERTURE FICHIER nouveauStock ***\n");
      }

      exit(0);
   }

/* -------------------------------------------------------------------------- */
/* Debut programme                                                            */
/* -------------------------------------------------------------------------- */
   if ((ligne[0] == 'o') || (ligne[0] == 'O'))
   {
      printf("\n\nFichier ancienStock\n\n");
   }
   else
   {
      printf("\n\nFichier nouveauStock\n\n");
   }

   fread(&produit, sizeof(PRODUIT), 1, fichierStock);

   do
   {
      printf("%3s   %-20s   %4d\n", produit.numero,
                                    produit.libelle,
                                    produit.quantite);

      fread(&produit, sizeof(PRODUIT), 1, fichierStock);
   }
   while (!feof(fichierStock));

/* -------------------------------------------------------------------------- */
/* Fermeture du fichier                                                       */
/* -------------------------------------------------------------------------- */
   fclose(fichierStock);

   return 0;
}
