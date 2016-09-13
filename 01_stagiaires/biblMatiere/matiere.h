/* ========================================================================== */
/* Projet : biblMatiere                                                       */
/* -------------------------------------------------------------------------- */
/* matiere.h : structure MATIERE et fonction de lecture du fichier des        */
/*             matieres                                                       */
/* -------------------------------------------------------------------------- */
/* Structure MATIERE                                                          */
/*    numMatiere  : numero de matiere (identifiant)                           */
/*    nomMatiere  : nom de matiere                                            */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */

#include <stdio.h>

typedef struct
{
   int  numMatiere;
   char nomMatiere[31];
} MATIERE;

/* -------------------------------------------------------------------------- */
/* Lit la variable de type MATIERE pointee par pMatiere                       */
/* Remarque : la variable numMatiere doit etre prealablement renseignee       */
/* Code retour : 1 si la matiere est trouvee, 0 sinon                         */
/* -------------------------------------------------------------------------- */
int litMatiere(MATIERE *pMatiere, FILE *fichierMatieres);
