#include <stdio.h>
#include <stdlib.h>

#define MAXST 12

struct student
{
	char *surname;
	int group;
	int web;
	int ukr;
	int infSys;
};

void debtor(struct student arr[]);
int lowGroup(struct student arr[]);
void percent(struct student arr[]);
char *subject(struct student arr[]);