#include <stdio.h>
#include <string.h>
#include "header.h"

struct worker
{
	int nomer_sotrudnika;
	char fio[40];
	char dolj[40];
	int year;
};
static worker data[20], temp[20];
int kol_sotrudnikov;
extern void enter()
{
	register int a;
	printf("How many workers will you hire: ");
	scanf_s("%d", &kol_sotrudnikov);
	for (a = 0; a < kol_sotrudnikov; a++)
	{
		printf("\nEnter number of worker: ");
		scanf_s("%d", &data[a].nomer_sotrudnika);
		printf("Enter full name of worker: ");
		getchar();
		gets_s(data[a].fio, 40);
		printf("Enter job title of worker: ");
		gets_s(data[a].dolj, 40);
		printf("Enter year of admission: ");
		scanf_s("%d", &data[a].year);
	}
	printf("\n");
}
extern void print()
{
	register int a;
	printf("\n");
	printf("# 	     Full name		    Title		Year\n");
	printf("*************************************************************\n");
	for (a = 0; a < kol_sotrudnikov; a++)
	{
		if (data[a].nomer_sotrudnika != -1)
		{
			printf("%d %20s %18s %18d", data[a].nomer_sotrudnika, data[a].fio, data[a].dolj, data[a].year);
			printf("\n");
		}
	}
	printf("\n");
}
extern int read()
{
	register int a;
	printf("Write the number of worker to read information.\n");
	int choice;
	scanf_s("%d", &choice);
	for (a = 0; a < kol_sotrudnikov; a++)
	{
		if (choice == data[a].nomer_sotrudnika)
		{
			printf("# 	     Full name		    Title		Year\n");
			printf("*************************************************************\n");
			printf("%d %20s %18s %18d", data[a].nomer_sotrudnika, data[a].fio, data[a].dolj, data[a].year);
			printf("\n\n");
			return 0;
		}
	}
	printf("There isn't such a number of worker.\n");
}
extern int staj()
{
	if (!data[0].nomer_sotrudnika)
	{
		printf("You must enter information.\n\n");
		return 0;
	}
	register int a, k = 0;
	printf("Set the requiered work experience.\n");
	int choice;
	scanf_s("%d", &choice);
	for (a = 0; a < kol_sotrudnikov; a++)
	{
		if (2024 - data[a].year >= choice && data[a].nomer_sotrudnika != -1)
		{
			if (k == 0)
			{
				printf("# 	     Full name		    Title		Year\n");
				printf("*************************************************************\n");
				k++;
			}
			printf("%d %20s %18s %18d", data[a].nomer_sotrudnika, data[a].fio, data[a].dolj, data[a].year);
			printf("\n");
		}
	}
	if (k == 0)
	{
		printf("There aren't such workers.\n");
	}
	printf("\n");
	return 0;
}
extern int sort()
{
	if (!data[0].nomer_sotrudnika)
	{
		printf("You must enter information.\n\n");
		return 0;
	}
	register int a, b;
	printf("OLD");
	print();
	for (a = 0; a < kol_sotrudnikov - 1; a++)
		for (b = a + 1; b < kol_sotrudnikov; b++)
		{
			if (strcmp(data[a].fio, data[b].fio) > 0)
			{
				temp[b] = data[b];
				data[b] = data[a];
				data[a] = temp[b];
			}
		}
	printf("NEW");
	print();
	printf("***Complited***\n");
	printf("\n");
	return 0;
}
/*extern int del()
{
	register int a;
	printf("Write the number of worker which you want delete.\n");
	int choice;
	scanf_s("%d", &choice);
	for (a = 0; a < kol_sotrudnikov; a++);
	{
		printf("%d %d\n", choice, data[a].nomer_sotrudnika);
		if (choice == data[a].nomer_sotrudnika)
		{
			data[a].nomer_sotrudnika = -1;
			print();
			return 0;
		}
	}
	printf("There isn't such a number of worker.\n");
}*/