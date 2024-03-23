// include necessary library(s)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    // Seed the random number generator
    srand(time(NULL));

    // Check if the number of arguments is correct
    if (argc < 6 || argc > 7) {
        printf("Usage: %s nrows_A ncols_A nrows_B ncols_B <operation> [print]\n", argv[0]);
        return 1;
    }

    int N1 = atoi(argv[1]);
    int M1 = atoi(argv[2]);
    int N2 = atoi(argv[3]);
    int M2 = atoi(argv[4]);

    // Generate random matrices A with size N1*M1 and B with size N2*M2
    double A[N1][M1];
    double B[N2][M2];

    generateMatrix(N1, M1, A);
    generateMatrix(N2, M2, B);
    
    // call the functions as needed
    
    //  print the matrices if the last argument is "print"
    if (argc == 7 && strcmp(argv[6],"print")==0)
    {
        printf("Matrix A:\n");
        printMatrix(N1, M1, A);
        printf("\nMatrix B:\n");
        printMatrix(N2, M2, B);

    }

    //  perform the operation requested
    if (strcmp(argv[5],"add")==0){
        double result[N1][M1];
        if (N1 != N2 || M1 != M2)
        {
            printf("Matrices A and B must have the same size to perform the operation.\n");
            return 1;
        }
        addMatrices(N1, M1, A, N2, M2, B, result);
        if (argc == 7 && strcmp(argv[6],"print")==0)
        {
            printf("\nResult of A+B:\n");
            printMatrix(N1, M1, result);
        }
        else
        {
            printf("Solved!!\n");
        }
    } 

    else if (strcmp(argv[5],"subtract")==0){
        double result[N1][M1];
        if (N1 != N2 || M1 != M2)
        {
            printf("Matrices A and B must have the same size to perform the operation.\n");
            return 1;
        }
        subtractMatrices(N1, M1, A, N2, M2, B, result);
        if (argc == 7 && strcmp(argv[6],"print")==0)
        {
            printf("\nResult of A-B:\n");
            printMatrix(N1, M1, result);
        }
        else
        {
            printf("Solved!!\n");
        }
    } 

    else if (strcmp(argv[5],"multiply")==0){
        double result[N1][M2];
        if (M1 != N2)
        {
            printf("Number of columns of A must be equal to the number of rows of B to perform the operation.\n");
            return 1;
        }
        multiplyMatrices(N1, M1, A, N2, M2, B, result);
        if (argc == 7 && strcmp(argv[6],"print")==0)
        {
            printf("\nResult of A*B:\n");
            printMatrix(N1, M2, result);
        }
        else
        {
            printf("Solved!!\n");
        }
    } 

    else if (strcmp(argv[5],"solve")==0){
        double result[N1][M2];
        if (M1 != N2 && M2 != 1)
        {
            printf("Number of columns of A must be equal to the number of rows of B to perform the operation.\n");
            printf("Number of columns of B must be equal to 1 to perform the operation.\n");
            return 1;
        }
        solveLinearSystem(N1, M1, A, N2, M2, B, result);
        if (argc == 7 && strcmp(argv[6],"print")==0)
        {
            printf("\nResult of x=B/A:\n");
            printMatrix(N1, M2, result);
        }
        else
        {
            printf("Solved!!\n");
        }
    }
    return 0;
}