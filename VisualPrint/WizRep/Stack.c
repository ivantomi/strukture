#define _CRT_SECURE_NO_WARNINGS
#include"Header.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


int VisualPrintStack(position p)
{
	int first = 0;

	printf("\n\t      <---- push\n");

	while (p != NULL)
	{
		// address
		printf("\n|  %p  |", p);

		if (first == 1)
			printf("<--");
		printf("\n");

		// value
		printf("|     %d     |", p->number);

		if (first == 0)
		{
			printf("----> pop");
			first = 1;
		}

		// next
		printf("\n|  %p  |", p->next);
		if (p->next != NULL)
			printf("--");
		else
			printf("----> NULL");
		printf("\n");

		// separator
		for (int i = 0; i < 14; i++)
			printf("%c", t);
		if (p->next != NULL)
			printf("  |");

		p = p->next;
	}
	printf("\n");
	return 0;
}

int SlowPrint(position p)
{
	int i;

	FirstFunctionStack(p);
	SpaceAndPause();
	SecondFunctionStack(p);
	SpaceAndPause();
	ThirdFunctionStack(p);
	FourthFunctionStack(p);
}

int FirstFunctionStack(position p)
{
	int i;
	system("cls");
	printf("\n1. kreiramo prostor:\n");
	printf("|  %p  | -> adresa cvora\n", p);

	for (i = 0; i < 2; i++)
		printf("|            |\n");
	for (i = 0; i < 14; i++)
		printf("%c", t);
}

int SecondFunctionStack(position p)
{
	int i;

	printf("\r2. upisemo vrijednost:\n");
	printf("|  %p  |\n", p);
	for (i = 0; i < 1; i++)
		printf("|     %d     | -> vrijednost upisanog broja\n", p->number);
	printf("|            |\n");
	for (i = 0; i < 14; i++)
		printf("%c", t);
}

int ThirdFunctionStack(position p)
{
	int i;

	printf("3. povezemo pokazivace:\n");
	printf("|  %p  |\n", p);
	printf("|     %d     |\n", p->number);
	printf("|  %p  | -> pokazivac na sljedeci cvor\n", p->next);

	for (i = 0; i < 14; i++)
		printf("%c", t);
}

int FourthFunctionStack(position p)
{
	printf("\n\n");
	system("pause");

	system("cls");

	printf("4. ispisemo stack:");
	VisualPrintStack(p);
}

int SpaceAndPause()
{
	int i;

	printf("\n\n");
	system("pause");

	for (i = 0; i < 7; i++)
		printf("\033[A");
	printf("%c[2K", 27);
}



int RandomNumber()
{
	return rand() % 90 + 10;
}


int Push(position p)
{
	position q = malloc(sizeof(struct node));

	if (q == NULL)
	{
		printf("Greska pri alociranu memorije!\n");
		return 1;
	}

	q->number = RandomNumber();

	q->next = p->next;
	p->next = q;

	return 0;
}

int Pop(position p)
{
	if (p->next == NULL)
	{
		printf("Stog je prazan!\n");
		return -1;
	}
	position temp = p->next;
	p->next = temp->next;
	free(temp);

	return 0;
}

