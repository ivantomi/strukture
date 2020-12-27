#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct directory;
typedef struct directory* position;
typedef struct directory {
	char name[1024];
	position sibling;
	position child;
};

struct stack;
typedef struct stack* stack_position;
typedef struct stack {
	stack_position next;
	position pointer;
};

int Delete(position);
position mkdir(position);
position chdir(position);
int push(position, stack_position);
int Print(stack_position);
position cddotdot(stack_position);
position ls(position);


int Delete(position p)
{
	if (p == NULL)
		return NULL;
	Delete(p->sibling);
	Delete(p->child);
	free(p);
}

int main()
{
	position root = malloc(sizeof(struct directory));
	root->child = NULL;
	stack_position head = malloc(sizeof(struct stack));
	head->next = NULL;
	head->pointer = root;
	strcpy(root->name, "C:\\");
	root->sibling = NULL;
	position current = root;

	current = mkdir(current);

	current = chdir(current);
	push(current, head);
	Print(head);

	current = mkdir(current);
	current = mkdir(current);
	printf("U trenutnom direktoriju:\n");
	current = ls(current);

	printf("cd..\n");
	current = cddotdot(head);

	Print(head);
}

position mkdir(position root)
{
	char name[20];
	printf("Unesite ime direktorija: ");
	scanf(" %s", name);
	position new = malloc(sizeof(struct directory));
	new->sibling = new->child = NULL;
	strcpy(new->name, name);
	if (root->child == NULL)
		root->child = new;
	else
	{
		position temp = root->child;
		while (temp->sibling != NULL)
			temp = temp->sibling;
		temp->sibling = new;
	}
	return root;
}

position chdir(position root)
{
	char name[20];
	printf("Unesite ime direktorija u kojeg zelite uci: ");
	scanf("%s", name);
	position temp = root->child;
	while (temp != NULL && strcmp(temp->name, name) != 0)
		temp = temp->sibling;

	return temp;
}

int push(position tree, stack_position head)
{
	while (head->next != NULL)
		head = head->next;
	stack_position new = malloc(sizeof(struct stack));
	head->next = new;
	new->pointer = tree;
	new->next = NULL;
}

int Print(stack_position head)
{
	while (head != NULL)
	{
 		printf("%s\\", head->pointer->name);
		head = head->next;
	}
	printf("\n");
}

position cddotdot(stack_position head)
{
	stack_position temp = head->next;
	if (temp == NULL)
		printf("Ne mozes se vratiti!\n");
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
			head = head->next;
		}
		head->next = NULL;
		free(temp);
	}
	return head;
}

position ls(position root)
{
	position temp = root->child;
	while (temp != NULL)
	{
		printf("%s\n", temp->name);
		temp = temp->sibling;
	}
	return root;
}
