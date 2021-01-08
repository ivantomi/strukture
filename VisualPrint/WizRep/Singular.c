#define _CRT_SECURE_NO_WARNINGS
#include"Header.h"
#include<stdio.h>
#include<stdlib.h>


int WriteSingular(position p)
{
	int i = 0, number;
	printf("Unesite koliko cvorova zelite ispisati: ");
	scanf("%d", &number);

	while (i != number)
	{
		position q = malloc(sizeof(struct node));
		q->number = i;
		p->next = q;
		q->next = NULL;

		i++;
		p = p->next;
	}
}

int VisualPrintSingular(position p)
{
	int i = 0;
	position save = p;
	int temp;
	int counter = 1, helper = 0;
	int overflow = 0;
	int flag = 0;
	position next_row = NULL;
	int prevent_double_head = 0;

	//top border
	while (p != NULL)
	{
		if (overflow == 11)
		{
			flag = 1;
			next_row = p;
			break;
		}

		for (i = 0; i < length; i++)
			printf("%c", t);
		printf("      ");
		p = p->next;

		overflow++;
	}
	printf("\n");

	p = save;

	//1st block
	while (p != next_row)
	{
		printf("%c ", t);
		printf("%p ", p);
		printf("%c   -> ", t);

		if (p->next == NULL)
			printf(" NULL ");
		p = p->next;
	}
	printf("\n");

	p = save;

	//2nd block
	while (p != next_row)
	{
		printf("%c", t);
		for (i = 0; i < length - 2; i++)
			printf("-");
		printf("%c", t);
		printf("   |  ");
		p = p->next;
	}

	p = save;
	printf("\n");

	//3rd block
	while (p != next_row)
	{
		if (p->number == NULL && prevent_double_head == 0)
		{
			printf("%c   Head   %c   |  ", t, t);
			p = p->next;
			prevent_double_head = 1;
		}
		else
		{
			temp = p->number;
			while (temp >= 10)
			{
				temp = temp / 10;
				counter++;
			}
			if (counter % 2 == 0)
				helper = 0;
			else helper = 1;

			printf("%c", t);
			for (i = 0; i < (length - 1) / 2 - counter / 2 - helper; i++)
				printf(" ");
			printf("%d", p->number);

			for (i = 0; i < (length - 1) / 2 - counter / 2; i++)
				printf(" ");
			printf("%c   |  ", t);

			p = p->next;
		}

		counter = 1;
	}
	printf("\n");

	p = save;

	//4th block
	while (p != next_row)
	{
		printf("%c", t);
		for (i = 0; i < length - 2; i++)
			printf("-");
		printf("%c", t);
		printf("   |  ");
		p = p->next;
	}
	printf("\n");

	p = save;


	//5th block
	while (p != next_row)
	{
		printf("%c ", t);
		if (p->next == NULL)
			printf("  NULL   ");
		else
			printf("%p ", p->next);
		p = p->next;
		printf("%c __/  ", t);
	}
	printf("\n");

	p = save;

	//bottom border
	while (p != next_row)
	{
		for (i = 0; i < length; i++)
			printf("%c", t);
		printf("      ");
		p = p->next;
	}

	printf("\n\n");

	if (flag == 1)
		VisualPrintSingular(next_row);


	return 0;
}

int SingularInfo()
{
	printf("\n\nJednostruko vezane liste su niz struktura koje fizicki mogu biti smjestene na razlicitim mjestima u memoriji.\n");
	printf("Svaki element sadrzi pokazivac na sljedeci clan, a koriste se da bi se izbjeglo uzastopno pomicanje clanova kod brisanja i dodavanja novog elementa.\n");
	printf("Ispis liste i pronalazenje elementa zahtijevaju N koraka. Pronalazenje k-tog elementa zahtijeva k operacija i traje duze nego kod niza (1 operacija).\n");
	printf("Umetanje elementa zahtijeva samo jednu operaciju alokacije memorije i dva postavljanja pokazivaca (pod uvjetom da je poznat prethodni element).\n");
	printf("Brisanje elementa zahtijeva jednu promjenu pokazivaca i oslobadjanje memorije.\n\n");

	printf("Kod programske realizacije dodaje se 'dummy' element koji pokazuje na pocetak liste (head).\n");
	system("pause");
}

int FreeSingular(position p)
{
	p = p->next;
	position temp = p;

	while (temp != NULL)
	{
		temp = temp->next;
		free(p);
		p = temp;
	}

	free(temp);
}