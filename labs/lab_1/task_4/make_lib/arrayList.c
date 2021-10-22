#include <stdlib.h>
#include "../arrayList.h"

void increaseListSize(ArrayList* list) {
    int newLength = list->availableLength * 2;
    list->array = (int*)realloc(list->array, sizeof(int) * newLength);
    list->availableLength = newLength;
}

#define DEFAULT_AVAILABLE_LENGTH 10

ArrayList* newArrayList() {
    ArrayList* list = (ArrayList*) malloc(sizeof(ArrayList));

    list->array = (int*) malloc(sizeof(int) * DEFAULT_AVAILABLE_LENGTH);
    list->length = 0;
    list->availableLength = DEFAULT_AVAILABLE_LENGTH;

    return list;
}

void add(ArrayList* list, int item) {

    if (list->availableLength <= list->length) {
        increaseListSize(list);
    }

    list->array[list->length] = item;
    list->length++;
}

void insert(ArrayList* list, int index, int item) {
    if (list->availableLength <= list->length){
        increaseListSize(list);
    }

    int i;
    for (i = list->length; i > index; i--) {
        list->array[i] = list->array[i - 1];
    }
    list->array[index] = item;
    list->length++;
}

int size(ArrayList* list) {
    return list->length;
}

void removeByIndex(ArrayList* list, int index) {
    int i;
    for (i = index; i < list->length; i++) {
        list->array[i] = list->array[i + 1];
    }
    list->length--;
}

void set(ArrayList* list, int index, int item) {
    list->array[index] = item;
}

int get(ArrayList* list, int index) {
    return list->array[index];
}
