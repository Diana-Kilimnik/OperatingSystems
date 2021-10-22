#include <stdio.h>
#include "struct.h"

void percent(struct student arr[]);
char *subject(struct student arr[]);
void debtor(struct student arr[]);
int lowGroup(struct student arr[]);

int main(void)
{
	struct student arr[MAXST] = {"Ivanov", 1, 60, 70, 80,
								 "Antonov", 1, 30, 50, 50,
								 "Petrov", 1, 70, 49, 80,
								 "Popov", 2, 90, 90, 100,
								 "Ivanov", 2, 30, 70, 50,
								 "Kotov", 2, 60, 60, 60,
								 "Korol", 3, 100, 100, 100,
								 "Zorin", 3, 70, 50, 60,
								 "Koval", 3, 50, 80, 80,
								 "Bobrov", 4, 30, 30, 30,
								 "Strelov", 4, 70, 45, 80,
								 "Vetrov", 4, 50, 50, 50};

	printf("1. Show all debtors\n");
	printf("2. Show group with the smallest progress\n");
	printf("3. Show percent of students with 70+ scores\n");
	printf("4. Show the best marked subject\n");
	printf("0. Quit\n");
	int n = -1;
	while (n != 0)
	{
		printf("Enter your choise >> ");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
		{
			debtor(arr);
			break;
		}
		case 2:
		{
			printf("The smallest progress in group # %d\n", lowGroup(arr));
			break;
		}
		case 3:
		{
			percent(arr);
			break;
		}
		case 4:
		{
			printf("The best marked subject is %s\n", subject(arr));
			break;
		}
		case 0:
			break;
		default:
		{
			printf("Wrong choise!\n");
		}
		}
	}

	return (EXIT_SUCCESS);
}
