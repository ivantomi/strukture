#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#define max 125

typedef struct {
	char ime[20];
	char prz[20];
	float bod;
}student;

void fja(FILE*, student*, int);

int main()
{
	student* stud;
	int i;
	char c;
	int n = 0;
	FILE* dat;
	dat = fopen("studenti.txt", "r");
	if (dat == NULL)
		printf("Null pointer");

	while (!feof(dat))
		if (fgetc(dat) == '\n')
			n++;

	rewind(dat);
	
	stud = (student*)malloc(n * sizeof(student));
	fja(dat, stud, n);
	
	fclose(dat);

	return 0;
}

void fja(FILE* dat, student* stud, int n)
{
	int i;
	float rel;
	for (i = 0; i < n; i++)
	{
		fscanf(dat, "%s %s %f", stud[i].ime, stud[i].prz, &stud[i].bod);
		rel = stud[i].bod / max * 100;
		printf("Ime i prezime: %s %s\n\tBodovi: %.2f  (%.0f%%)\n\n", stud[i].ime, stud[i].prz, stud[i].bod, rel);
	}
}
