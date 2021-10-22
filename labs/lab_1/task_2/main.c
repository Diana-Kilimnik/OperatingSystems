#include <stdio.h>
#include "arrCalculations.h"

int main(void)
{
    int n;
    printf("Enter count of numbers:\n");
    printf("n = ");
    scanf("%d", &n);
    if (n < 1)
    {
        printf("Incorrect input!\n");
        return 1;
    }

    double *a = (double *)generateRandArray(n);

    printArray(a, n);

    findCountOfNumbersGreaterThanAvg(a, n);
    findSumAbsAfterFirstNegativeNumber(a, n);

    free(a);
    return 0;
}