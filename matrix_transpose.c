#include <stdio.h>

void inputMatrix(int mat[10][10], int n) {
    printf("Enter elements of %d x %d matrix:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void displayMatrix(int mat[10][10], int n) {
    printf("Matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int mat[10][10], int n) {
    printf("Transpose of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", mat[j][i]);
        }
        printf("\n");
    }
}

int main() {
    int mat[10][10];
    int n;

    printf("Enter size of square matrix (n x n): ");
    scanf("%d", &n);

    inputMatrix(mat, n);

    displayMatrix(mat, n);

    transposeMatrix(mat, n);

    return 0;
}