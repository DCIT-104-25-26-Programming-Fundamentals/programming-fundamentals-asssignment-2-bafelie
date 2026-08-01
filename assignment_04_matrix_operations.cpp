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

using namespace std;
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 10;

// Reads an M x N matrix from the user, element by element
void readMatrix(int matrix[MAX][MAX], int rows, int cols, string name) {
    cout << "\nEnter elements for matrix " << name << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Displays a matrix in a neat, aligned grid
void displayMatrix(int matrix[MAX][MAX], int rows, int cols, string label) {
    cout << "\n" << label << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// PART A: Transpose an M x N matrix into an N x M result
void transposeMatrix(int matrix[MAX][MAX], int rows, int cols, int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// PART B: Element-wise addition of two M x N matrices
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int rows, int cols, int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// PART C: Multiply an M x N matrix A by an N x P matrix B, producing an M x P result
void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int m, int n, int p, int result[MAX][MAX]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int matA[MAX][MAX], matB[MAX][MAX], result[MAX][MAX];
    int choice;

    cout << "Matrix Operations Menu:\n";
    cout << "1. Transpose a Matrix\n";
    cout << "2. Add Two Matrices\n";
    cout << "3. Multiply Two Matrices\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        int rows, cols;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        readMatrix(matA, rows, cols, "A");
        displayMatrix(matA, rows, cols, "Original Matrix");

        transposeMatrix(matA, rows, cols, result);
        displayMatrix(result, cols, rows, "Transposed Matrix");

    } else if (choice == 2) {
        int rows, cols;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        readMatrix(matA, rows, cols, "A");
        readMatrix(matB, rows, cols, "B");

        displayMatrix(matA, rows, cols, "Matrix A");
        displayMatrix(matB, rows, cols, "Matrix B");

        addMatrices(matA, matB, rows, cols, result);
        displayMatrix(result, rows, cols, "Sum Matrix");

    } else if (choice == 3) {
        int m, n, n2, p;
        cout << "Enter rows of Matrix A (M): ";
        cin >> m;
        cout << "Enter columns of Matrix A (N): ";
        cin >> n;
        readMatrix(matA, m, n, "A");

        cout << "Enter rows of Matrix B (must equal N = " << n << "): ";
        cin >> n2;
        cout << "Enter columns of Matrix B (P): ";
        cin >> p;

        if (n2 != n) {
            cout << "Error: Columns of A must equal rows of B.\n";
            return 1;
        }

        readMatrix(matB, n2, p, "B");

        displayMatrix(matA, m, n, "Matrix A");
        displayMatrix(matB, n2, p, "Matrix B");

        multiplyMatrices(matA, matB, m, n, p, result);
        displayMatrix(result, m, p, "Product Matrix (A x B)");

    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}

