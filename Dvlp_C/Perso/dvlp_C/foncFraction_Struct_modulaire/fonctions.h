#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED


typedef struct
{
	int num;
	int den;
} Fraction;

int saisie(Fraction *);
Fraction somme(Fraction, Fraction);
int pgcd(int, int);
void affiche(Fraction);


#endif // FONCTIONS_H_INCLUDED
