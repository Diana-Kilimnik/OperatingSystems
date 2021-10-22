#define SIZE 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "user-interface.h"

int *generateRandArray(int size);
void printArray(int *arr, int size);
int checkArray(int *arr, int size);
int isRepetition(int *arr, int num);
int isSeven(int *arr, int size);
int areAllNumbersSimilar(int *arr, int size);
int isOneThirdOfNumbersSimilar(int *arr, int size);

int main()
{
  printName();
  int play = 1;
  double money = 0;
  srand(time(NULL));
  printEnterBudget();
  scanf("%lf", &money);

  if (money < 0)
  {
    printEnterCorrectData();
  }

  while (money > 0 && play)
  {
    int *num = (int *)generateRandArray(SIZE);
    printArray(num, SIZE);

    switch (checkArray(num, SIZE))
    {
    case 0:
    {
      money = 0;
      printYouLose();
      break;
    }
    case 1:
    {
      printReturnYourMoney();
      break;
    }
    case 2:
    {
      printYouWinX(2);
      money *= 2;
      break;
    }
    case 3:
    {
      printYouWinX(3);
      money *= 3;
      break;
    }
    }
    if (money > 0)
    {
      printYourCurrentBalance(money);
      printDoYouWantContinue();
      scanf("%d", &play);
    }
  }
  printGameOver();
  printYourCurrentBalance(money);
  printThanksForPlaying();
}

int *generateRandArray(int size)
{
  int *num = (int *)malloc(size * sizeof(int));
  for (int i = 0; i < size; i++)
    *(num + i) = rand() % 9;
  return num;
}

void printArray(int *ar, int size)
{
  printf("\n");
  for (int i = 0; i < size; i++)
    printf("%d", *(ar + i));
  printf("\n");
}

int checkArray(int *ar, int size)
{
  if (isRepetition(ar, size))
  {
    //There was a repetition!
    if (areAllNumbersSimilar(ar, size))
    {
      if (isSeven(ar, size))
      {
        //All numbers are seven!
        return 3;
      }
      else
      {
        //All numbers are similar!
        return 2;
      }
    }
    else
    {
      if (isOneThirdOfNumbersSimilar(ar, size))
      {
        //One third of the numbers is similar
        return 1;
      }
    }
  }
  if (isSeven(ar, size))
  {
    //number has 7
    return 1;
  }
  return 0;
}

int isRepetition(int *ar, int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = i + 1; j < size; j++)
      if (*(ar + i) == *(ar + j))
        return 1;
  }
  return 0;
}

int isSeven(int *ar, int size)
{
  for (int i = 0; i < size; i++)
    if (*(ar + i) == 7)
      return 1;
  return 0;
}

int areAllNumbersSimilar(int *ar, int size)
{
  for (int i = 0; i < size; i++)
  {
    if (*(ar) != *(ar + i))
      return 0;
  }
  return 1;
}

int isOneThirdOfNumbersSimilar(int *ar, int size)
{
  int repetitions = 1;
  int minRepetitions = size / 3;
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (*(ar + i) == *(ar + j))
        repetitions++;
    }
    if (repetitions >= minRepetitions)
      return 1;
    repetitions = 1;
  }
  return 0;
}