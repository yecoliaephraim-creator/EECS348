#include <stdio.h>

#define SIZE 5

// Function prototypes
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]);
void printMatrix(const char *label, int matrix[SIZE][SIZE]);

int main() {

    // First matrix
    int m1[SIZE][SIZE] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };

    // Second matrix
    int m2[SIZE][SIZE] = {
        {25,24,23,22,21},
        {20,19,18,17,16},
        {15,14,13,12,11},
        {10,9,8,7,6},
        {5,4,3,2,1}
    };

    // Result matrices
    int sum[SIZE][SIZE];
    int product[SIZE][SIZE];
    int transpose[SIZE][SIZE];

    // Display original matrices
    printMatrix("Matrix 1:", m1);
    printMatrix("Matrix 2:", m2);

    // Add matrices
    addMatrices(m1, m2, sum);
    printMatrix("Sum of Matrix 1 and Matrix 2:", sum);

    // Multiply matrices
    multiplyMatrices(m1, m2, product);
    printMatrix("Product of Matrix 1 and Matrix 2:", product);

    // Transpose matrix 1
    transposeMatrix(m1, transpose);
    printMatrix("Transpose of Matrix 1:", transpose);

    return 0;
}

/*
Adds two matrices element-by-element and stores
the result in the result matrix.
*/
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {

    for (int i = 0; i < SIZE; i++) {

        for (int j = 0; j < SIZE; j++) {

            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

/*
Multiplies two matrices using the standard
row-by-column matrix multiplication method.
*/
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {

    for (int i = 0; i < SIZE; i++) {

        for (int j = 0; j < SIZE; j++) {

            result[i][j] = 0;

            // Multiply row of m1 by column of m2
            for (int k = 0; k < SIZE; k++) {

                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

/*
Creates the transpose of a matrix by swapping
rows and columns.
*/
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {

    for (int i = 0; i < SIZE; i++) {

        for (int j = 0; j < SIZE; j++) {

            result[j][i] = matrix[i][j];
        }
    }
}

/*
Prints a matrix in a readable table format.
*/
void printMatrix(const char *label, int matrix[SIZE][SIZE]) {

    printf("%s\n", label);

    for (int i = 0; i < SIZE; i++) {

        for (int j = 0; j < SIZE; j++) {

            printf("%5d", matrix[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}