#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node* Position;

struct node {
	int element;
	Position next;
};

Position UnosPostfix();
int Push(int, Position);
int Pop(Position);
int Addition(Position);
int Substraction(Position);
int Multiplication(Position);
int Division(Position);


int main()
{
	Position izraz = UnosPostfix();
	printf("Rezultat je: %d ", izraz->element);
	
}

Position UnosPostfix()
{
	FILE* file = fopen("postfix.txt", "r");
	struct node Head;
	Head.next = NULL;
	Position p = &Head;

	char op[10];
	int result, a, b;
	

	while (!(feof(file)))
	{
		fscanf(file, "%s ", op);

		if (strcmp(op, "+") == 0)
			Addition(p);
		else if (strcmp(op, "-") == 0)
			Substraction(p);
		else if (strcmp(op, "*") == 0)
			Multiplication(p);
		else if (strcmp(op, "/") == 0)
			Division(p);
		else
			Push(atoi(op), p);
	}
	fclose(file);
	return Head.next;
}

int Push(int x, Position p)
{
	Position q = malloc(sizeof(struct node));

	q->element = x;
	q->next = p->next;
	p->next = q;

	return 0;
}

int Pop(Position p)
{
	Position temp = p->next;
	p->next = temp->next;
	int number = temp->element;
	free(temp);
	return number;

}

int Addition(Position p)
{
	int number1 = Pop(p);
	int number2 = Pop(p);

	Push(number1 + number2, p);

	return 0;
}

int Substraction(Position p)
{
	int number1 = Pop(p);
	int number2 = Pop(p);

	Push(number1 - number2, p);

	return 0;
}

int Multiplication(Position p)
{
	int number1 = Pop(p);
	int number2 = Pop(p);

	Push(number1 * number2, p);

	return 0;
}

int Division(Position p)
{
	int number1 = Pop(p);
	int number2 = Pop(p);

	Push(number1 / number2, p);

	return 0;
}
