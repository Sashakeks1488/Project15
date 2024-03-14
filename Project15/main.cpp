#include <stdio.h>
#include "header.h"

extern int kol_zakazov;

int main()
{
	int choice;
	do {
		printf("1. Enter information.\n");
		printf("2. Read information.\n");
		printf("3. Read onpedel. information.\n");
		printf("4. Sort information.\n");
		printf("5. Read information about workers with work experience you need.\n");
		printf("6. Delete information about a worker.\n");
		printf("7. Quit from programm.\n\n");
		printf("Enter your choice: ");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1: enter();
			break;
		case 2: print();
			break;
		case 3: read();
			break;
		case 4: sort();
			break;
		case 5: staj();
			break;
		case 6: return 0;
		}
	} while (choice != 6);
	return 0;
}
