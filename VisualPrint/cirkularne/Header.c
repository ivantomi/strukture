#include"Header.h"
#include<stdio.h>
#include<stdlib.h>
#define length 12

int Entry(int number, position p)
{
	position new = malloc(sizeof(struct node));
	new->number = number;
	position first = p->next;

	if (first == NULL)
	{
		p->next = new;
		new->next = new;
	}
	else
	{
		do
		{
			p = p->next;
		} while (p->next != first);
		
		new->next = p->next;
		p->next = new;
	}
}

int Print(position head)
{
	position first = head->next;
	if (head->next == NULL)
		printf("Prazna lista!\n");

	do {
		head = head->next;
		printf("%d ", head->number);
	} while (head->next != first);
}

int VisualPrintCircular(position p)
{
		char t = -2;
		static int space = 0;
		int first_number = 0;
		static position first = NULL;

		//head
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
			p = p->next;
			first = p;
		}

		int i, temp, helper, overflow = 0, flag = 0, counter = 1;
		position save = p;
		
		position next_row = NULL;

		printf("| ");

		//top border
		do {
			if (overflow == 10)
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
		} while (p != first);
		printf("\n");
		printf("| ");

		p = save;

		//1st block 
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

		p = save;

		//2nd block
		do
		{
			p = p->next;
			printf("%c", t);
			for (i = 0; i < length - 2; i++)
				printf("-");
			printf("%c", t);
			if (p != first)
				printf("   |  ");
			
		} while (p != next_row && p != first);
		printf("\n");
		printf("| ");

		p = save;

		//3rd block
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

		p = save;

		//4th block
		do
		{
			p = p->next;
			printf("%c", t);
			for (i = 0; i < length - 2; i++)
				printf("-");
			printf("%c", t);
			if (p != first)
				printf("   |  ");
			
		} while (p != next_row && p != first);
		printf("\n");
		if (space != 0)
			printf("| ");
		else printf("->");

		p = save;

		//5th block
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

		p = save;

		//bottom border
		do {
			for (i = 0; i < length; i++)
				printf("%c", t);
			printf("      ");
			p = p->next;
		} while (p != next_row && p != first);

		if (flag == 0)
			printf("|");

		printf("\n|");
		if (flag == 0)
		{
			for (int j = 0; j < overflow; j++)
			{
				for (i = 0; i < length; i++)
					printf(" ");
				printf("     ");
				printf(" ");
			}
			printf(" |");
		}
		printf("\n");
		space++;
		if (flag == 1)
			VisualPrintCircular(next_row);
		else
		{
			printf("\\");
			for (int j = 0; j < overflow; j++)
			{
				for (i = 0; i < length; i++)
					printf("_");
				printf("_____");
				printf("_");
			}
			printf("_|");

			return 0;
		}
}