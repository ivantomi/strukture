#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include"Header.h"



int main()
{
	int i;
	struct node head;
	head.next = NULL;

	for (i = 0; i < 1000; i++)
		Entry(i, &head);

	VisualPrintCircular(&head);
}