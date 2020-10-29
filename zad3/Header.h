#pragma once
struct osoba;
typedef struct osoba* Poz;

struct osoba {
	char ime[10];
	char prz[10];
	int god;
	Poz next;
};

int UnosP(Poz);
void Ispis(Poz);
int UnosK(Poz);
int Trazi(Poz);
int TraziPret(Poz);
int Brisi(Poz);
int UnosIzaElementa(Poz);
int UnosIspredElementa(Poz);
int IspisListeUDatoteku();
int UnosSortiraneListe();
int UnosListeIzDatoteke();
