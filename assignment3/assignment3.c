#include <stdio.h>
#include<stdlib.h>
#define MAX_MatrixS 100

typedef struct {
    int row;
    int col;
    int value;
} Matrix;

void addSparseMatrices(Matrix A[], Matrix B[], int m, int n, Matrix C[]) {
    int aPos = 0, bPos = 0, cPos = 0;
    while (aPos < m || bPos < n) {
        if (aPos >= m) {
            C[cPos++] = B[bPos++];
        } else if (bPos >= n) {
            C[cPos++] = A[aPos++];
        } else {
            if (A[aPos].row < B[bPos].row || (A[aPos].row == B[bPos].row && A[aPos].col < B[bPos].col)) {
                C[cPos++] = A[aPos++];
            } else if (A[aPos].row > B[bPos].row || (A[aPos].row == B[bPos].row && A[aPos].col > B[bPos].col)) {
                C[cPos++] = B[bPos++];
            } else {
                C[cPos].row = A[aPos].row;
                C[cPos].col = A[aPos].col;
                C[cPos++].value = A[aPos++].value + B[bPos++].value;
            }
        }
    }
}

void subtractSparseMatrices(Matrix A[], Matrix B[], int m, int n, Matrix C[]) {
    int aPos = 0, bPos = 0, cPos = 0;
    while (aPos < m || bPos < n) {
        if (aPos >= m) {
            C[cPos++] = B[bPos++];
        } else if (bPos >= n) {
            C[cPos++] = A[aPos++];
        } else {
            if (A[aPos].row < B[bPos].row || (A[aPos].row == B[bPos].row && A[aPos].col < B[bPos].col)) {
                C[cPos++] = A[aPos++];
            } else if (A[aPos].row > B[bPos].row || (A[aPos].row == B[bPos].row && A[aPos].col > B[bPos].col)) {
                C[cPos++] = B[bPos++];
            } else {
                C[cPos].row = A[aPos].row;
                C[cPos].col = A[aPos].col;
                C[cPos++].value = A[aPos++].value - B[bPos++].value;
            }
        }
    }
}

void multiplySparseMatrices(Matrix A[], Matrix B[], int m, int n, int p, Matrix C[]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i * p + j].row = i;
            C[i * p + j].col = j;
            C[i * p + j].value = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < p; k++) {
                C[i * p + k].value += A[i * n + j].value * B[j * p + k].value;
            }
        }
    }
}
void powerSparseMatrix(Matrix A[], int m, int n, int exponent, Matrix result[]) {
    if (exponent == 0) {
        for (int i = 0; i < m; i++) {
            result[i].row = A[i].row;
            result[i].col = A[i].col;
            result[i].value = (A[i].row == A[i].col) ? 1 : 0;
        }
    } else if (exponent == 1) {
        // A^1 = A
        for (int i = 0; i < m; i++) {
            result[i] = A[i];
        }
    } else {
        Matrix *temp = (Matrix *)malloc(MAX_MatrixS * sizeof(Matrix));
        if (temp == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        powerSparseMatrix(A, m, n, exponent - 1, temp);
        multiplySparseMatrices(A, temp, m, n, n, result);

        free(temp);
    }
}


int main() {
    int m, n, x, y, p;
    printf("Enter the number of non-zero elements in A: ");
    scanf("%d", &m);
    Matrix A[MAX_MatrixS];
    printf("Enter the elements of A (row col value):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &A[i].row, &A[i].col, &A[i].value);
    }

    printf("Enter the number of non-zero elements in B: ");
    scanf("%d", &n);
    Matrix B[MAX_MatrixS];
    printf("Enter the elements of B (row col value):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &B[i].row, &B[i].col, &B[i].value);
    }

    printf("Choose the operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Calculate (A[k][3])^n\n");
    int choice;
    scanf("%d", &choice);

    Matrix result[MAX_MatrixS];

    switch (choice) {
        case 1:
            addSparseMatrices(A, B, m, n, result);
            printf("Resultant Sparse Matrix (row col value):\n");
            for (int i = 0; i < m + n; i++) {
                printf("%d %d %d\n", result[i].row, result[i].col, result[i].value);
            }
            break;
        case 2:
            subtractSparseMatrices(A, B, m, n, result);
            printf("Resultant Sparse Matrix (row col value):\n");
            for (int i = 0; i < m + n; i++) {
                printf("%d %d %d\n", result[i].row, result[i].col, result[i].value);
            }
            break;
        case 3:
            printf("Enter the number of columns in matrix B: ");
            scanf("%d", &p);
            multiplySparseMatrices(A, B, m, n, p, result);
            printf("Resultant Sparse Matrix (row col value):\n");
            for (int i = 0; i < m * p; i++) {
                printf("%d %d %d\n", result[i].row, result[i].col, result[i].value);
            }
            break;
        case 4:
            printf("Enter the exponent (n) for (A[k][3])^n: ");
            int exponent;
            scanf("%d", &exponent);
            powerSparseMatrix(A, m, 3, exponent, result);
            printf("Resultant Sparse Matrix (row col value):\n");
            for (int i = 0; i < m; i++) {
                printf("%d %d %d\n", result[i].row, result[i].col, result[i].value);
            }
            break;
        default:
            printf("Invalid choice\n");    
        
    }

    return 0;
}
