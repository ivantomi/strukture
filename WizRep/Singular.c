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
	position save = p;
	position next_row = NULL;
	int flag = 0;
	int prevent_double_head = 0;

	TopBorderSingular(p, &next_row, &flag);
	SpaceAndSave(p, save);
	FirstBlockSingular(p, next_row);
	SpaceAndSave(p, save);
	SecondBlockSingular(p, next_row);
	SpaceAndSave(p, save);
	ThirdBlockSingular(p, next_row, &prevent_double_head);
	SpaceAndSave(p, save);
	FourthBlockSingular(p, next_row);
	SpaceAndSave(p, save);
	FifthBlockSingular(p, next_row);
	SpaceAndSave(p, save);
	BottomBorderSingular(p, next_row);

	if (flag == 1)
		VisualPrintSingular(next_row);

	return 0;
}

int TopBorderSingular(position p, position* next_row, int* flag)
{
	int overflow = 0, i;

	while (p != NULL)
	{
		if (overflow == 10) // koliko cvorova se prikaze u jednom retku
		{
			*flag = 1;		// oznacava da se mora prijeci u novi redak
			*next_row = p;	//spremanje trenutne vrijednosti za sljedeci redak
			break;
		}

		for (i = 0; i < length; i++)
			printf("%c", t);
		printf("      ");
		p = p->next;

		overflow++;
	}
}

int FirstBlockSingular(position p, position next_row)
{
	while (p != next_row)
	{
		printf("%c ", t);
		printf("%p ", p);
		printf("%c   -> ", t);

		if (p->next == NULL)
			printf(" NULL ");
		p = p->next;
	}
}

int SecondBlockSingular(position p, position next_row)
{
	while (p != next_row)
	{
		printf("%c", t);
		for (int i = 0; i < length - 2; i++)
			printf("-");
		printf("%c", t);
		printf("   |  ");
		p = p->next;
	}
}

int ThirdBlockSingular(position p, position next_row, int *prevent_double_head)
{
	int temp, helper, counter = 1, i;
	while (p != next_row)
	{
		if (p->number == NULL && *prevent_double_head == 0) // samo prvi cvor moze biti Head, sljedeci je vec prvi element s brojem 0
		{
			printf("%c   Head   %c   |  ", t, t);
			p = p->next;
			*prevent_double_head = 1;
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
			else helper = 1; // pomocna varijabla koja sluzi za centriranje neparnih brojeva

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
}

int FourthBlockSingular(position p, position next_row)
{
	while (p != next_row)
	{
		printf("%c", t);
		for (int i = 0; i < length - 2; i++)
			printf("-");
		printf("%c", t);
		printf("   |  ");
		p = p->next;
	}
}

int FifthBlockSingular(position p, position next_row)
{
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
}

int BottomBorderSingular(position p, position next_row)
{
	while (p != next_row)
	{
		for (int i = 0; i < length; i++)
			printf("%c", t);
		printf("      ");
		p = p->next;
	}

	printf("\n\n");
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

int SpaceAndSave(position p, position save)
{
	printf("\n");
	p = save;
}
