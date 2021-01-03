#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"Header.h"

int main()
{
	struct node HeadStog, HeadRed;
	HeadStog.next = NULL;
	HeadRed.next = NULL;

	srand((unsigned)time NULL);
	char odabir[256];
	int c;

	do {
		printf("Unesite 'push', 'pop', 'kraj': ");
		scanf(" %s", odabir);
		c = Transform(odabir);
		if (c == 1)
		{
			Push(&HeadStog);
			Push(&HeadRed);
		}
		else if (c == 2)
		{
			Pop(&HeadStog);
			VisualPrintStack(HeadStog.next);
			BrisiRed(&HeadRed);
		}
		else if (c == 0)
			break;

		else printf("Probajte opet.\n");

		if (c == 1)
			SlowPrint(HeadStog.next);

	} while (1);
}
