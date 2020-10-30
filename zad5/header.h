#pragma once
struct node;

typedef struct node* Poz;

struct node {
	int element;
	Poz next;
};

void Ispis(Poz);
Poz UnosListeIzDatoteke();
int Presjek(Poz, Poz);
int Unija(Poz, Poz);
int NadjiElement(int, Poz);
