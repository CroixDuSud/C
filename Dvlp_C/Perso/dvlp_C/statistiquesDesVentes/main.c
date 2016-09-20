#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "R:\C\utilitaires\entetes\chaines.h"
#include "R:\C\utilitaires\entetes\temps.h"


typedef struct
{
	char nosect [3];
	char norep [4];
	char nocli [5];
	char nofac [6];
	double mont;
	char codpays [3];

}Versement;



// ============================================== MAIN ============================================


int main()
{
    //==========================================  REGLE  ==========================================
    printf("0         1         2         3         4         5         6         7         "); //==
    printf("01234567890123456789012345678901234567890123456789012345678901234567890123456789\n\n"); //==
    //==========================================  REGLE  ==========================================

    Versement versement;
    FILE* fichierVersements;
    FILE* edition; // version .txt du résultat
    char pathVers [81] = "R:\\C\\fichiers\\versements";
    char pathEdit [81] = "C:\\Users\\afpa1800\\Desktop\\Statistique.txt";
    double z01, z02, z03, z04, z05, z06, z07, z08, z09, z10, z11 = 0;
    //char vide [81];
    //remplirChaine(vide, ' ', 0, 80);
    //char LE1 [81], LE2 [81], LE3 [81], LD1 [81], LT1 [81], LT2 [81], LT3 [81];
    char LE1 [81], LE2 [81], LE3 [81], LD1 [81], LT1 [81], LT2 [81], LT3 [81];
    char date [9];
    char secteur [3], representant [4], client [5], facture [6], codePays[3];
    int codeRetour;
    _strdate (date);



    //============================= OUVERTURE DU FICHIER DES VERSEMENTS ===========================

    fichierVersements = fopen (pathVers, "rb");

    if (fichierVersements == NULL)
    {
    	printf("***ERREUR OUVERTURE FICHIER VERSEMENTS***\n");
    	exit(0);
    }

    //=================================== LECTURE FICHIER VERSEMENT ===============================

    //printf("Liste des versements :\n\n");
    fread (&versement, sizeof (Versement), 1, fichierVersements);



    //============================== OUVERTURE DU FICHIER EDITION =================================

    edition = fopen (pathEdit, "wt");

    if (edition == NULL)
    {
    	printf("***ERREUR OUVERTURE FICHIER EDITION***\n");
    	exit(1);
    }


    // =============================== Debut SECTEUR

    while (!feof (fichierVersements))// && strcmp (versement.nosect, secteur) == 0) //&& strcmp (versement.norep, representant) == 0) //&& strcmp (versement.nocli, client) == 0)
    {
    	strcpy (secteur, versement.nosect);
        z06 = 0;
        z07 = 0;
        z08 = 0;

        placeSousChaine (LE1, date, 1, 'd');
        placeSousChaine (LE1, "STATISTIQUE MENSUELLE DES VENTES", 17, 'd');
        printf("\n\n%s\n\n", LE1);
        strcpy(LE1, "");

        placeSousChaine (LE2, "SECTEUR", 29, 'd');
        placeSousChaine (LE2, versement.nosect, 37, 'd');
        printf("%s\n\n", LE2);
        strcpy(LE2, "");

        placeSousChaine (LE3, "REPRESENTANT  CLIENT   MONTANT FRANCE   MONTANT EXPORT     PRIME", 1, 'd');
        printf("%s\n\n", LE3);
        strcpy(LE3, "");

        fprintf(edition, "\n\n%s\n\n", LE1);
        fprintf(edition, "%s\n\n", LE2);
        fprintf(edition, "%s\n\n", LE3);


    	// ================================ Debut SECTEUR ========================================

    	while (!feof (fichierVersements) && strcmp (versement.nosect, secteur) == 0)
    	{
    		strcpy (representant, versement.norep);
            z03 = 0;
            z04 = 0;
            z05 = 0;


            placeSousChaine (LD1, representant, 5, 'd');
            printf("%s\n", LD1);
            strcpy(LD1, "");

            fprintf(edition, "%s\n", LD1);


            //printf("     %s\n", representant);
            //fprintf(edition, "     %s\n", representant);

    		// ================================ Debut REPRESENTANT ===================================

    		while (!feof (fichierVersements) && strcmp (versement.nosect, secteur) == 0 && strcmp (versement.norep, representant) == 0) //strcmp (versement.nocli, "")
    		{
    			strcpy (client, versement.nocli);

                z01 = 0;
                z02 = 0;

    			// ================================ Debut CLIENT =================================

    			while (!feof (fichierVersements) && strcmp (versement.nosect, secteur) == 0 && strcmp (versement.norep, representant) == 0 && strcmp (versement.nocli, client) == 0)
    			{
    				strcpy (codePays, versement.codpays);
    				if (strcmp (versement.codpays, "") == 0) // ou codepays [0] == 0;
                    {
                        z01 += versement.mont;
                    }
                    else
                    {
                        z02 += versement.mont;
                    }
                    fread (&versement, sizeof (Versement), 1, fichierVersements);
    			}

    			// ============================= FIN BOUCLE CLIENT ================================


    			placeSousChaine(LD1, client, 16, 'd');
    			printf("%s", LD1);
    			strcpy(LD1, "");



    			//fprintf(edition, "%s",LD1;
    		}

    		// ============================= FIN BOUCLE REPRESENTANT ================================

    	}

    	// ============================= FIN BOUCLE SECTEUR ================================

    }

    /*
    placeSousChaine (LE1, date, 1, 'd');
    placeSousChaine (LE1, "STATISTIQUE MENSUELLE DES VENTES", 17, 'd');
    printf("%s\n\n", LE1);

    placeSousChaine (LE2, secteur, 29, 'd');
    */

    fclose (fichierVersements);
    fclose (edition);

    return 0;
}
