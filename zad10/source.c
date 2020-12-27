#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tree* tree_pointer;
struct tree {
	char *element;
	tree_pointer left;
	tree_pointer right;
};

typedef struct stack* stack_pointer;
struct stack {
	tree_pointer position;
	stack_pointer next;
};

tree_pointer Start(char*, stack_pointer);
int Check(char*);
tree_pointer Insert(tree_pointer, tree_pointer);
tree_pointer pop(stack_pointer);
int push(stack_pointer, stack_pointer);
stack_pointer NewStackNode(tree_pointer);
tree_pointer NewTreeNode(char*);
int Print(tree_pointer);

int main()
{
	stack_pointer head = (stack_pointer) malloc(sizeof(struct stack));
	head->next = NULL;
	head->position = NULL;
	tree_pointer tree = malloc(sizeof(struct tree));
	tree = Start("postfix.txt", head);

	Print(tree);
}

tree_pointer Start(char* name, stack_pointer head)
{

	FILE* dat = fopen(name, "r");
	if (dat == NULL)
		printf("krivo ime datoteke");

	char helper[100];
	tree_pointer first, second;

	while (!feof(dat))
	{
		fscanf(dat, "%s ", helper);

		tree_pointer new_tree = NewTreeNode(helper);
		stack_pointer new_stack = NewStackNode(new_tree);

		if (Check(helper) == 0)
			push(new_stack, head);
		else
		{
			first = pop(head);
			second = pop(head);
			Insert(first, new_tree);
			Insert(second, new_tree);
			push(new_stack, head);
		}
	}
	fclose(dat);
	return pop(head);
}

int Check(char* helper)
{
	if (strcmp(helper, "+") != 0 && strcmp(helper, "-") != 0 && strcmp(helper, "*") != 0 && strcmp(helper, "/") != 0)
		return 0;
	else
		return 1;
}

tree_pointer Insert(tree_pointer tree, tree_pointer root)
{
	if (root == NULL)
		return NULL;
	else if (root->left == NULL)
		root->left = tree;
	else if (root->right == NULL)
		root->right = tree;

	return root;
}

int push(stack_pointer p, stack_pointer head)
{
	p->next = head->next;
	head->next = p;
}

tree_pointer pop(stack_pointer head)
{
	stack_pointer popper = head->next;
	if (popper == NULL)
		return 0;
	head->next = popper->next;
	tree_pointer tree = popper->position;
	free(popper);

	return tree;
}

tree_pointer NewTreeNode(char* helper)
{
	tree_pointer new = malloc(sizeof(struct tree));
	new->left = new->right = NULL;
	new->element = malloc(sizeof(char) * strlen(helper));
	strcpy(new->element, helper);

	return new;
}

stack_pointer NewStackNode(tree_pointer tree)
{
	stack_pointer new= malloc(sizeof(struct stack));
	new->next = NULL;
	new->position = tree;

	return new;
}

int Print(tree_pointer root)
{
	if (root != NULL)
	{
		Print(root->left);
		printf("%s ", root->element);
		Print(root->right);
	}
	
	return 0;
}
