#include <stdio.h>

#define N 3

void multiply(int A[][N], int B[][N], int C[][N])
{
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            C[i][j] = 0;
            for (k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main()
{
    int A[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[N][N] = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};
    int C[N][N];

    multiply(A, B, C);

    int i, j;
    printf("Result matrix is: \n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
