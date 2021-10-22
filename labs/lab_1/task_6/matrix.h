#ifndef OPERATING_SYSTEM_MATRIX_H
#define OPERATING_SYSTEM_MATRIX_H

typedef struct
{
    int column;
    int row;
    double **data;
} Matrix;

Matrix *newMatrix(int column, int row);
void fillMatrixThroughTerminal(Matrix *matrix);
void printMatrix(Matrix *matrix);
int getColumnSize(Matrix *matrix);
int getRowSize(Matrix *matrix);
double get(Matrix *matrix, int columnIndex, int rowIndex);
void set(Matrix *matrix, int columnIndex, int rowIndex, double item);
void clearMatrix(Matrix *matrix);
void resizeMatrix(Matrix *matrix, int column, int row);
Matrix *sum(Matrix *first, Matrix *second);
Matrix *multiplication(Matrix *first, Matrix *second);
Matrix *multiplicationByNumber(Matrix *matrix, double value);
Matrix *subtraction(Matrix *first, Matrix *second);
void saveMatrixToFile(Matrix *matrix, char *path);
Matrix *loadMatrixFromFile(char *path);

#endif //OPERATING_SYSTEM_MATRIX_H