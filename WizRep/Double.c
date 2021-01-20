#define _CRT_SECURE_NO_WARNINGS

#include"Header.h"
#include<stdio.h>
#include<stdlib.h>


int WriteDouble(Position p)
{
	int i = 0, number;
	printf("Unesite koliko cvorova zelite ispisati: ");
	scanf("%d", &number);

	while (i != number)
	{
		Position q = malloc(sizeof(struct double_node));
		q->number = i;

		p->next = q;
		q->prev = p;
		q->next = NULL;

		i++;
		p = p->next;
	}
}

int VisualPrintDouble(Position p)
{
	int flag = 0;
	Position save = p;
	Position next_row = NULL;

	TopBorderDouble(p, &next_row, &flag);
	SpaceAndSaveDouble(p, save);
	FirstBlockDouble(p, next_row);
	SpaceAndSaveDouble(p, save);
	SecondBlockDouble(p, next_row);
	SpaceAndSaveDouble(p, save);
	ThirdBlockDouble(p, next_row);
	SpaceAndSaveDouble(p, save);
	FourthBlockDouble(p, next_row);
	SpaceAndSaveDouble(p, save);
	FifthBlockDouble(p, next_row);
	SpaceAndSaveDouble(p, save);
	SixthBlockDouble(p, next_row);
	SpaceAndSaveDouble(p, save);
	BottomBorderDouble(p, next_row);

	if (flag == 1)
		VisualPrintDouble(next_row);
}

int TopBorderDouble(Position p, Position* next_row, int* flag)
{
	int overflow = 0, i;

	while (p != NULL)
	{
		if (overflow == 9)
		{
			*flag = 1;
			*next_row = p;
			break;
		}

		for (i = 0; i < length; i++)
			printf("%c", t);
		printf("           ");
		p = p->next;

		overflow++;
	}
}

int FirstBlockDouble(Position p, Position next_row)
{
	while (p != next_row)
	{
		printf("%c ", t);
		printf("%p ", p);
		printf("%c", t);

		if (p->next != NULL)
			printf("<==     ==>");
		p = p->next;
	}
}

int SecondBlockDouble(Position p, Position next_row)
{
	int i;
	while (p != next_row)
	{
		printf("%c", t);
		for (i = 0; i < length - 2; i++)
			printf("-");
		printf("%c", t);
		if (p->next != NULL)
			printf("   \\   /   ");
		p = p->next;
	}
}

int ThirdBlockDouble(Position p, Position next_row)
{
	int temp, helper, i, counter = 1;

	while (p != next_row)
	{
		if (p->prev == NULL)
		{
			printf("%c   Head   %c    \\ /    ", t, t);
			p = p->next;
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
			printf("%c", t);
			if (p->next != NULL)
				printf("    \\ /    ");

			p = p->next;
		}
		counter = 1;
	}
}

int FourthBlockDouble(Position p, Position next_row)
{
	int i;

	while (p != next_row)
	{
		printf("%c", t);
		for (i = 0; i < length - 2; i++)
			printf("-");
		printf("%c", t);
		if (p->next != NULL)
			printf("     X     ");

		p = p->next;
	}
}

int FifthBlockDouble(Position p, Position next_row)
{
	while (p != next_row)
	{
		printf("%c ", t);
		if (p->prev != NULL)
			printf("%p ", p->prev);
		else
			printf("  NULL   ");
		printf("%c", t);
		if (p->next != NULL)
			printf("    / \\___ ");
		p = p->next;
	}
}

int SixthBlockDouble(Position p, Position next_row)
{
	int i;

	while (p != next_row)
	{
		printf("%c ", t);
		if (p->next != NULL)
			printf("%p ", p->next);
		else
			printf("  NULL   ");
		printf("%c", t);
		if (p->next != NULL)
			printf(" __/       ");
		p = p->next;
	}
}

int BottomBorderDouble(Position p, Position next_row)
{
	int i;

	while (p != next_row)
	{
		for (i = 0; i < length; i++)
			printf("%c", t);
		printf("           ");
		p = p->next;
	}
	printf("\n\n");
}

int SpaceAndSaveDouble(Position p, Position save)
{
	printf("\n");
	p = save;
}



int FreeDouble(Position p)
{
	p = p->next;
	Position temp = p;

	while (temp != NULL)
	{
		temp = temp->next;
		free(p);
		p = temp;
	}

	free(temp);
}