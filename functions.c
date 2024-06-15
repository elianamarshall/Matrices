#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "functions.h"

//function to generate a random matrix
void generateMatrix(int rows, int cols, double matrix[rows][cols]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = ((rand() % 21) - 10); //generates a random integer between -10 and 10 inclusive and assigns it to the current element of a matrix
        }
    } 
}

//function to print a matrix
void printMatrix(int rows, int cols, double matrix[rows][cols]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%f ", matrix[i][j]); //prints each element of the matrix
        }
        printf("\n");
    }
}

//function to add two matrices
void addMatrices(int N1, int M1, double A[N1][M1], int N2, int M2, double B[N2][M2], double result[N1][M1]) {
    for(int i = 0; i < N1; i++) {
        for(int j = 0; j < M1; j++) {
            result[i][j] = A[i][j] + B[i][j]; //adds the corresponding element of matrix B to matrix A
        }
    }
}

//function to subtract two matrices
void subtractMatrices(int N1, int M1, double A[N1][M1], int N2, int M2, double B[N2][M2], double result[N1][M1]) {
    for(int i = 0; i < N1; i++) {
        for(int j = 0; j < M1; j++) {
            result[i][j] = A[i][j] - B[i][j]; //subtracts the corresponding element of matrix B from matrix A
        }
    }
}

//function to multiply two matrices
void multiplyMatrices(int N1, int M1, double A[N1][M1], int N2, int M2, double B[N2][M2], double result[N1][M2]) {
    for(int i = 0; i < N1; i++) {
        for(int j = 0; j < M2; j++) {
            result[i][j] = 0; //initializes the result matrix
            for(int k = 0; k < N2; k++) {
                result[i][j] += A[i][k] * B[k][j]; //multiplies the corresponding elements of row i of matrix A and column j of matrix B, then adds the products to the current value of result[i][j]
            }
        }
    }
}

//function to solve a system of linear equations
void solveLinearSystem(int N1, int M1, double A[N1][M1], int N2, int M2, double B[N2][M2], double x[N1][M2]) {
    //Gaussian elimination
    for(int i = 0; i < N1; i++) {
        int maxRow = i; //pivot row
        for(int k = i + 1; k < N1; k++) {
            if(fabs(A[k][i]) > fabs(A[maxRow][i])) { //checks if the absolute value of A[k][i] is greater than the current maximum
                maxRow = k; //updates the index of the row with the maximum absolute value
            }
        }
        //swaps the current row with the pivot row
        if(maxRow != i) {
            for(int j = 0; j < M1; j++) {
                double swap = A[i][j]; //stores the current element of A
                A[i][j] = A[maxRow][j]; //replaces the current element of A with the corresponding element from the pivot row
                A[maxRow][j] = swap; //replaces the corresponding element of the pivot row with the stored element
            }
            for(int j = 0; j < M2; j++) {
                double swap = B[i][j]; //stores the current element of B
                B[i][j] = B[maxRow][j]; //replaces the current element of B with the corresponding element from the pivot row
                B[maxRow][j] = swap; //replaces the corresponding element of the pivot row with the stored element
            }
        }
        //forward elimination
        for(int k = i + 1; k < N1; k++) {
            double factor = A[k][i] / A[i][i]; //calculates the factor to multiply the pivot row by in order to eliminate A[k][i]
            for(int j = i; j < M1; j++) {
                A[k][j] -= factor * A[i][j]; //subtracts the factor times the pivot row from the current row to eliminate A[k][i]
            }
            for(int j = 0; j < M2; j++) {
                B[k][j] -= factor * B[i][j]; //subtracts the factor times the pivot row from the corresponding element of B
            }
        }
    }
    //back substitution
    for(int i = N1 - 1; i >= 0; i--) {
        for(int j = 0; j < M2; j++) {
            x[i][j] = B[i][j];
            for(int k = i + 1; k < N1; k++) {
                x[i][j] -= A[i][k] * x[k][j]; //subtracts the elements of known part of the solution from x[i][j]
            }
            x[i][j] /= A[i][i]; //divides by the coefficient of the unknown to find its value
        }
    }
}