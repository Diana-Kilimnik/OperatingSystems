#include "../LinkedList.h"

LinkedList *ar;

void add(int num)
{
    LinkedList *ptr = ar, *node = (LinkedList *)malloc(sizeof(LinkedList));
    node->next = NULL;
    node->num = num;
    node->prev = NULL;
    if (ar != NULL)
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = node;
        node->prev = ptr;
    }
    else
        ar = node;
}

int size()
{
    LinkedList *ptr = ar;
    int i;
    for (i = 0; ptr != NULL; i++)
    {
        ptr = ptr->next;
    }
    return i;
}

int rm(int index)
{
    int buf = 0;
    if (index < size() && index > -1)
    {
        LinkedList *curPtr = ar;
        if (index == 0)
            ar = curPtr->next;
        for (int i = 0; i < index; i++)
        {
            curPtr = curPtr->next;
        }
        if (curPtr->prev != NULL)
            curPtr->prev->next = curPtr->next;
        if (curPtr->next != NULL)
            curPtr->next->prev = curPtr->prev;
        buf = curPtr->num;
        free(curPtr);
    }
    else
        printf("\n\aInvalid index or nothing to remove!");
    return buf;
}

void insert(int num, int index)
{
    if (index < size() && index > -1 && ar != NULL)
    {
        LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList)), *curPtr = ar;
        node->num = num;
        node->prev = NULL;
        node->next = NULL;
        for (int i = 0; i < index; i++)
        {
            curPtr = curPtr->next;
        }
        node->prev = curPtr->prev;
        node->next = curPtr;
        if (curPtr->prev != NULL)
            curPtr->prev->next = node;
        curPtr->prev = node;
        if (index == 0)
            ar = node;
    }
    else if (index == 0 && ar == NULL)
    {
        add(num);
    }
    else
        printf("\n\aInvalid index!");
}

void set(int num, int index)
{
    if (index < size() && index > -1)
    {
        LinkedList *curPtr = ar;
        for (int i = 0; i < index; i++)
        {
            curPtr = curPtr->next;
        }
        curPtr->num = num;
    }
    else
        printf("\n\aInvalid index!");
}

int get(int index)
{
    int buf = 0;
    if (index < size() && index > -1)
    {
        LinkedList *curPtr = ar;
        for (int i = 0; i < index; i++)
        {
            curPtr = curPtr->next;
        }
        return curPtr->num;
    }
    else
        printf("\n\aInvalid index!");
    return buf;
}

void printList()
{
    if (ar != NULL)
    {
        LinkedList *curPtr = ar;
        printf("\n");
        while (curPtr != NULL)
        {
            printf("%d ", curPtr->num);
            curPtr = curPtr->next;
        }
        printf("\n");
    }
    else
        printf("\tThe list is empty!\n");
}