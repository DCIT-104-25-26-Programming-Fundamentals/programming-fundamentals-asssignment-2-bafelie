// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
// =============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 10;

void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
}

void displayMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << setw(5) << mat[i][j];
        cout << endl;
    }
}


void transposeMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols,
                      int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[j][i] = mat[i][j];
}


void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                  int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = a[i][j] + b[i][j];
}


void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                       int result[MAX_SIZE][MAX_SIZE],
                       int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
}

int main() {
    int matA[MAX_SIZE][MAX_SIZE], matB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    
    cout << "--- Transpose ---\n";
    cout << "Enter number of rows: "; cin >> rows;
    cout << "Enter number of columns: "; cin >> cols;
    readMatrix(matA, rows, cols);

    cout << "\nOriginal Matrix:\n";
    displayMatrix(matA, rows, cols);

    transposeMatrix(matA, rows, cols, result);
    cout << "\nTransposed Matrix:\n";
    displayMatrix(result, cols, rows);

    
    cout << "\n--- Addition ---\n";
    cout << "Enter number of rows: "; cin >> rows;
    cout << "Enter number of columns: "; cin >> cols;

    cout << "Matrix A:\n";
    readMatrix(matA, rows, cols);
    cout << "Matrix B:\n";
    readMatrix(matB, rows, cols);

    addMatrices(matA, matB, result, rows, cols);
    cout << "\nSum (A + B):\n";
    displayMatrix(result, rows, cols);

    
    cout << "\n--- Multiplication ---\n";
    int rowsA, colsA, rowsB, colsB;
    cout << "Rows of A: "; cin >> rowsA;
    cout << "Columns of A: "; cin >> colsA;
    cout << "Rows of B (must equal columns of A): "; cin >> rowsB;
    cout << "Columns of B: "; cin >> colsB;

    if (rowsB != colsA) {
        cout << "Error: columns of A must equal rows of B.\n";
        return 0;
    }

    cout << "Matrix A:\n";
    readMatrix(matA, rowsA, colsA);
    cout << "Matrix B:\n";
    readMatrix(matB, rowsB, colsB);

    multiplyMatrices(matA, matB, result, rowsA, colsA, colsB);
    cout << "\nProduct (A x B):\n";
    displayMatrix(result, rowsA, colsB);

    return 0;
}

