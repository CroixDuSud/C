/* ========================================================================== */
/* Projet : gadMajStock                                                       */
/* -------------------------------------------------------------------------- */
/* Mise à jour du fichier nouveau stock a partir des fichiers ancienStock et  */
/* mouvements                                                                 */
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

/* -------------------------------------------------------------------------- */
/* Structure MOUVEMENT                                                        */
/* -------------------------------------------------------------------------- */

typedef struct
{
   char numeroProduit[3];
   int  quantite;
   char code;
} MOUVEMENT;


int main()
{
   PRODUIT produitAS, produitNS;
   MOUVEMENT mouvement;

   FILE* fichierAS;
   FILE* fichierMouvements;
   FILE* fichierNS;

   char nomfich[81];

/* -------------------------------------------------------------------------- */
/* Ouverture des fichiers                                                     */
/* -------------------------------------------------------------------------- */
   strcpy(nomfich,
      "u:\\bip\\formateur\\gnmi\\c\\cours_algo\\fichiers\\ancienStock");

   fichierAS = fopen(nomfich, "rb");

   if (fichierAS == NULL)
   {
      printf(" *** ERREUR OUVERTURE FICHIER ancienStock ***\n");
      exit(0);
   }


   strcpy(nomfich,
      "u:\\bip\\formateur\\gnmi\\c\\cours_algo\\fichiers\\mouvements");

   fichierMouvements = fopen(nomfich, "rb");

   if (fichierMouvements == NULL)
   {
      printf(" *** ERREUR OUVERTURE FICHIER mouvements ***\n");
      exit(0);
   }

   strcpy(nomfich,
      "u:\\bip\\formateur\\gnmi\\c\\cours_algo\\fichiers\\nouveauStock");

   fichierNS = fopen(nomfich, "wb");

   if (fichierNS == NULL)
   {
      printf(" *** ERREUR OUVERTURE FICHIER nouveauStock ***\n");
      exit(0);
   }

/* -------------------------------------------------------------------------- */
/* DEBUT PROGRAMME                                                            */
/* -------------------------------------------------------------------------- */
   fread(&produitAS, sizeof(PRODUIT), 1, fichierAS);
   fread(&mouvement, sizeof(MOUVEMENT), 1, fichierMouvements);

   do
   {

/* -------------------------------------------------------------------------- */
/* DEBUT PRODUIT                                                              */
/* -------------------------------------------------------------------------- */
      strcpy(produitNS.numero, produitAS.numero);
      strcpy(produitNS.libelle, produitAS.libelle);
      produitNS.quantite = produitAS.quantite;

      if ((strcmp(produitAS.numero, mouvement.numeroProduit) == 0) &&
          (!feof(fichierMouvements)))
      {

/* -------------------------------------------------------------------------- */
/* DEBUT GROUPE MOUVEMENTS                                                    */
/* -------------------------------------------------------------------------- */
         do
         {

/* -------------------------------------------------------------------------- */
/* DEBUT MOUVEMENT                                                            */
/* -------------------------------------------------------------------------- */
            if (mouvement.code == 'E')
            {
               produitNS.quantite += mouvement.quantite;
            }
            else
            {
               produitNS.quantite -= mouvement.quantite;
            }


/* -------------------------------------------------------------------------- */
/* FIN MOUVEMENT                                                              */
/* -------------------------------------------------------------------------- */
            fread(&mouvement, sizeof(MOUVEMENT), 1, fichierMouvements);
         }
         while ((strcmp(produitAS.numero, mouvement.numeroProduit) == 0) &&
                (!feof(fichierMouvements)));

/* -------------------------------------------------------------------------- */
/* FIN GROUPE MOUVEMENTS                                                      */
/* -------------------------------------------------------------------------- */
      }

/* -------------------------------------------------------------------------- */
/* FIN PRODUIT                                                                */
/* -------------------------------------------------------------------------- */
      printf("%3s   %-20s   %4d\n", produitNS.numero,
                                    produitNS.libelle,
                                    produitNS.quantite);

      fwrite(&produitNS, sizeof(PRODUIT), 1, fichierNS);
      fread(&produitAS, sizeof(PRODUIT), 1, fichierAS);
   }
   while (!feof(fichierAS));

/* -------------------------------------------------------------------------- */
/* FIN PROGRAMME                                                              */
/* -------------------------------------------------------------------------- */
   fclose(fichierAS);
   fclose(fichierMouvements);
   fclose(fichierNS);

   return 0;
}
