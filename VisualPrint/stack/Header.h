#pragma once
typedef struct node* Position;
struct node {
	int element;
	int next;
};

int VisualPrintStack(Position);
