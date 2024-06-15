#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));

    int N1 = atoi(argv[1]);
    int M1 = atoi(argv[2]);
    int N2 = atoi(argv[3]);
    int M2 = atoi(argv[4]);
    double A[N1][M1];
    double B[N2][M2];
    double result[N1][M1];

    //checks if the number of arguments are correct
    if (argc < 6 || argc > 7) {
        printf("Usage: %s nrows_A ncols_A nrows_B ncols_B <operation> [print]\n", argv[0]);
        return 1;
    }

    //generates and prints matrix A
    generateMatrix(N1, M1, A);
    printf("Matrix A: \n");
    printMatrix(N1, M1, A);

    //generates and print matrix B
    generateMatrix(N2, M2, B);
    printf("\nMatrix B: \n");
    printMatrix(N2, M2, B);

    if (strcmp(argv[5], "add") == 0) { //checks if the operation specified in argv[5] is "add"
        if (N1 == N2 && M1 == M2) { //checks if the dimensions of matrix A and matrix B are the same
            addMatrices(N1, M1, A, N2, M2, B, result);
            if (strcmp(argv[6], "print") == 0) { //checks if the user wants to print the results
                printf("\nResult of A + B: \n");
                printMatrix(N1, M1, result);
            }
        }
        else
            printf("\nDimensions are incompatible. \n");
    }

    if (strcmp(argv[5], "subtract") == 0) { //checks if the operation specified in argv[5] is "subtract"
        if (N1 == N2 && M1 == M2) { //checks if the dimensions of matrix A and matrix B are the same
            subtractMatrices(N1, M1, A, N2, M2, B, result);
            if (strcmp(argv[6], "print") == 0) { //checks if the user wants to print the results
                printf("\nResult of A - B: \n");
                printMatrix(N1, M1, result);
            }
        }
        else
            printf("\nDimensions are incompatible. \n");
    }

    if (strcmp(argv[5], "multiply") == 0) { //checks if the operation specified in argv[5] is "multiply"
        if (M1 == N2) { //checks if the number of columns of matrix A is the same as the number of rows of matrix B
            multiplyMatrices(N1, M1, A, N2, M2, B, result);
            if (strcmp(argv[6], "print") == 0) { //checks if the user wants to print the results
                printf("\nResult of A * B: \n");
                printMatrix(N1, M1, result);
            }
        }
        else
            printf("\nDimensions are incompatible. \n");
    }

    if (strcmp(argv[5], "solve") == 0) { //checks if the operation specified in argv[5] is "solve"
        if (N1 == M1 && N2 == N1 && M2 == 1) { //checks if matrix A is square, matrix B has the same number of rows as matrix A, and if matrix B has only one column
            solveLinearSystem(N1, M1, A, N2, M2, B, result);
            if (strcmp(argv[6], "print") == 0) { //checks if the user wants to print the results
                printf("\nResult of x=B/A: \n");
                printMatrix(N2, 1, result); 
            }
        }
        else
            printf("\nDimensions are incompatible. \n");
    }

    return 0;
}