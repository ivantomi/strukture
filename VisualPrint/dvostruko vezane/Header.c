#define _CRT_SECURE_NO_WARNINGS
#define length 12
char t = -2;

#include"Header.h"
#include<stdio.h>
#include<stdlib.h>


int Write(position p)
{
	int number;
	for (int i = 1; i < 30; i++)
	{
		number = i;

		while (p->next != NULL)
			p = p->next;

		position q = malloc(sizeof(struct node));
		q->number = number;

		p->next = q;
		q->prev = p;
		q->next = NULL;

	}
}

int Print(position p)
{
	while (p != NULL)
	{
		printf("%d ", p->number);
		p = p->next;
	}
}

int VisualPrintDouble(position p)
{
	int flag = 0;
	position save = p;
	position next_row = NULL;

	TopBorderDouble(p, &next_row, &flag);
	SpaceAndSave(p, save);

	FirstBlockDouble(p, next_row);
	SpaceAndSave(p, save);

	SecondBlockDouble(p, next_row);
	SpaceAndSave(p, save);

	ThirdBlockDouble(p, next_row);
	SpaceAndSave(p, save);

	FourthBlockDouble(p, next_row);
	SpaceAndSave(p, save);

	FifthBlockDouble(p, next_row);
	SpaceAndSave(p, save);

	SixthBlockDouble(p, next_row);
	SpaceAndSave(p, save);

	BottomBorderDouble(p, next_row);

	if (flag == 1)
		VisualPrintDouble(next_row);
}

int TopBorderDouble(position p, position *next_row, int *flag)
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

int FirstBlockDouble(position p, position next_row)
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

int SecondBlockDouble(position p, position next_row)
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

int ThirdBlockDouble(position p, position next_row)
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

int FourthBlockDouble(position p, position next_row)
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

int FifthBlockDouble(position p, position next_row)
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

int SixthBlockDouble(position p, position next_row)
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

int BottomBorderDouble(position p, position next_row)
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


position SpaceAndSave(position p, position save)
{
	printf("\n");
	p = save;

	return p;
}

