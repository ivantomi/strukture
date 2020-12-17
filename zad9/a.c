#include<stdio.h>
#include<stdlib.h>

struct treeNode;

typedef struct treeNode* node;
typedef struct treeNode* position;

node CreateEmpty(node);
node Add(int, node);
position Search(node);
node Delete(node);
int Print(node);
position FindMin(node);

struct treeNode {
	int element;
	node left;
	node right;
};

int main()
{
	struct treeNode tree;
	position root = &tree;
	position find;
	root = CreateEmpty(root);
	root = Add(2, root);
	root = Add(5, root);
	root = Add(4, root);
	root = Add(1, root);
	root = Add(8, root);
	root = Add(3, root);
	if (find = Search(17, root) != NULL)
		printf("Trazeni element je na poziciji %p.\n", find);
	else printf("Nema tog elementa.\n");
	Print(root);
	root = Delete(3, root);
	printf("\n");
	Print(root);
}

node CreateEmpty(node tree)
{
	if (tree != NULL)
		return NULL;
	else
	{
		CreateEmpty(tree->left);
		CreateEmpty(tree->right);
		free(tree);
	}
	return NULL;
}

node Add(int x, node tree)
{
	if (tree == NULL)
	{
		tree = malloc(sizeof(struct treeNode));
		tree->element = x;
		tree->left = NULL;
		tree->right = NULL;
	}
	else if (x < tree->element)
		tree->left = Add(x, tree->left);
	else if (x > tree->element)
		tree->right = Add(x, tree->right);

	return tree;
}

int Print(node tree)
{
	if (tree != NULL)
	{
		Print(tree->left);
		printf("%d ", tree->element);
		Print(tree->right);
	}
	return 0;
}

position Search(int x, node tree)
{
	if (tree == NULL)
		return NULL;
	else if (x < tree->element)
		return Search(x, tree->left);
	else if (x > tree->element)
		return Search(x, tree->right);
	return tree;
}

position FindMin(node tree)
{
	if (tree == NULL)
		return NULL;
	else if (tree->left == NULL)
		return tree;
	else return FindMin(tree->left);
}

node Delete(int x, node tree)
{
	position temp;
	if (tree == NULL)
		printf("Taj element ne postoji!\n");
	else if (x < tree->element)
		tree->left = Delete(x, tree->left);
	else if (x > tree->element)
		tree->right = Delete(x, tree->right);
	else if (tree->left && tree->right != NULL)
	{
		temp = FindMin(tree->right);
		tree->element = temp->element;

		tree->right = Delete(tree->element, tree->right);
	}
	else
	{
		temp = tree;
		if (tree->left == NULL)
			tree = tree->right;
		else tree = tree->left;
		free(temp);
	}

		return tree;
}

