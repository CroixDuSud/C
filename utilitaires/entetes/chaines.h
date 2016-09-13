/* ========================================================================== */
/* Projet : chaines                                                           */
/* -------------------------------------------------------------------------- */
/* chaines.h : Entete des utilitaires de traitement de chaines                */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */

/* ========================================================================== */
/* Recherche de la position du premier(pc) et du dernier(dc) caractere non    */
/* blanc d'une chaine.                                                        */
/*                                                                            */
/* Valeur retournee : 0    ==> normal                                         */
/*                    1    ==> chaine vide                                    */
/*                    2    ==> chaine entierement a blanc                     */
/* ========================================================================== */

int  pcdc(char* ligne, int* pc, int *dc);

/* ========================================================================== */
/* Longueur d'une chaine (du premier au dernier caractere non blanc)          */
/* ========================================================================== */

int  lchaine(char* chaine);


/* ========================================================================== */
/* Cadrage à gauche d'une chaine                                              */
/* ========================================================================== */

void cadreg(char* chaine);


/* ========================================================================== */
/* Inversion d'une chaine                                                     */
/* ========================================================================== */

void inverse(char* chaine);

/* ========================================================================== */
/* Placer une sous-chaine dans une chaine, a une certaine position, avec      */
/* cadrage a gauche ou a droite de la position                                */
/* -------------------------------------------------------------------------- */
/* Parametres :                                                               */
/* chaine  : chaine a remplir                                                 */
/* sChaine : sous chaine a placer dans chaine                                 */
/* pos     : position de la sous-chaine dans la chaine (0 : debut)            */
/* sens    : 'g' ==> la sous-chaine est placee a gauche de pos                */
/*           'd' ==> la sous-chaine est placee a droite de pos                */
/* ========================================================================== */

void placeSousChaine(char* chaine, char* sChaine, int pos, char sens);


/* ========================================================================== */
/* Remplir une chaine avec un caractere, entre deux positions                 */
/* -------------------------------------------------------------------------- */
/* Parametres :                                                               */
/* chaine  : chaine a remplir                                                 */
/* caract  : caractere a placer dans chaine                                   */
/* pos1    : position du premier caractere insere                             */
/* pos2    : position du dernier caractere insere                             */
/* ========================================================================== */

void remplirChaine(char* chaine, char caract, int pos1, int pos2);


/* ========================================================================== */
/* Isoler une sous-chaine dans une chaine (les sous-chaines sont separees par */
/* des ;                                                                      */
/* -------------------------------------------------------------------------- */
/* Parametre d'entree   : chaine   ==> chaine a parcourir                     */
/* Parametre de sortie  : mot      ==> mot (sous-chaine) isole                */
/* Valeur retournee     : 0        ==> ; trouve                               */
/*                      : 1        ==> 0 trouve                               */
/* ========================================================================== */

int  isole(char *chaine, char *mot);

/* ========================================================================== */
/* Mettre tous les caracteres d'une chaine a CHAR_MAX                         */
/* Cette fonction sert a la gestion des fins de fichiers                      */
/* ========================================================================== */

void chaine_max(char* chaine, int lchaine);


/* ========================================================================== */
/* Entete des utilitaires de conversion                                       */
/* ========================================================================== */

/* ========================================================================== */
/* Conversion d'un entier en chaine de caracteres                             */
/* -------------------------------------------------------------------------- */
/* Parametres d'entree  : n  (Exemple : 1258)                                 */
/*                        separ : separateur des milliers                     */
/*                                peut prendre les valeurs : ',' '.' ' ', 0   */
/* Parametre de sortie : chaine  (Exemple : 1.258)                            */
/* ========================================================================== */

char* intChaine(int n, char separ, char* chaine);

/* ========================================================================== */
/* Conversion d'un reel en chaine de caracteres                               */
/* -------------------------------------------------------------------------- */
/* Parametres d'entree  : r                                                   */
/*                      : ndec     ==> nombre de decimales a afficher         */
/*                      : zero (1) ==> afficher les zeros non significatifs   */
/*                      : separ : separateur des milliers                     */
/* Parametre de sortie  : chaine                                              */
/* ========================================================================== */

char* doubleChaine(double r, char ndec, char zero, char separ, char* chaine);

/* ========================================================================== */
/* Conversion d'une chaine de caracteres en reel                              */
/* -------------------------------------------------------------------------- */
/* Parametre d'entree   : chaine   ==> chaine a convertir                     */
/* Parametre de sortie  : r        ==> nombre reel                            */
/* Valeur retournee     : 0        ==> normal                                 */
/*                      : 1        ==> erreur                                 */
/* ========================================================================== */

int  chaineDouble(char* chaine, double* r);
