#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"

int check_input_value();
int menu();
void clean_stdin();
void printList(ArrayList* list);

int main()
{
    ArrayList *list = newArrayList();
    int ID;

    int choice = -1;
    while (choice != 0)
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            printf("Num = ");
            add(list, check_input_value());
            break;
        case 2:
            printf("Index = ");
            scanf("%d", &ID);
            printf("Num = ");

            if (ID > size(list) || ID == 0)
            {
                printf("Error. Index = %d not exist\n", ID);
            }
            else
            {
                set(list, ID, check_input_value());
            }
            break;
        case 3:
            printf("Index = ");
            scanf("%d", &ID);
            int getInt = 0;
            if (ID > size(list) || ID == 0)
            {
                printf("Error. Index = %d not exist\n", ID);
            }
            else
            {
                getInt = get(list, ID);
                printf("%d\n", getInt);
            }
            break;
        case 4:
            if (list == NULL || size == 0)
            {
                printf("List is empty\n");
            }
            else
                printList(list);
            break;
        case 5:
            printf("Num = ");
            scanf("%d", &ID);
            if (ID > size(list) || ID == 0)
            {
                printf("Error. Index = %d not exist\n", ID);
            }
            else
            {
                removeByIndex(list, ID);
            }
            break;
        case 6:
            printf("Index = ");
            scanf("%d", &ID);
            printf("Num = ");
            if (ID > size(list) + 1 || ID == 0)
            {
                printf("Error. Index = %d not exist\n", ID);
            }
            else
            {
                if (size == 0)
                {
                    add(list, check_input_value());
                }
                else
                {
                    insert(list, ID, check_input_value());
                }
            }
            break;
        case 7:
            printf("Size = %d\n", size(list));
            break;
        case 0:
            return 0;
        default:
            printf("Invalid input!!!\n");
        }
    }
    return 0;
}

int check_input_value()
{
    int b = 0;
    int item;
    do
    {
        b = scanf("%d", &item);
        if (b != 1)
        {
            printf("\nEnter a number:");
            clean_stdin();
        }
    } while (b != 1);
    return item;
}

void clean_stdin(void)
{
    int c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void printList(ArrayList* list) {
    int index;
    for (index = 0; index < list->length; index++) {
        printf("%d ", get(list, index));
    }
}

int menu()
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