#ifndef FONCCHAINES_5_H_INCLUDED

#define FONCCHAINES_5_H_INCLUDED

typedef struct
{
	int numero;
	char nom [51];
	char prenom[41];
	int numeroAgence;
}EMPLOYE;

void input(EMPLOYE *emp);

#endif // FONCCHAINES_5_H_INCLUDED
