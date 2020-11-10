#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node* Position;

typedef struct node {
	int koeficijent;
	int potencija;
	Position next;
};

Position UnosPolinomaIzDatoteke();
void Ispis(Position);
Position Zbroji(Position, Position);
Position Umnozak(Position, Position);

int main()
{
	Position prvi = UnosPolinomaIzDatoteke();
	Position drugi = UnosPolinomaIzDatoteke();

	Ispis(prvi);
	Ispis(drugi);

	Position zbroj = Zbroji(prvi, drugi);
	Position umnozak = Umnozak(prvi, drugi);

	printf("Zbroj polinoma: ");
	Ispis(zbroj);
	printf("Umnozak polinoma: ");
	Ispis(umnozak);
	//Pomnozi(prvi, drugi);
}

Position UnosPolinomaIzDatoteke()
{
	struct node Head;
	Head.next = NULL;

	int check;
	FILE* datoteka;
	char ime_datoteke[20];
	printf("Unesite ime datoteke: ");
	scanf(" %s", ime_datoteke);
	datoteka = fopen(ime_datoteke, "r");

	if (datoteka == NULL)
	{
		printf("Greska pri otvaranju datoteke!\n");
		return 1;
	}
	
	while (!(feof(datoteka)))
	{
		check = 0;
		Position p = &Head;
		
		Position q = malloc(sizeof(struct node));
		fscanf(datoteka, "%dx%d ", &q->koeficijent, &q->potencija);
		
		while (p->next != NULL && (p->next->potencija >= q->potencija))
		{
			if (p->next->potencija == q->potencija)
			{
				p->next->koeficijent = p->next->koeficijent + q->koeficijent;
				check = 1;
				free(q);
			}
			p = p->next;
		}
		if (check == 0)
		{
			q->next = p->next;
			p->next = q;
		}	
	}

	fclose(datoteka);
	return Head.next;
}

void Ispis(Position p)
{
	while (p != NULL)
	{
		printf(" %dx%d ", p->koeficijent, p->potencija);
		p = p->next;
	}
	printf("\n");
}

Position Zbroji(Position prvi, Position drugi)
{
	struct node zbroj;
	zbroj.next = NULL;

	Position p = &zbroj;
	
	int check = 0;

	while (prvi != NULL && drugi != NULL)
	{
		if (prvi->potencija > drugi->potencija)
		{
			Position new = malloc(sizeof(struct node));
			new->koeficijent = prvi->koeficijent;
			new->potencija = prvi->potencija;
			new->next = p->next;
			p->next = new;
			prvi = prvi->next;
			printf("check: %dx%d\n", new->koeficijent, new->potencija);
			
		}
		else if (prvi->potencija < drugi->potencija)
		{
			Position new = malloc(sizeof(struct node));
			new->koeficijent = drugi->koeficijent;
			new->potencija = drugi->potencija;
			new->next = p->next;
			p->next = new;
			drugi = drugi->next;
			printf("check: %dx%d\n", new->koeficijent, new->potencija);
			
		}
		else if (prvi->potencija == drugi->potencija)
		{
			Position new = malloc(sizeof(struct node));
			new->koeficijent = drugi->koeficijent + prvi->koeficijent;
			new->potencija = drugi->potencija;
			new->next = p->next;
			p->next = new;
			prvi = prvi->next;
			drugi = drugi->next;
			printf("check: %dx%d\n", new->koeficijent, new->potencija);
		}
	}
	if (prvi == NULL)
		while (drugi != NULL)
		{
			Position new = malloc(sizeof(struct node));
			new->koeficijent = drugi->koeficijent;
			new->potencija = drugi->potencija;
			new->next = p->next;
			p->next = new;
			drugi = drugi->next;
		}
	else if (drugi == NULL)
	{
		while (prvi != NULL)
		{
			Position new = malloc(sizeof(struct node));
			new->koeficijent = prvi->koeficijent;
			new->potencija = prvi->potencija;
			new->next = p->next;
			p->next = new;
			prvi = prvi->next;
		}
	}
	return zbroj.next;
}

Position Umnozak(Position prvi, Position drugi)
{
	struct node umnozak;
	umnozak.next = NULL;

	Position p = &umnozak;

	int check = 0;

	while (prvi != NULL && drugi != NULL)
	{
		if (prvi->potencija > drugi->potencija)
		{
			Position new = malloc(sizeof(struct node));
			new->koeficijent = prvi->koeficijent;
			new->potencija = prvi->potencija;
			new->next = p->next;
			p->next = new;
			prvi = prvi->next;
			printf("check: %dx%d\n", new->koeficijent, new->potencija);

		}
		else if (prvi->potencija < drugi->potencija)
		{
			Position new = malloc(sizeof(struct node));
			new->koeficijent = drugi->koeficijent;
			new->potencija = drugi->potencija;
			new->next = p->next;
			p->next = new;
			drugi = drugi->next;
			printf("check: %dx%d\n", new->koeficijent, new->potencija);

		}
		else if (prvi->potencija == drugi->potencija)
		{
			Position new = malloc(sizeof(struct node));
			new->koeficijent = drugi->koeficijent * prvi->koeficijent;
			new->potencija = drugi->potencija;
			new->next = p->next;
			p->next = new;
			prvi = prvi->next;
			drugi = drugi->next;
			printf("check: %dx%d\n", new->koeficijent, new->potencija);
		}
	}
	if (prvi == NULL)
		while (drugi != NULL)
		{
			Position new = malloc(sizeof(struct node));
			new->koeficijent = drugi->koeficijent;
			new->potencija = drugi->potencija;
			new->next = p->next;
			p->next = new;
			drugi = drugi->next;
		}
	else if (drugi == NULL)
		while (prvi != NULL)
		{
			Position new = malloc(sizeof(struct node));
			new->koeficijent = prvi->koeficijent;
			new->potencija = prvi->potencija;
			new->next = p->next;
			p->next = new;
			prvi = prvi->next;
		}
	return umnozak.next;
}
