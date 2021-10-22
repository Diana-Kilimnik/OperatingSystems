#include <stdio.h>
#include "matrix.h"

int main()
{
    printf("Fill first matrix:\n");
    Matrix *matrix1 = newMatrix(2, 2);
    fillMatrixThroughTerminal(matrix1);
    printf("\n");

    printf("SAVE MATRIX TO FILE...\n");
    saveMatrixToFile(matrix1, "matrix.txt");

    printf("LOAD MATRIX FROM FILE...\n");
    Matrix *savedMatrix = loadMatrixFromFile("matrix.txt");

    printf("Loaded matrix:\n");
    printMatrix(savedMatrix);
    printf("\n");

    printf("Fill second matrix:\n");
    Matrix *matrix2 = newMatrix(2, 2);
    fillMatrixThroughTerminal(matrix2);
    printf("\n");

    printf("First matrix:\n");
    printMatrix(matrix1);
    printf("Second matrix:\n");
    printMatrix(matrix2);
    printf("\n");

    printf("Sum of two matrix:\n");
    Matrix *sumMatrix = sum(matrix1, matrix2);
    printMatrix(sumMatrix);
    printf("\n");

    printf("Subtraction of two matrix\n");
    Matrix *subtractionMatrix = subtraction(matrix1, matrix2);
    printMatrix(subtractionMatrix);
    printf("\n");

    printf("USING SET MATRIX METHOD TO INDEX [0, 0] (1 time)\n");
    set(matrix1, 0, 0, 1337);
    printf("Element with indexes [0, 0] is %.2lf\n\n", get(matrix1, 0, 0));

    printf("USING RESIZE MATRIX METHOD (2 times for 2 matrix)\n");
    resizeMatrix(matrix1, 3, 2);
    resizeMatrix(matrix2, 2, 3);

    printf("First matrix:\n");
    printMatrix(matrix1);
    printf("Second matrix:\n");
    printMatrix(matrix2);
    printf("\n");

    printf("USING MULTIPLICATION MATRIX METHOD\n");
    Matrix *multiplicationMatrix = multiplication(matrix1, matrix2);

    printf("Multiplicated matrix:\n");
    printMatrix(multiplicationMatrix);
    printf("\n");

    printf("Multiplicated by number matrix:\n");
    Matrix *multiplicationMatrixByNumber = multiplicationByNumber(matrix1, 5);
    printMatrix(multiplicationMatrixByNumber);
    printf("\n");

    printf("USING CLEAR MATRIX\n");
    clearMatrix(matrix1);
    clearMatrix(matrix2);
    clearMatrix(sumMatrix);
    clearMatrix(subtractionMatrix);
    clearMatrix(multiplicationMatrix);
    clearMatrix(multiplicationMatrixByNumber);

    return 0;
}