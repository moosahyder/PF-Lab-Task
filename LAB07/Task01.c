
#include <stdio.h>

int main() {
    int a[3][3], trans[3][3], cof[3][3], adj[3][3];
    int temp[2][2];
    int i, j, row, col, r, c;
    int det;
    float inv[3][3];

    printf("Enter elements of 3x3 matrix:\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nOriginal Matrix:\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            trans[i][j] = a[j][i];
        }
    }

    printf("\nTranspose Matrix:\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", trans[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            r = 0;

            for (row = 0; row < 3; row++) {
                if (row != i) {
                    c = 0;

                    for (col = 0; col < 3; col++) {
                        if (col != j) {
                            temp[r][c] = a[row][col];
                            c++;
                        }
                    }
                    r++;
                }
            }

            cof[i][j] =
                temp[0][0] * temp[1][1]
                - temp[0][1] * temp[1][0];

            if ((i + j) % 2 != 0) {
                cof[i][j] = -cof[i][j];
            }
        }
    }

    printf("\nCofactor Matrix:\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", cof[i][j]);
        }
        printf("\n");
    }


    det = 0;

    for (j = 0; j < 3; j++) {
        det += a[0][j] * cof[0][j];
    }

    printf("\nDeterminant = %d\n", det);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            adj[i][j] = cof[j][i];
        }
    }

    printf("\nAdjoint Matrix:\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", adj[i][j]);
        }
        printf("\n");
    }

    if (det == 0) {
        printf("\nInverse does not exist because determinant is zero.\n");
    } else {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                inv[i][j] = (float) adj[i][j] / det;
            }
        }

        printf("\nInverse Matrix:\n");

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                printf("%.3f\t", inv[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
