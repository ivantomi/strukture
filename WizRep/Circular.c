#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"Header.h"

int WriteCircular(position p)
{
	int i = 0, number;
	static int remember_first = 0;
	printf("Unesite koliko cvorova zelite ispisati: ");
	scanf("%d", &number);
	position first = NULL;

	while (i != number)
	{
		position new = malloc(sizeof(struct node));
		new->number = i;

		if (p->next == NULL && remember_first == 0)
		{
			p->next = new;
			new->next = new;
			first = new;
			remember_first++;
		}
		else
		{
			new->next = first;
			p->next = new;
		}

		p = p->next;
		i++;
	}
	remember_first = 0;
}

int VisualPrintCircular(position p)
{
	static int space = 0;
	int first_number = 0;
	static position first = NULL;
	int overflow = 0, flag = 0;
	position next_row = NULL;

	HeadCircular(space);

	if (space == 0)
	{
		p = p->next;
		first = p;
	}

	TopBorderCircular(p, &next_row, &flag, &overflow, first, space);
	FirstBlockCircular(p, next_row, first);
	SecondBlockCircular(p, next_row, first);
	ThirdBlockCircular(p, next_row, first);
	FourthBlockCircular(p, next_row, first);
	FifthBlockCircular(p, next_row, first);
	BottomBorderCircular(p, next_row, first, flag);
	CreateSpaceCircular(flag, overflow, &space);

	if (flag == 1)
		VisualPrintCircular(next_row);
	else
	{
		CreateLineCircular(overflow, &space);
		return 0;
	}
}

int HeadCircular(int space)
{
	if (space == 0)
	{
		printf("   ");
		for (int i = 0; i < 10; i++)
			printf("%c", t);
		printf("\n<--%c  Head  %c\n", t, t);
		printf("|  ");
		for (int i = 0; i < 10; i++)
			printf("%c", t);
		printf("\n|\n|\n");
	}
}

int TopBorderCircular(position p, position* next_row, int* flag, int *overflow, position first, int space)
{
	int  i;
	printf("| ");

	do {
		if (*overflow == 10)
		{
			*flag = 1;
			*next_row = p;
			break;
		}

		for (i = 0; i < length; i++)
			printf("%c", t);
		printf("      ");

		p = p->next;

		++*overflow;
	} while (p != first);
	printf("\n");

	if (space == 0)
		printf("->");
	else
		printf("| ");
}

int FirstBlockCircular (position p, position next_row, position first)
{
	do
	{
		printf("%c ", t);
		printf("%p ", p);

		p = p->next;
		printf("%c ", t);
		if (p != first)
			printf("  -> ");


	} while (p != next_row && p != first);
	printf("\n");
	printf("| ");
}

int SecondBlockCircular(position p, position next_row, position first)
{
	do
	{
		p = p->next;
		printf("%c", t);
		for (int i = 0; i < length - 2; i++)
			printf("-");
		printf("%c", t);
		if (p != first)
			printf("   |  ");

	} while (p != next_row && p != first);
	printf("\n");
	printf("| ");
}

int ThirdBlockCircular(position p, position next_row, position first)
{
	int temp, i, counter = 1, helper;
	do
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

		p = p->next;

		printf("%c", t);
		if (p != first)
			printf("   |  ");

		counter = 1;
	} while (p != next_row && p != first);
	printf("\n");
	printf("| ");
}

int FourthBlockCircular(position p, position next_row, position first)
{
	do
	{
		p = p->next;
		printf("%c", t);
		for (int i = 0; i < length - 2; i++)
			printf("-");
		printf("%c", t);
		if (p != first)
			printf("   |  ");

	} while (p != next_row && p != first);
	printf("\n");
	printf("| ");
}

int FifthBlockCircular(position p, position next_row, position first)
{
	do
	{
		printf("%c ", t);
		if (p->next == NULL)
			printf("  NULL   ");
		else
			printf("%p ", p->next);

		p = p->next;
		if (p == first)
			printf("%c ----->", t);
		else
			printf("%c __/  ", t);
	} while (p != next_row && p != first);
	printf("\n");
	printf("| ");
}

int BottomBorderCircular(position p, position next_row, position first, int flag)
{
	do {
		for (int i = 0; i < length; i++)
			printf("%c", t);
		printf("      ");

		p = p->next;
	} while (p != next_row && p != first);

	if (flag == 0)
		printf("|");
}

int CreateSpaceCircular(int flag, int overflow, int *space)
{
	printf("\n|");

	if (flag == 0)
	{
		for (int j = 0; j < overflow; j++)
		{
			for (int i = 0; i < length; i++)
				printf(" ");
			printf("     ");
			printf(" ");
		}
		printf(" |");
	}
	printf("\n");
	++*space;
}

int CreateLineCircular(int overflow, int *space)
{
	printf("\\");
	for (int j = 0; j < overflow; j++)
	{
		for (int i = 0; i < length; i++)
			printf("_");
		printf("_____");
		printf("_");
	}
	printf("_|");

	*space = 0;
}

int FreeCircular(position head)
{
	position p = head->next;
	position first = p;
	p = p->next;

	position temp = p;

	while (temp->next != first)
	{
		temp = temp->next;
		free(p);
		p = temp;
	}

	p = p->next;
	free(temp);
	free(p);
	head->next = NULL;
}
