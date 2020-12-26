#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 256
#define max_table 11

struct node;
typedef struct node* position;
typedef struct node* list;
struct hashT;
typedef struct hashT *hashTab;

hashTab Start(int);
void DeleteTable(hashTab);
position Search(char*, hashTab);
int Add(char*, hashTab);
int Hash(char*, int);
int Print(hashTab);

struct node {
	char name[max];
	char surname[max];
	int mb;
	position next;
};

struct hashT {
	int size;
	list* hashList;
};

hashTab Start(int size)
{
	hashTab H;

	H = malloc(sizeof(struct hashT));
	H->size = 11;
	H->hashList = malloc(sizeof(list) * H->size);

	for (int i = 0; i < size; i++)
		H->hashList[i] = NULL;

	return H;
}

int Hash(char* surname, int size)
{
	int value = 0;

	while (*surname != '\0')
		value = value + *surname++;
	return value % size;
}

position Search(char *surname, hashTab H)
{
	list L;

	L = H->hashList[Hash(surname, H->size)];
	while (L != NULL && strcmp(L->surname, surname) != 0)
		L = L->next;

	return L;
}

int Add(list L, hashTab H)
{
	L->next = H->hashList[Hash(L->surname, H->size)];
	H->hashList[Hash(L->surname, H->size)] = L;
}

list DataEntry()
{
	list L = malloc(sizeof(struct hashT));
	printf("Unesite ime, prezime i maticni broj: ");
	scanf("%s %s %d", L->name, L->surname, &L->mb);

	return L;

}

int Print(hashTab H)
{
	for (int i = 0; i < max_table; i++)
	{
		if (H->hashList[i] == NULL)
			printf("%d\txxx", i);
		else
		{
			printf("%d\t", i);
			position temp = H->hashList[i];
			while (temp != NULL)
			{
				printf("%s %s || ", temp->name, temp->surname);
				temp = temp->next;
			}
		}
		printf("\n");
	}
}

int main()
{
	struct hashT *head = Start(max_table);
	int number;
	list temp = malloc(sizeof(struct node));
	
	while (1)
	{
		printf("1 za unos novog studenta, 2 za kraj: ");
		scanf("%d", &number);
		
		if (number == 1)
		{
			temp = DataEntry();
			Add(temp, head);
		}
		else if (number == 2)
			break;
		else printf("Nepoznat unos!\n");
	}

	Print(head);

	return 0;
}
