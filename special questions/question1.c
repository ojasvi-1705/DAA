//Given an n x n matrix, rotate it by 90 degrees clockwise in place without using extra memory.
#include <stdio.h>

#define N 4   // Example size, but this works for any N

void rotate90Clockwise(int matrix[N][N]) {
    int i, j;

    // Step 1: Transpose (across the main diagonal)
    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Step 2: Reverse each row
    for (i = 0; i < N; i++) {
        for (j = 0; j < N / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][N - 1 - j];
            matrix[i][N - 1 - j] = temp;
        }
    }
}

void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[N][N] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13,14, 15,16}
    };

    printf("Original Matrix:\n");
    printMatrix(matrix);

    rotate90Clockwise(matrix);

    printf("\nRotated Matrix (90 degrees clockwise):\n");
    printMatrix(matrix);

    return 0;
}
