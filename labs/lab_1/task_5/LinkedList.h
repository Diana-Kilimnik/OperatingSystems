#include <stdlib.h>
#include <stdio.h>

#ifndef LIST_

typedef struct linked_list{
	int num;
	struct linked_list *next;
    struct linked_list *prev;
}LinkedList;

extern LinkedList* ar;

void printList();
void add(int num);
int size();
int rm(int index);
void set(int num, int index);
void insert(int num, int index);
int get(int index);

#endif