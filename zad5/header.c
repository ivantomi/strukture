#define _CRT_SECURE_NO_WARNINGS
#include"header.h"
#include<stdio.h>
#include<stdlib.h>


Poz UnosListeIzDatoteke() {
	struct node Head;
	Head.next = NULL;

	FILE* datoteka;
	char ime_datoteke[20];
	printf("Unesite ime datoteke iz koje zelite procitati listu: ");
	scanf(" %s", ime_datoteke);
	datoteka = fopen(ime_datoteke, "r");

	if (datoteka == NULL)
	{
		printf("Greska pri otvaranju datoteke!\n");
		return 1;
	}

	int broj_redaka = 0;
	while (!feof(datoteka))
	{
		if (fgetc(datoteka) == '\n')
			broj_redaka++;
	}
	if (broj_redaka == 0)
	{
		printf("U datoteci se ne nalazi nista.\n");
		return NULL;
	}
	rewind(datoteka);

	Poz p = &Head;

	for (int i = 0; i < broj_redaka; i++)
	{
		Poz q = malloc(sizeof(struct node));
		if (q == NULL)
		{
			printf("Greska u %d. iteraciji pri alokaciji memorije.\n", i + 1);
			return 1;
		}
		fscanf(datoteka, "%d", &q->element);
		q->next = p->next;
		p->next = q;

		p = p->next;
	}

	fclose(datoteka);
	return Head.next;
}

void Ispis(Poz p)
{
	while (p != NULL)
	{
		printf("%d ", p->element);
		p = p->next;
	}
}


int Presjek(Poz prva, Poz druga)
{
	printf("Presjek: ");
	while (prva != NULL)
	{
		if (NadjiElement(prva->element, druga) != 0)
			printf("%d ", prva->element);
		prva = prva->next;
	}
}

int Unija(Poz prva, Poz druga)
{
	printf("Unija: ");
	while (druga != NULL)
	{
		if (NadjiElement(druga->element, prva) == 0)
		{
			PronadjiMjesto(druga->element, prva);
		}

		druga = druga->next;
	}
	Ispis(prva);
}

int NadjiElement(int x, Poz druga)
{
	while (druga != NULL)
	{
		if (druga->element == x)
			return 1;
		druga = druga->next;
	}
	return 0;
}

int PronadjiMjesto(int x, Poz prva)
{
	while (prva->next != NULL && prva->next->element < x)
		prva = prva->next;
	Poz new = malloc(sizeof(struct node));
	new->next = prva->next;
	prva->next = new;
	new->element = x;
	return 0;
}
