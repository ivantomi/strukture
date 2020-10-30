#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"header.h"


int main()
{
	Poz prva_lista = UnosListeIzDatoteke();
	Poz druga_lista = UnosListeIzDatoteke();

	printf("Prva lista: ");
	Ispis(prva_lista);
	printf("\nDruga lista: ");
	Ispis(druga_lista);
	printf("\n");

	Presjek(prva_lista, druga_lista);
	printf("\n");
	Unija(prva_lista, druga_lista);

	return 0;
}




