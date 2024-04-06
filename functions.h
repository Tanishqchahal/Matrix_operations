#ifndef FUNCTIONS_H
#define FUNCTIONS_H
// DO NOT change anything here. You will not submit this file.
// Function prototypes
void generateMatrix(int rows, int cols, double **matrix);
void printMatrix(int rows, int cols, double **matrix);
void addMatrices(int N1, int M1, double **A, int N2, int M2, double **B, double **result);
void subtractMatrices(int N1, int M1, double **A, int N2, int M2, double **B, double **result);
void multiplyMatrices(int N1, int M1, double **A, int N2, int M2, double **B, double **result);
void solveLinearSystem(int N1, int M1, double **A, int N2, int M2, double **B, double **x);
void deallocateMatrix(int rows, double **matrix);
#endif /* FUNCTIONS_H */