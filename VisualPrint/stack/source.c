#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"Header.h"


int Push(Position);
int Pop(Position);
int BrisiRed(Position);
int RandomNumber();
int Ispis(Position);
int Transform(char[]);

int main()
{
	struct node HeadStog, HeadRed;
	HeadStog.next = NULL;
	HeadRed.next = NULL;

	srand((unsigned)time NULL);
	char odabir[256];
	int c;

	do {
		printf("Unesite 'push', 'pop', 'kraj': ");
		scanf(" %s", odabir);
		c = Transform(odabir);
		if (c == 1)
		{
			Push(&HeadStog);
			Push(&HeadRed);
		}
		else if (c == 2)
		{
			Pop(&HeadStog);
			BrisiRed(&HeadRed);
		}
		else if (c == 0)
			break;

		else printf("Probajte opet.\n");

		if (c == 1)
		{
			//VisualPrintStack(HeadStog.next);
			SlowPrint(HeadStog.next);
			//VisualPrintStack(HeadRed.next);
		}

	} while (1);



}

int Transform(char odabir[])
{
	if (strcmp(odabir, "push") == 0)
		return 1;
	else if (strcmp(odabir, "pop") == 0)
		return 2;
	else if (strcmp(odabir, "kraj") == 0)
		return 0;
	else return -1;
}

int RandomNumber()
{
	return rand() % 90 + 10;
}

int Ispis(Position p)
{
	while (p != NULL)
	{
		printf("%d", p->element);
		p = p->next;
	}
	puts("\n");
	return 0;
}

int Push(Position p)
{
	Position q = malloc(sizeof(struct node));

	if (q == NULL)
	{
		printf("Greska pri alociranu memorije!\n");
		return 1;
	}

	q->element = RandomNumber();

	q->next = p->next;
	p->next = q;

	return 0;
}

int Pop(Position p)
{
	if (p->next == NULL)
	{
		printf("Stog je prazan!\n");
		return -1;
	}
	Position temp = p->next;
	p->next = temp->next;
	free(temp);

	return 0;
}

int BrisiRed(Position p)
{
	if (p->next == NULL)
	{
		printf("Red je prazan!\n");
		return -1;
	}
	Position prev = p;
	while (p->next != NULL)
	{
		prev = p;
		p = p->next;
	}
	prev->next = p->next;
	free(p);

	return 0;
}
