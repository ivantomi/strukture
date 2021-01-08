#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"Header.h"

int main()
{
	// deklaracije struktura
	struct node head;
	head.next = NULL;
	head.number = NULL;

	struct double_node double_head;
	double_head.next = NULL;
	double_head.prev = NULL;
	double_head.number = NULL;

	struct node stack;
	stack.next = NULL;

	// deklaracije pomocnih varijabli
	int number, menu_choice;

	// izbornik
	printf("Dobrodosli u program WizRep! Za najbolje rezultate i optimalni prikaz preporuca se da konzolu otvorite preko cijelog ekrana.");
	while (1)
	{
		printf("\nOdaberite opciju za pocetak: \n");
		printf("\t1 - Jednostruko vezane liste\n\t2 - cirkularne liste\n\t3 - dvostruko vezane liste\n\t4 - Stack\n\t5 - Izlaz\n: ");
		scanf("%d", &menu_choice);
		switch (menu_choice)
		{
		case 1: 
		{
			Single();
			break;
		}
		case 2:
		{
			Circle();
			break;
		}
		case 3: 
		{
			Double();
			break;
		}
		case 4:
		{
			Stack();
			break;
		}
		}
		if (menu_choice == 5)
			break;
	}
	
	printf("Hvala na koristenju i sretno sa strukturama!\n");


}

