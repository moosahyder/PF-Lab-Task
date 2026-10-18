#include <stdio.h>

int main() {
    int a[3][3], b[3][3], result[3][3];
    int r1, c1, r2, c2;
    int i, j, k;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (r1 < 1 || r1 > 3 || c1 < 1 || c1 > 3 ||
        r2 < 1 || r2 > 3 || c2 < 1 || c2 > 3) {
        printf("Invalid dimensions! Maximum size is 3x3.\n");
    }
    else {
        if (c1 != r2) {
            printf("Matrix multiplication is not possible.\n");
            printf("Columns of first matrix must equal rows of second matrix.\n");
        }
        else {
            printf("\nEnter elements of first matrix:\n");

            for (i = 0; i < r1; i++) {
                for (j = 0; j < c1; j++) {
                    scanf("%d", &a[i][j]);
                }
            }

            printf("\nEnter elements of second matrix:\n");

            for (i = 0; i < r2; i++) {
                for (j = 0; j < c2; j++) {
                    scanf("%d", &b[i][j]);
                }
            }

            printf("\nFirst Matrix:\n");

            for (i = 0; i < r1; i++) {
                for (j = 0; j < c1; j++) {
                    printf("%d\t", a[i][j]);
                }
                printf("\n");
            }

            printf("\nSecond Matrix:\n");

            for (i = 0; i < r2; i++) {
                for (j = 0; j < c2; j++) {
                    printf("%d\t", b[i][j]);
                }
                printf("\n");
            }

            for (i = 0; i < r1; i++) {
                for (j = 0; j < c2; j++) {
                    result[i][j] = 0;

                    for (k = 0; k < c1; k++) {
                        result[i][j] = result[i][j]
                                     + a[i][k] * b[k][j];
                    }
                }
            }

            printf("\nResult of Matrix Multiplication:\n");

            for (i = 0; i < r1; i++) {
                for (j = 0; j < c2; j++) {
                    printf("%d\t", result[i][j]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}