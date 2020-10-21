#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>

typedef struct osoba* Poz;

struct osoba {
	char ime[10];
	char prz[10];
	int god;
	Poz next;
};

void UnosP(Poz);
void Ispis(Poz);
void UnosK(Poz);
void Trazi(Poz);
void TraziPret(Poz);
void Brisi(Poz);

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
	return 0;

}

void UnosP(Poz p)
{
	Poz q;
	q = malloc(sizeof(struct osoba));
	

	printf("Unos na pocetak:\nUnesi ime, prezime i godinu rodjenja osobe: ");
	scanf("%s %s %d", q->ime, q->prz, &q->god);

	q->next = p->next;
	p->next = q;
	
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

void UnosK(Poz p)
{
	while (p->next != NULL)
	{
		p = p->next;
	}
	Poz q;
	q = malloc(sizeof(struct osoba));
	q->next = NULL;

	printf("Unos na kraj:\nUnesi ime, prezime i godinu rodjenja: ");
	scanf("%s %s %d", q->ime, q->prz, &q->god);

	q->next = NULL;
	p->next = q;
}

void Trazi(Poz p)
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
}

void TraziPret(Poz p)
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
}

void Brisi(Poz p)
{
	Poz pret;
	pret = malloc(sizeof(struct osoba));
	char prz[10];
	printf("Unesite prezime koje zelite izbrisati: ");
	scanf(" %s", prz);
	while ((p != NULL) && (strcmp(p->prz, prz) != 0))
	{
		pret = p;
		p = p->next;
	}
	if (pret != NULL)
	{
		p = pret->next;
		pret->next = p->next;
		free(p);
	}
}