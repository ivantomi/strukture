#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include"Header.h"



int main()
{
	struct node head;
	head.next = NULL;
	head.number = NULL;

	Write(&head);




	VisualPrintSingular(&head);


}