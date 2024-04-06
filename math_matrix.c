// include necessary library(s)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) 
{
    // Seed the random number generator
    srand(time(NULL));

    //Check if the number of arguments is correct
    if (argc < 6 || argc > 7) {
        printf("Usage: %s nrows_A ncols_A nrows_B ncols_B <operation> [print]\n", argv[0]);
        return 1;
    }

    int N1 = atoi(argv[1]);
    int M1 = atoi(argv[2]);
    int N2 = atoi(argv[3]);
    int M2 = atoi(argv[4]);

    // Generate random matrices A with size N1*M1 and B with size N2*M24
    double **A = NULL;
    double **B = NULL;
    A = malloc(N1 * sizeof(double *));
    B = malloc(N2 * sizeof(double *));


    for (int i = 0; i < N1; i++)
    {
        A[i] = malloc(M1 * sizeof(double));
    }

    for (int i = 0; i < N2; i++)
    {
        B[i] = malloc(M2 * sizeof(double));
    }

    if (A == NULL || B == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }


    generateMatrix(N1, M1, A);
    generateMatrix(N2, M2, B);

    //call the functions as needed
    
     //print the matrices if the last argument is "print"
    if (argc == 7 && strcmp(argv[6],"print")==0)
    {
        printf("Matrix A:\n");
        printMatrix(N1, M1, A);
        printf("\nMatrix B:\n");
        printMatrix(N2, M2, B);

    }

    //  perform the operation requested
    if (strcmp(argv[5],"add")==0){
        double **result = NULL;
        result = malloc(N1 * sizeof(double *));
        for (int i = 0; i < N1; i++)
        {
            result[i] = malloc(M1 * sizeof(double));
        }

        if (result == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }

        if (N1 != N2 || M1 != M2)
        {
            printf("Matrices A and B must have the same size to perform the operation.\n");
            return 1;
        }

        clock_t start = clock();
        addMatrices(N1, M1, A, N2, M2, B, result);
        clock_t end = clock();
        double taken_time = (double)(end - start) / CLOCKS_PER_SEC;
    
        if (argc == 7 && strcmp(argv[6],"print")==0)
        {
            printf("\nResult of A+B:\n");
            printMatrix(N1, M1, result);
        }
        else
        {
            printf("Solved!!\n");
        }
        printf("Time taken: %f seconds\n", taken_time);
        deallocateMatrix(N1, result);
    } 

    else if (strcmp(argv[5],"subtract")==0){
        double **result = NULL;
        result = malloc(N1 * sizeof(double *));
        for (int i = 0; i < N1; i++)
        {
            result[i] = malloc(M1 * sizeof(double));
        }

        if (result == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }

        if (N1 != N2 || M1 != M2)
        {
            printf("Matrices A and B must have the same size to perform the operation.\n");
            return 1;
        }

        clock_t start = clock();
        subtractMatrices(N1, M1, A, N2, M2, B, result);
        clock_t end = clock();
        double taken_time = (double)(end - start) / CLOCKS_PER_SEC;

        if (argc == 7 && strcmp(argv[6],"print")==0)
        {
            printf("\nResult of A-B:\n");
            printMatrix(N1, M1, result);
        }
        else
        {
            printf("Solved!!\n");
        }
        deallocateMatrix(N1, result);  
    } 

    else if (strcmp(argv[5],"multiply")==0){
        double **result = NULL;
        result = malloc(N1 * sizeof(double *));
        for (int i = 0; i < N1; i++)
        {
            result[i] = malloc(M2 * sizeof(double));
        }

        if (result == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }
        if (M1 != N2)
        {
            printf("Number of columns of A must be equal to the number of rows of B to perform the operation.\n");
            return 1;
        }
        
        clock_t start = clock();
        multiplyMatrices(N1, M1, A, N2, M2, B, result);
        clock_t end = clock();
        double taken_time = (double)(end - start) / CLOCKS_PER_SEC;
        
        if (argc == 7 && strcmp(argv[6],"print")==0)
        {
            printf("\nResult of A*B:\n");
            printMatrix(N1, M2, result);
        }
        else
        {
            printf("Solved!!\n");
        }
        printf("Time taken: %f seconds\n", taken_time);
        deallocateMatrix(N1, result);
    } 

    else if (strcmp(argv[5],"solve")==0){
        double **result = NULL;
        result = malloc(N1 * sizeof(double *));
        for (int i = 0; i < N1; i++)
        {
            result[i] = malloc(M2 * sizeof(double));
        }

        if (result == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }
        if (M1 != N2 && M2 != 1)
        {
            printf("Number of columns of A must be equal to the number of rows of B to perform the operation.\n");
            printf("Number of columns of B must be equal to 1 to perform the operation.\n");
            return 1;
        }
        
        clock_t start = clock();
        solveLinearSystem(N1, M1, A, N2, M2, B, result);
        clock_t end = clock();
        double taken_time = (double)(end - start) / CLOCKS_PER_SEC;
        
        if (argc == 7 && strcmp(argv[6],"print")==0)
        {
            printf("\nResult of x=B/A:\n");
            printMatrix(N1, M2, result);
        }
        else
        {
            printf("Solved!!\n");
        }
        printf("Time taken: %f seconds\n", taken_time);
        deallocateMatrix(N1, result);
    }

    deallocateMatrix(N1, A);
    deallocateMatrix(N2, B);
    return 0;
}