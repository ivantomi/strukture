#include"Header.h"
#include<stdlib.h>
char t = -2;
int length = 12;

int Single()
{
	struct node head;
	head.next = NULL;
	head.number = NULL;

	int menu_choice;
	
	while (1)
	{
		system("cls");
		printf("*** JEDNOSTRUKO VEZANE LISTE ***\n");
		printf("Jednostavne stvari u zivotu su najcesce i najbolje - jednostruko vezane liste su najjednostavniji oblik listi koje imamo.\n\n");
		printf("Odaberite opciju:\n\t1 - Vizualna reprezentacija\n\t2 - Vise informacija\n\t3 - povratak\n: ");
		scanf(" %d", &menu_choice);

		if (menu_choice == 3)
			break;

		switch (menu_choice)
		{
			case 1:
			{
				WriteSingular(&head);
				VisualPrintSingular(&head);
				FreeSingular(&head);
				system("pause");
				break;
			}
			case 2:
			{
				SingularInfo();
				break;
			}
			default: 
			{
				printf("Pogresan unos, pokusajte ponovno!\n");
				system("pause");
				system("cls");
			}
		}

	}
	system("cls");
}
int Double()
{
	int menu_choice;
	struct double_node double_head;
	double_head.next = NULL;
	double_head.prev = NULL;
	double_head.number = NULL;

	while (1)
	{
		system("cls");
		printf("*** DVOSTRUKO VEZANE LISTE ***\n");
		printf("Ako su liste tako dobre, zasto ne postoje liste 2? Najblize tome sto imamo su dvostruko vezane liste.\n\n");
		printf("Odaberite opciju:\n\t1 - Vizualna reprezentacija\n\t2 - Vise informacija\n\t3 - povratak\n: ");
		scanf(" %d", &menu_choice);

		if (menu_choice == 3)
			break;

		switch (menu_choice)
		{
			case 1:
			{
				WriteDouble(&double_head);
				VisualPrintDouble(&double_head);
				FreeDouble(&double_head);
				system("pause");
				break;
			}
			case 2:
			{
				DoubleInfo();
				break;
			}
			default:
			{
				printf("Pogresan unos, pokusajte ponovno!\n");
				system("pause");
				system("cls");
			}
		}
	}
	system("cls");
}
int Circle()
{
	int menu_choice;
	struct node head;
	head.next = NULL;
	head.number = NULL;

	while (1)
	{
		system("cls");
		printf("*** CIRKULARNE LISTE ***\n");
		printf("You spin me right 'round, baby, right 'round like a record, baby, right 'round, 'round, 'round.\n\n");
		printf("Odaberite opciju:\n\t1 - Vizualna reprezentacija\n\t2 - Vise informacija\n\t3 - povratak\n: ");
		scanf(" %d", &menu_choice);

		if (menu_choice == 3)
			break;

		switch (menu_choice)
		{
		case 1:
		{
			WriteCircular(&head);
			VisualPrintCircular(&head);
			FreeCircular(&head);
			system("pause");
			break;
		}
		case 2:
		{
			CircleInfo();
			break;
		}
		default:
		{
			printf("Pogresan unos, pokusajte ponovno!\n");
			system("pause");
			system("cls");
		}
		}
	}
	system("cls");
}
int Stack()
{
	struct node head;
	head.next = NULL;

	int menu_choice;

	while (1)
	{
		system("cls");
		printf("*** STACK ***\n");
		printf("stackstackstack.\n\n");
		printf("Odaberite opciju:\n\t1 - push\n\t2 - pop\n\t3 - ispis stacka\n\t4 - povratak\n:");
		scanf("%d", &menu_choice);

		if (menu_choice == 4)
			break;

		switch (menu_choice)
		{
		case 1:
		{
			Push(&head);
			SlowPrint(head.next);
			system("pause");
			break;
		}
		case 2:
		{
			Pop(&head);
			VisualPrintStack(head.next);
			system("pause");
			break;
		}
		case 3:
		{
			VisualPrintStack(head.next);
			system("pause");
			break;
		}
		default:
		{
			printf("Pogresan unos, pokusajte ponovno!\n");
			system("pause");
			system("cls");
		}
		}

	}
	system("cls");
}


