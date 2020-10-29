#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include"Header.h"

int main()
{
	struct osoba Head;
	Head.next = NULL;

	UnosP(&Head);
	Ispis(Head.next);
	UnosP(&Head);
	Ispis(Head.next);
	UnosK(&Head);
	Ispis(Head.next);
	Trazi(Head.next);
	TraziPret(Head.next);
	Brisi(&Head);
	Ispis(Head.next);
	UnosIspredElementa(&Head);
	Ispis(Head.next);
	UnosIzaElementa(Head.next);
	Ispis(Head.next);
	IspisListeUDatoteku(Head.next);
	printf("\n--------------------------\n");
	UnosListeIzDatoteke();
	printf("\n--------------------------\n");
	UnosSortiraneListe();

	return 0;
}
