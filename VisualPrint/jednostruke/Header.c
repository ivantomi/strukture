#define _CRT_SECURE_NO_WARNINGS
#define length 12

#include"Header.h"
#include<stdio.h>
#include<stdlib.h>


int Write(position p)
{
	int number;
	for (int i = 0; i < 10; i = i++)
	{
		number = i;

		while (p->next != NULL)
			p = p->next;

		position q = malloc(sizeof(struct node));
		q->number = number;
		p->next = q;
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

int VisualPrintSingular(position p)
{
	char t = -2;
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
	{
		VisualPrintSingular(next_row);
	}
}