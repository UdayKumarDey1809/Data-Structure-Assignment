#include <stdio.h>

#define SIZE 4

void inputMatrix(int mat[SIZE][SIZE]) {
    printf("Enter elements of 4x4 matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void displayMatrix(int mat[SIZE][SIZE]) {
    printf("Matrix (4x4):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int isSparse(int mat[SIZE][SIZE]) {
    int zeroCount = 0;
    int total = SIZE * SIZE;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (mat[i][j] == 0) {
                zeroCount++;
            }
        }
    }
    return (zeroCount > total / 2);
}

void storeNonZero(int mat[SIZE][SIZE], int alt[SIZE][3], int *count) {
    *count = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (mat[i][j] != 0) {
                alt[*count][0] = i;
                alt[*count][1] = j;
                alt[*count][2] = mat[i][j];
                (*count)++;
            }
        }
    }
}

void displayAlternate(int alt[SIZE][3], int count) {
    printf("Alternate matrix (row, col, value):\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t%d\n", alt[i][0], alt[i][1], alt[i][2]);
    }
}

int main() {
    int mat[SIZE][SIZE];
    int alt[SIZE * SIZE][3];
    int count;

    inputMatrix(mat);

    displayMatrix(mat);

    if (isSparse(mat)) {
        printf("Matrix is sparse.\n");
        storeNonZero(mat, alt, &count);
        displayAlternate(alt, count);
    } else {
        printf("Matrix is not sparse.\n");
    }

    return 0;
}