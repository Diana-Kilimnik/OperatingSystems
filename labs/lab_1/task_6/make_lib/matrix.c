#include <stdio.h>
#include <stdlib.h>

#include "../matrix.h"

Matrix *newMatrix(int column, int row)
{
    int i;

    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->row = row;
    matrix->column = column;
    matrix->data = malloc(sizeof(double *) * row);

    for (i = 0; i < row; i++)
    {
        matrix->data[i] = malloc(sizeof(double) * column);
    }

    return matrix;
}

void fillMatrixThroughTerminal(Matrix *matrix)
{
    int i, j;
    for (i = 0; i < matrix->row; i++)
    {
        for (j = 0; j < matrix->column; j++)
        {
            printf("row %d, column %d: ", i, j);
            scanf("%lf", &matrix->data[i][j]);
        }
    }
}

void printMatrix(Matrix *matrix)
{
    int i, j;
    for (i = 0; i < matrix->row; i++)
    {
        for (j = 0; j < matrix->column; j++)
        {
            printf("%0.2lf ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

int getColumnSize(Matrix *matrix)
{
    return matrix->column;
}

int getRowSize(Matrix *matrix)
{
    return matrix->row;
}

double get(Matrix *matrix, int columnIndex, int rowIndex)
{
    return matrix->data[rowIndex][columnIndex];
}

void set(Matrix *matrix, int columnIndex, int rowIndex, double item)
{
    matrix->data[rowIndex][columnIndex] = item;
}

void clearMatrix(Matrix *matrix)
{
    int i;
    for (i = 0; i < matrix->row; i++)
    {
        free(matrix->data[i]);
    }
    free(matrix->data);
}

void resizeMatrix(Matrix *matrix, int column, int row)
{
    int i, j;
    double **newMatrix = (double **)malloc(sizeof(double *) * row);

    for (i = 0; i < row; i++)
    {
        newMatrix[i] = (double *)calloc(sizeof(double), column);
    }

    for (i = 0; i < row && i < matrix->row; i++)
    {
        for (j = 0; j < column && j < matrix->column; j++)
        {
            newMatrix[i][j] = matrix->data[i][j];
        }
    }

    for (i = 0; i < matrix->row; i++)
    {
        free(matrix->data[i]);
    }

    free(matrix->data);

    matrix->row = row;
    matrix->column = column;
    matrix->data = newMatrix;
}

Matrix *sum(Matrix *first, Matrix *second)
{
    int i, j;

    if (first->row == second->row && first->column == second->column)
    {
        Matrix *sum = newMatrix(first->column, first->row);

        for (i = 0; i < sum->row; i++)
        {
            for (j = 0; j < sum->column; j++)
            {
                sum->data[i][j] = first->data[i][j] + second->data[i][j];
            }
        }

        return sum;
    }
    else
    {
        return NULL;
    }
}

Matrix *subtraction(Matrix *first, Matrix *second)
{
    int i, j;

    if (first->row == second->row && first->column == second->column)
    {
        Matrix *subtraction = newMatrix(first->column, first->row);

        for (i = 0; i < subtraction->row; i++)
        {
            for (j = 0; j < subtraction->column; j++)
            {
                subtraction->data[i][j] = first->data[i][j] - second->data[i][j];
            }
        }

        return subtraction;
    }
    else
    {
        return NULL;
    }
}

Matrix *multiplication(Matrix *first, Matrix *second)
{
    int i, j, k;

    if (first->column == second->row)
    {
        Matrix *multiplication = newMatrix(second->column, first->row);

        for (i = 0; i < multiplication->row; i++)
        {
            for (j = 0; j < multiplication->column; j++)
            {
                multiplication->data[i][j] = 0;
                for (k = 0; k < first->column; k++)
                {
                    multiplication->data[i][j] = multiplication->data[i][j] + first->data[i][k] * second->data[k][j];
                }
            }
        }

        return multiplication;
    }
    else
    {
        return NULL;
    }
}

Matrix *multiplicationByNumber(Matrix *matrix, double value)
{
    int i, j;
    Matrix *multiplicationByNumber = newMatrix(matrix->column, matrix->row);

    for (i = 0; i < matrix->row; i++)
    {
        for (j = 0; j < matrix->column; j++)
        {
            multiplicationByNumber->data[i][j] = matrix->data[i][j] * value;
        }
    }
    return multiplicationByNumber;
}

void saveMatrixToFile(Matrix *matrix, char *path)
{
    int i;
    FILE *file = fopen(path, "wb");

    fwrite(&matrix->row, sizeof(int), 1, file);
    fwrite(&matrix->column, sizeof(int), 1, file);

    for (i = 0; i < matrix->row; i++)
    {
        fwrite(matrix->data[i], sizeof(double), matrix->column, file);
    }

    fclose(file);
}

Matrix *loadMatrixFromFile(char *path)
{
    FILE *file = fopen(path, "rb");

    int i, column = 0, row = 0;
    fread(&column, sizeof(int), 1, file);
    fread(&row, sizeof(int), 1, file);

    Matrix *matrix = newMatrix(column, row);

    for (i = 0; i < matrix->row; i++)
    {
        fread(matrix->data[i], sizeof(double), matrix->column, file);
    }

    fclose(file);

    return matrix;
}