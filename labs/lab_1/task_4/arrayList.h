#ifndef OPERATING_SYSTEM_ARRAY_LIST_H
#define OPERATING_SYSTEM_ARRAY_LIST_H

typedef struct
{
    int *array;
    int length;
    int availableLength;
} ArrayList;

ArrayList *newArrayList();
void add(ArrayList *list, int item);
void insert(ArrayList *list, int index, int item);
int size(ArrayList *list);
void removeByIndex(ArrayList *list, int index);
void set(ArrayList *list, int index, int item);
int get(ArrayList *list, int index);

#endif