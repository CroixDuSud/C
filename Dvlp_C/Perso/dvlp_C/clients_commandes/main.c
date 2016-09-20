#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "R:\C\utilitaires\entetes\chaines.h"
#include "R:\C\utilitaires\entetes\temps.h"
#include "R:\C\utilitaires\entetes\client.h"
/*
typedef struct // Structure CLIENT
{
	char noCli [5];
	char nom [51];
	char adresse [51];
	char cPost [6];
	char ville [51];
	char noRep [4];
	char codPays [3];
	char codSit;
	float solde;
} CLIENT;
*/
typedef struct
{
	char noComm [7];
	char noCli [5];
	char noProd [5];
	int quantite;
	char desig [21];
	float prix;
	char date [11];
} COMMANDE;

int litClient (CLIENT *c, FILE *fichier); // Lire client

int ecritClient (CLIENT *c, FILE *fichier); // Ecrire client

/* ================================================================================================
												 MAIN
================================================================================================ */

int main(int argc, char const *argv[])
{
	//==========================================  REGLE  ==========================================
    printf("0         1         2         3         4         5         6         7         8         9    "); //==
    printf("01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234\n\n"); //==
    //==========================================  REGLE  ==========================================


    CLIENT client;
    COMMANDE commande;
    COMMANDE depannage;
    FILE *fichierComm;
    FILE *fichierCommd;
    FILE *fichierClient;
    FILE *edition;

    char datcli [9];

    _strdate (datcli);

    char pathComm [81] = "R:\\C\\fichiers\\comm";
    char pathCommd [81] = "R:\\C\\fichiers\\commd";
    char pathClient [81] = "R:\\C\\fichiers\\client";
    char pathEdit [81] = "C:\\Users\\afpa1800\\Desktop\\factureCommandes.txt";

    char comm [7], commd [7], cli [5], prod [5], datcom [11];
    float fmontant;
    char char_prix [11], char_montant [11], char_quantite [11]; char_montant [11];

    char LE1 [93], LE2 [93], LE3 [93], LE4 [93], LE5 [93], LD1 [93], LE6 [93], LT1 [93], LT2 [93], LT3 [93], LT4 [93] = "";

    char cadreEtoiles [93], etoiles [93];

    float z01, z02, z03, z04;
    char cz01 [11], cz02 [11], cz03 [11], cz04 [11];

    float z00; // montant partiel

    /* -- GESTION PAGES----
    int IncrementPage;
    char page [4];
    ---------------------*/

	//============================= OUVERTURE DU FICHIER COMM ===========================

    fichierComm = fopen (pathComm, "rb");

    if (fichierComm == NULL)
    {
    	printf("***ERREUR OUVERTURE FICHIER COMM***\n");
    	exit(0);
    }

    //============================= OUVERTURE DU FICHIER COMMD ===========================

    fichierCommd = fopen (pathCommd, "rb");

    if (fichierCommd == NULL)
    {
    	printf("***ERREUR OUVERTURE FICHIER COMMD***\n");
    	exit(1);
    }

    //============================= OUVERTURE DU FICHIER CLIENT ===========================

    fichierClient = fopen (pathClient, "rb");

    if (fichierClient == NULL)
    {
    	printf("***ERREUR OUVERTURE FICHIER CLIENT***\n");
    	exit(2);
    }

    //============================== OUVERTURE DU FICHIER EDITION =================================

    edition = fopen (pathEdit, "wt");

    if (edition == NULL)
    {
    	printf("***ERREUR OUVERTURE FICHIER EDITION***\n");
    	exit(3);
    }

    /* ----------------------------------------------------------------------------------------------
    -------------------------------------- DEBUT PROGRAMME ------------------------------------------
    -----------------------------------------------------------------------------------------------*/






	/*====================================================
	==================   PROGRAMME   =====================
	====================================================*/

	fread (&commande, sizeof (COMMANDE), 1, fichierComm);
	fread (&depannage, sizeof (COMMANDE), 1, fichierCommd);
	fread (&client, sizeof (CLIENT), 1, fichierClient);


	while (!feof (fichierComm))
	{
		/* =====================================================
		====================   CLIENT   ========================
		======================================================*/

		strcpy (cli, commande.noCli);

		z00 = 0;

		//---------------------------------- >>> etoiles <<< CHAINES COLONNES D'ETOILES

		remplirChaine (etoiles, ' ', 0, 92);
		placeSousChaine (etoiles, "*", 1, 'd');
		placeSousChaine (etoiles, "*", 12, 'd');
		placeSousChaine (etoiles, "*", 23, 'd');
		placeSousChaine (etoiles, "*", 33, 'd');
		placeSousChaine (etoiles, "*", 56, 'd');
		placeSousChaine (etoiles, "*", 64, 'd');
		placeSousChaine (etoiles, "*", 76, 'd');
		placeSousChaine (etoiles, "*", 92, 'd');

		//---------------------------------- >>> cadreEtoiles <<< Affichage CADRE D'ETOILES

		remplirChaine(cadreEtoiles, ' ', 0, 92);
		remplirChaine(cadreEtoiles, '*', 1, 92);
    	printf("%s\n", cadreEtoiles);
    	//fprintf(edition, "%s\n", cadreEtoiles);

    	//---------------------------------- >>> LE1 <<< Affichage NO CLIENT et NO PAGE

    	remplirChaine (LE1, ' ', 0, 92);
    	placeSousChaine (LE1, "*  CLIENT NO : ", 1,'d');
    	placeSousChaine (LE1, cli, 16, 'd');
    	placeSousChaine (LE1, "PAGE : ", 25, 'd');
    	//placeSousChaine (LE1, page, 32, 'd');

    	printf("%s\n", LE1);

    	//fprintf(edition, "%s\n", LE1);

    	printf("\n\n\n\n\n");
    	//fprintf(edition, "\n\n\n\n\n");

    	//-------------------------------------- >>> LE2 <<< Affichage NOM CLIENT

    	remplirChaine (LE2, ' ',0 , 92);
    	placeSousChaine (LE2, client.nom, 9, 'd');
    	printf("%s\n", LE2);
    	//fprintf(edition, "%s\n", LE2);

    	//----------------------------------------- >>> LE3 <<< Affichage ADRESSE CLIENT

    	remplirChaine (LE3, ' ',0 , 92);
    	placeSousChaine(LE3, client.adresse, 9, 'd');
    	printf("%s\n", LE3);
    	//fprintf(edition, "%s", LE3);

    	//------------------------------------------- >>> LE4 <<< Affichage CODE POSTAL + VILLE CLIENT

    	remplirChaine (LE4, ' ',0 , 92);
    	placeSousChaine (LE4, client.cPost, 9, 'd');
    	placeSousChaine (LE4, client.ville, 15, 'd');

    	printf("%s\n\n\n\n\n", LE4);
    	//fprintf(edition, "%s\n\n\n\n\n", LE4);

    	//------------------------------------------ >>> LE5 <<< Affichage NO FACTURE CLIENT + DATE

    	remplirChaine (LE5, ' ',0 , 92);
    	placeSousChaine (LE5, "FACTURE NO : ", 9, 'd');
    	placeSousChaine (LE5, "XXXXXX", 22, 'd');
    	placeSousChaine (LE5, "DU", 30, 'd');
    	placeSousChaine (LE5, datcli, 35, 'd');
    	printf("%s\n\n", LE5);
    	//fprintf(edition, "%s\n\n", LE5);

    	//------------------------------------------- >>>  <<< Affichage INTITULE DES COLONNES DU TABLEAU


		printf("%s\n", cadreEtoiles);
		//fprintf(edition, "%s\n", cadreEtoiles);
		printf(" * COMMANDE *   DATE   * PRODUIT *     DESIGNATION      * QUANT *  PRIX HT  *  MONTANT HT   *\n");
		//fprintf(edition, " * COMMANDE *    DATE   * PRODUIT *     DESIGNATION      * QUANT *  PRIX HT  *  MONTANT HT   *\n");
		printf("%s\n", cadreEtoiles);
		//fprintf(edition, "%s\n", cadreEtoiles);




		while (!feof (fichierComm) && strcmp (cli, commande.noCli) == 0)
		{
			/* =====================================================
			====================   COMMANDE   ======================
			======================================================*/

			strcpy (comm, commande.noComm);



			//strcpy (LD1, etoiles);
			remplirChaine (LD1, ' ', 0, 92);
			placeSousChaine (LD1, comm, 4, 'd');
			placeSousChaine (LD1, commande.date, 13, 'd');

			//printf("%s", LD1);





			while (!feof (fichierComm) && strcmp (cli, commande.noCli) == 0  && strcmp (comm, commande.noComm) == 0) // && strcmp (cli, client.noCli) == 0
			{
				/* =====================================================
				====================   PRODUIT   =======================
				======================================================*/



				doubleChaine(commande.prix, 2, 1, 0, char_prix);
				doubleChaine(commande.quantite, 0, 1, 0, char_quantite);
				fmontant = commande.prix * commande.quantite;
				doubleChaine(fmontant, 2, 1, 0, char_montant);


				placeSousChaine (LD1, commande.noProd, 26, 'd');
				placeSousChaine (LD1, commande.desig, 39, 'd');
				placeSousChaine (LD1, char_quantite, 61, 'g');
				placeSousChaine (LD1, char_prix, 73, 'g');
				placeSousChaine (LD1, char_montant, 87, 'g');

				printf("%s\n\n", LD1);
				remplirChaine (LD1, ' ', 0, 92);
				z00 += fmontant;



				fread (&commande, sizeof (COMMANDE), 1, fichierComm);

			}

			/*---------------------------------- FIN PRODUIT --------------------------------*/

		}

		/*---------------------------------- FIN COMMANDE --------------------------------*/

		if (strcmp (cli, depannage.noCli) == 0)
			{

				//------------------------------------------- >>> LE6 <<< Affichage "D E P A N N A G E"

					remplirChaine (LE6, ' ', 0, 92);
					placeSousChaine (LE6, "D E P A N N A G E\n", 36, 'd');
					printf("\n%s\n", LE6);

				while (!feof (fichierCommd) && strcmp (cli, depannage.noCli) == 0)
				{
					/* =====================================================
					====================   DEPANNAGE   =====================
					======================================================*/

					strcpy (commd, depannage.noComm);



					//strcpy (LD1, etoiles);
                    remplirChaine (LD1, ' ', 0, 92);
                    placeSousChaine (LD1, commd, 4, 'd');
                    placeSousChaine (LD1, depannage.date, 13, 'd');

                    //printf("%s", LD1);



					while (!feof (fichierCommd) && strcmp (cli, depannage.noCli) == 0 && strcmp (commd, depannage.noComm) == 0)
					{
						/* =====================================================
						====================   PRODUIT   =====================
						======================================================*/


						doubleChaine(depannage.prix, 2, 1, 0, char_prix);
						doubleChaine(depannage.quantite, 0, 1, 0, char_quantite);
						fmontant = depannage.prix * depannage.quantite;
						doubleChaine(fmontant, 2, 1, 0, char_montant);


						placeSousChaine (LD1, depannage.noProd, 26, 'd');
						placeSousChaine (LD1, depannage.desig, 39, 'd');
						placeSousChaine (LD1, char_quantite, 61, 'g');
						placeSousChaine (LD1, char_prix, 73, 'g');
						placeSousChaine (LD1, char_montant, 87, 'g');

						printf("%s\n\n", LD1);
						remplirChaine (LD1, ' ', 0, 92);
						z00 += fmontant;


						fread (&depannage, sizeof (COMMANDE), 1, fichierCommd);
					}

					/*---------------------------------- FIN PRODUIT --------------------------------*/

				}

				/*---------------------------------- FIN DEPANNAGE --------------------------------*/

			}

		//------------------------------------------- >>> LT1 <<< Affichage REMISE

		z01 = z00 * (2.00/100);
		doubleChaine (z01, 2, 1, 0, cz01);
		remplirChaine (LT1, ' ', 0, 92);
		placeSousChaine (LT1, cz01, 87,'g');
		placeSousChaine (LT1, "REMISE", 35, 'd');
		printf("\n\n\n");
		printf("%s\n", LT1);

		//------------------------------------------- >>> LT2 <<< Affichage MONTANT HORS TAXES

		z02 = z00 - z01;
		doubleChaine (z02, 2, 1, 0, cz02);
		remplirChaine (LT2, ' ', 0, 92);
		placeSousChaine (LT2, cz02, 87,'g');
		placeSousChaine (LT2, "MONTANT HORS TAXES", 35, 'd');
		printf("%s\n", LT2);

		//------------------------------------------- >>> LT3 <<< Affichage MONTANT TVA

		z03 = z02 * (19.60/100);
		doubleChaine (z03, 2, 1, 0, cz03);
		remplirChaine (LT3, ' ', 0, 92);
		placeSousChaine (LT3, cz03, 87,'g');
		placeSousChaine (LT3, "MONTANT TVA (19.6%)", 35, 'd');
		printf("%s\n\n\n", LT3);

		//------------------------------------------- >>> LT4 <<< Affichage NET A PAYER

		z04 = z03 + z02;
		doubleChaine (z04, 2, 1, 0, cz04);
		remplirChaine (LT4, ' ', 0, 92);
		placeSousChaine (LT4, cz04, 87,'g');
		placeSousChaine (LT4, "NET A PAYER", 35, 'd');
		printf("%s\n\n", LT4);

		printf("\f\n");

	}

		/*---------------------------------- FIN CLIENT --------------------------------*/








	fclose (fichierClient);
	fclose (fichierComm);
	fclose (fichierCommd);
	fclose (edition);

	return 0;

}





