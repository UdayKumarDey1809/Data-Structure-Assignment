#include <stdio.h>

void inputMatrix(int mat[10][10], int rows, int cols) {
    printf("Enter elements of %d x %d matrix:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}
void displayMatrix(int mat[10][10], int rows, int cols) {
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}
void multiplyMatrix(int mat1[10][10], int mat2[10][10], int result[10][10],
                    int r1, int c1, int r2, int c2) {
    if (c1 != r2) {
        printf("Matrix multiplication not possible! (Columns of first != Rows of second)\n");
        return;
    }
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int mat1[10][10], mat2[10][10], result[10][10];
    int r1, c1, r2, c2;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    inputMatrix(mat1, r1, c1);
    inputMatrix(mat2, r2, c2);

    displayMatrix(mat1, r1, c1);
    displayMatrix(mat2, r2, c2);

    multiplyMatrix(mat1, mat2, result, r1, c1, r2, c2);

    if (c1 == r2) {
        displayMatrix(result, r1, c2);
    }

    return 0;
}