#include <stdio.h>
#include "LinkedList.h"

int check_input_value();
int menuList();
void clean_stdin();

int main()
{
	int choice = -1;
	while (choice != 0)
	{
		choice = menuList();
		switch (choice)
		{
		case 1:
		{
			printf("Num = ");
			add(check_input_value());
			break;
		}
		case 2:
		{
			printf("Num = ");
			int num = check_input_value();
			printf("Index = ");
			set(num, check_input_value());
			break;
		}
		case 3:
		{
			printf("Index = ");
			int index = check_input_value();
			printf("Num = %d\n", get(index));
			break;
		}
		case 4:
		{
			printList();
			break;
		}
		case 5:
		{
			printf("Index = ");
			printf("\nRemoved num: %d\n", rm(check_input_value()));
			break;
		}
		case 6:
		{
			printf("Num = ");
			int num = check_input_value();
			printf("Index = ");
			insert(num, check_input_value());
			break;
		}
		case 7:
		{
			printf("Size = %d\n", size());
			break;
		}
		}
	}
}

int check_input_value()
{
	int b = 0;
	int a;
	do
	{
		b = scanf("%d", &a);
		if (b != 1)
		{
			printf("\n\tEnter a number:");
			clean_stdin();
		}
	} while (b != 1);
	return a;
}

void clean_stdin(void)
{
	int c;
	do
	{
		c = getchar();
	} while (c != '\n' && c != EOF);
}

int menuList()
{
	int choice = -1;
	printf("\n\nMAIN MENU\n"
		   "1. Add\n"
		   "2. Set\n"
		   "3. Get\n"
		   "4. Print\n"
		   "5. Remove\n"
		   "6. Insert\n"
		   "7. Size\n"
		   "0. Exit\n"
		   "Choice: ");
	while (choice < 0 || choice > 7)
	{
		choice = check_input_value();
		if (choice < 0 || choice > 7)
			printf("\nUnknown operation! ");
	}
	return choice;
}
