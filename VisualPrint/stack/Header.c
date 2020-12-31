#include"Header.h"
#include<stdio.h>
#include<stdlib.h>

int VisualPrintStack(Position p)
{
	printf("pop  \n");
	while (p != NULL)
	{
		printf("%d  |", p->element);
		p = p->next;
	}
	puts("\n");
	return 0;
}
