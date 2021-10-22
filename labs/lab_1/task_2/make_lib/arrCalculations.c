#include "../arrCalculations.h"

double *generateRandArray(int size)
{
    double *a = malloc(size * sizeof(double));
    for (int i = 0; i < size; i++)
        *(a + i) = rand() % 20 - 10;
    return a;
}

void printArray(double *ar, int size)
{
    printf("\nArray:\n");
    for (int i = 0; i < size; i++)
        printf("%.2lf\n", *(ar + i));
    printf("\n");
}

void findCountOfNumbersGreaterThanAvg(double *ar, int size)
{
    double sum = 0.0f;
    for (int i = 0; i < size; i++)
    {
        sum += ar[i];
    }
    double avg = sum / (double)size;
    printf("Avg = %.2lf\n", avg);

    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (ar[i] > avg)
            count++;
    }

    printf("Count = %d\n", count);
}

void findSumAbsAfterFirstNegativeNumber(double *ar, int size)
{
    double sumAbs = 0.0f;
    int j = 0;
    for (j; j<size &&*(ar + j)> 0; j++)
    {
    }
    if (j != size - 1)
    {
        for (j++; j < size; j++)
        {
            sumAbs += abs(ar[j]);
        }
    }

    printf("SumAbs = %.2lf\n", sumAbs);
}