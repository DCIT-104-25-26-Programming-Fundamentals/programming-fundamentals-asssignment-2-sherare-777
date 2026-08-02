#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 10;

// Function to display a matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Part A — Transpose a Matrix
void transposeMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int transpose[MAX][MAX];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    cout << "\nTransposed Matrix:\n";
    displayMatrix(transpose, cols, rows);
}

// Part B — Add Two Matrices
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int rows, int cols) {
    int sum[MAX][MAX];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }
    cout << "\nSum of Matrices:\n";
    displayMatrix(sum, rows, cols);
}

// Part C — Multiply Two Matrices
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int rowsA, int colsA, int colsB) {
    int product[MAX][MAX] = {0};
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                product[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << "\nProduct of Matrices:\n";
    displayMatrix(product, rowsA, colsB);
}

int main() {
    int matrixA[MAX][MAX], matrixB[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;

    // Part A — Transpose
    cout << "=== Part A: Transpose ===\n";
    cout << "Enter rows: "; cin >> rowsA;
    cout << "Enter cols: "; cin >> colsA;
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrixA[i][j];
        }
    }
    cout << "\nOriginal Matrix:\n";
    displayMatrix(matrixA, rowsA, colsA);
    transposeMatrix(matrixA, rowsA, colsA);

    // Part B — Addition
    cout << "\n=== Part B: Addition ===\n";
    cout << "Enter rows: "; cin >> rowsA;
    cout << "Enter cols: "; cin >> colsA;
    cout << "Enter elements for Matrix A:\n";
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            cin >> matrixA[i][j];
        }
    }
    cout << "Enter elements for Matrix B:\n";
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            cin >> matrixB[i][j];
        }
    }
    addMatrices(matrixA, matrixB, rowsA, colsA);

    // Part C — Multiplication
    cout << "\n=== Part C: Multiplication ===\n";
    cout << "Enter rows for Matrix A: "; cin >> rowsA;
    cout << "Enter cols for Matrix A: "; cin >> colsA;
    cout << "Enter elements for Matrix A:\n";
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            cin >> matrixA[i][j];
        }
    }

    cout << "Enter rows for Matrix B: "; cin >> rowsB;
    cout << "Enter cols for Matrix B: "; cin >> colsB;
    if (colsA != rowsB) {
        cout << "Matrix multiplication not possible (colsA != rowsB).\n";
        return 0;
    }
    cout << "Enter elements for Matrix B:\n";
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            cin >> matrixB[i][j];
        }
    }
    multiplyMatrices(matrixA, matrixB, rowsA, colsA, colsB);

    return 0;
}
