#pragma warning(disable : 4996)
#include"./Header.h"
#include<stdio.h>
#include<stdlib.h>

int UnosP(Poz p)
{
	Poz q = malloc(sizeof(struct osoba));
	if (q == NULL) {
		printf("Greska pri alociranju memorije!\n");
		return 1;
	}

	printf("Unos na pocetak:\nUnesi ime, prezime i godinu rodjenja osobe: ");
	scanf("%s %s %d", q->ime, q->prz, &q->god);

	q->next = p->next;
	p->next = q;

	return 0;
}

void Ispis(Poz p)
{
	while (p != NULL)
	{
		printf("%s %s %d (%d) ", p->ime, p->prz, p->god, p);
		p = p->next;
		printf("\n");
	}
	printf("\n");
}

int UnosK(Poz p)
{
	while (p->next != NULL)
	{
		p = p->next;
	}

	Poz q = malloc(sizeof(struct osoba));

	if (q == NULL)
	{
		printf("Greska pri alociranju memorije!\n");
		return 1;
	}
	
	printf("Unos na kraj:\nUnesi ime, prezime i godinu rodjenja: ");
	scanf("%s %s %d", q->ime, q->prz, &q->god);

	q->next = NULL;
	p->next = q;

	return 0;
}

int Trazi(Poz p)
{
	char prz[10];
	printf("Unesite prezime koje trazite: ");
	scanf(" %s", prz);

	while ((p != NULL) && (strcmp(p->prz, prz) != 0))
	{
		p = p->next;
	}

	if (p == NULL)
		printf("Nema tog lika.\n");
	else
		printf("Lik je na adresi %d.\n", p);

	return 0;
}

int TraziPret(Poz p)
{
	char prz[10];
	printf("Unesite prezime od kojeg zelite znati prethodnog: ");
	scanf(" %s", prz);
	while ((p->next != NULL) && (strcmp(p->next->prz, prz) != 0))
	{
		p = p->next;
	}
	if (p->next == NULL)
		printf("Taj lik ne postoji u listi.\n");
	else
		printf("Prethodnik unesenog je %s\n.", p->prz);

	return 0;
}

int Brisi(Poz p)
{
	Poz pret = malloc(sizeof(struct osoba));

	if (pret == NULL)
	{
		printf("Greska pri alociranju memorije!\n");
		return 1;
	}
	char prz[10];
	printf("Unesite prezime koje zelite izbrisati: ");
	scanf(" %s", prz);

	while ((p != NULL) && (strcmp(p->prz, prz) != 0))
	{
		pret = p;
		p = p->next;
	}
	if (p != NULL)
	{
		p = pret->next;
		pret->next = p->next;
		free(p);
	}
	else
		printf("Taj lik ne postoji u listi.\n");
	return 0;
}

int UnosIspredElementa(Poz p)
{
	char prezime[10];
	Poz pret = malloc(sizeof(struct osoba));
	if (pret == NULL)
	{
		printf("Greska pri alokaciji memorije!");
		return 1;
	}

	printf("Unesite prezime ispred kojeg zelite unijeti osobu: ");
	scanf(" %s", prezime);

	while ((p->next != NULL) && (strcmp(p->next->prz, prezime) != 0))
	{
		p = p->next;
	}

	if (p->next == NULL)
	{
		printf("Nema tog lika u listi.\n");
		return 1;
	}

	pret->next = p->next;
	p->next = pret;

	printf("Unesite podatke osobe: ");
	scanf(" %s %s %d", pret->ime, pret->prz, &pret->god);

	return 0;
}

int UnosIzaElementa(Poz p)
{
	char prezime[10];
	Poz sljedeci = malloc(sizeof(struct osoba));
	if (sljedeci == NULL)
	{
		printf("Greska pri alokaciji memorije!");
		return 1;
	}

	printf("Unesite prezime iza kojeg zelite unijeti osobu: ");
	scanf(" %s", prezime);

	while ((p != NULL) && (strcmp(p->prz, prezime) != 0))
	{
		p = p->next;
	}

	if (p == NULL)
	{
		printf("Tog lika nema u listi.\n");
		return 1;
	}

	sljedeci->next = p->next;
	p->next = sljedeci;

	printf("Unesite podatke osobe: ");
	scanf(" %s %s %d", sljedeci->ime, sljedeci->prz, &sljedeci->god);

	return 0;
}

int IspisListeUDatoteku(Poz p)
{
	FILE* datoteka;
	char ime_datoteke[20];
	printf("Unesite ime datoteke u koju zelite upisati listu: ");
	scanf(" %s", ime_datoteke);
	datoteka = fopen(ime_datoteke, "w");
	if (datoteka == NULL)
	{
		printf("greska pri stvaranju datoteke!\n");
		return 1;
	}

	while (p != NULL)
	{
		fprintf(datoteka, "%s %s %d\n", p->ime, p->prz, p->god);
		p = p->next;
	}

	fclose(datoteka);

	printf("Lista uspješno ispisana u datoteku %s!\n", ime_datoteke);

	return 0;
}

int UnosListeIzDatoteke() {
	struct osoba Head;
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
		return 1;
	}
	rewind(datoteka);

	Poz p = &Head;

	for (int i = 0; i < broj_redaka; i++)
	{
		Poz q = malloc(sizeof(struct osoba));
		if (q == NULL)
		{
			printf("Greska u %d. iteraciji pri alokaciji memorije.\n", i + 1);
			return 1;
		}
		fscanf(datoteka, "%s %s %d", q->ime, q->prz, &q->god);
		q->next = p->next;
		p->next = q;

		p = p->next;
	}

	printf("Lista iz datoteke %s:\n", ime_datoteke);
	fclose(datoteka);
	Ispis(Head.next);
}

int UnosSortiraneListe()
{
	struct osoba Head;
	Head.next = NULL;
	Poz p = &Head;
	int i = 0;
	char odabir[10];

	while (1)
	{
		do {
			printf("\n");
			printf("Upisite 'novi' za unos novog elementa ili 'kraj' za prekid unosa: ");
			scanf("%s", odabir);
		} while (strcmp(odabir, "novi") != 0 && strcmp(odabir, "kraj") != 0);

		if (strcmp(odabir, "kraj") == 0) break;

		Poz q = malloc(sizeof(struct osoba));

		if (q == NULL)
		{
			printf("Greska pri alokaciji memorije!\n");
			return 1;
		}

		printf("Unesite podatke za %d. osobu: ", ++i);
		scanf(" %s %s %d", q->ime, q->prz, &q->god);

		while (p->next != NULL && strcmp(q->prz, p->next->prz) >= 0)
		{
			p = p->next;
		}

		q->next = p->next;
		p->next = q;

	}
	Ispis(Head.next);
	return 0;
}
