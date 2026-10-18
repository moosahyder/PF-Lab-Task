#include <stdio.h>

int main() {
    int a[5][5], b[5][5];
    int rows, cols, rows2, cols2;
    int i, j, k;
    int zero, identity, diagonal, scalar;
    int upper, lower, symmetric, skew;
    int rowMatrix, columnMatrix;
    int idempotent, nilpotent;
    int equal, singular, determinant;
    int product[5][5];
    int power[5][5];
    int temp[5][5];
    int isNilpotent;
    int count;
    int det;
    int sign;
    int x, y, z, w, v;
    int permutation[5];
    int used[5];
    int productValue;
    int determinantSum;
    int determinantTerm;
    int swap;
    int found;
    int m;

    printf("Enter number of rows (1-5): ");
    scanf("%d", &rows);

    printf("Enter number of columns (1-5): ");
    scanf("%d", &cols);

    if (rows < 1 || rows > 5 || cols < 1 || cols > 5) {
        printf("Invalid matrix size.\n");
        return 0;
    }

    printf("Enter elements of the first matrix:\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nFirst Matrix:\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    // 1. Square Matrix
    if (rows == cols) {
        printf("1. Square Matrix\n");
    }

    // 2. Rectangular Matrix
    if (rows != cols) {
        printf("2. Rectangular Matrix\n");
    }

    // 3. Zero Matrix and 15. Null Matrix
    zero = 1;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (a[i][j] != 0) {
                zero = 0;
            }
        }
    }

    if (zero == 1) {
        printf("3. Zero Matrix\n");
        printf("15. Null Matrix\n");
    }

    // 4. Identity Matrix
    identity = 1;

    if (rows != cols) {
        identity = 0;
    }

    if (rows == cols) {
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                if (i == j && a[i][j] != 1) {
                    identity = 0;
                }

                if (i != j && a[i][j] != 0) {
                    identity = 0;
                }
            }
        }
    }

    if (identity == 1) {
        printf("4. Identity Matrix\n");
    }

    // 5. Diagonal Matrix
    diagonal = 1;

    if (rows != cols) {
        diagonal = 0;
    }

    if (rows == cols) {
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                if (i != j && a[i][j] != 0) {
                    diagonal = 0;
                }
            }
        }
    }

    if (diagonal == 1) {
        printf("5. Diagonal Matrix\n");
    }

    // 6. Scalar Matrix
    scalar = 1;

    if (rows != cols) {
        scalar = 0;
    }

    if (rows == cols) {
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                if (i != j && a[i][j] != 0) {
                    scalar = 0;
                }
            }
        }

        for (i = 1; i < rows; i++) {
            if (a[i][i] != a[0][0]) {
                scalar = 0;
            }
        }
    }

    if (scalar == 1) {
        printf("6. Scalar Matrix\n");
    }

    // 7. Upper Triangular Matrix
    upper = 1;

    if (rows != cols) {
        upper = 0;
    }

    if (rows == cols) {
        for (i = 1; i < rows; i++) {
            for (j = 0; j < i; j++) {
                if (a[i][j] != 0) {
                    upper = 0;
                }
            }
        }
    }

    if (upper == 1) {
        printf("7. Upper Triangular Matrix\n");
    }

    // 8. Lower Triangular Matrix
    lower = 1;

    if (rows != cols) {
        lower = 0;
    }

    if (rows == cols) {
        for (i = 0; i < rows; i++) {
            for (j = i + 1; j < cols; j++) {
                if (a[i][j] != 0) {
                    lower = 0;
                }
            }
        }
    }

    if (lower == 1) {
        printf("8. Lower Triangular Matrix\n");
    }

    // 9. Symmetric Matrix
    symmetric = 1;

    if (rows != cols) {
        symmetric = 0;
    }

    if (rows == cols) {
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                if (a[i][j] != a[j][i]) {
                    symmetric = 0;
                }
            }
        }
    }

    if (symmetric == 1) {
        printf("9. Symmetric Matrix\n");
    }

    // 10. Skew-Symmetric Matrix
    skew = 1;

    if (rows != cols) {
        skew = 0;
    }

    if (rows == cols) {
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                if (a[i][j] != -a[j][i]) {
                    skew = 0;
                }
            }
        }
    }

    if (skew == 1) {
        printf("10. Skew-Symmetric Matrix\n");
    }

    // 11. Singular or Non-Singular Matrix
    if (rows == cols) {
        determinantSum = 0;

        for (x = 0; x < rows; x++) {
            for (y = 0; y < rows; y++) {
                for (z = 0; z < rows; z++) {
                    for (w = 0; w < rows; w++) {
                        for (v = 0; v < rows; v++) {

                            if (x == y || x == z || x == w || x == v ||
                                y == z || y == w || y == v ||
                                z == w || z == v || w == v) {
                                continue;
                            }

                            permutation[0] = x;
                            permutation[1] = y;
                            permutation[2] = z;
                            permutation[3] = w;
                            permutation[4] = v;

                            used[0] = 0;
                            used[1] = 0;
                            used[2] = 0;
                            used[3] = 0;
                            used[4] = 0;

                            count = 0;

                            for (i = 0; i < rows; i++) {
                                for (j = i + 1; j < rows; j++) {
                                    if (permutation[i] > permutation[j]) {
                                        count++;
                                    }
                                }
                            }

                            sign = 1;

                            if (count % 2 != 0) {
                                sign = -1;
                            }

                            determinantTerm = sign;

                            for (i = 0; i < rows; i++) {
                                determinantTerm =
                                    determinantTerm * a[i][permutation[i]];
                            }

                            determinantSum =
                                determinantSum + determinantTerm;
                        }
                    }
                }
            }
        }

        if (determinantSum == 0) {
            printf("11. Singular Matrix\n");
        }

        if (determinantSum != 0) {
            printf("11. Non-Singular Matrix\n");
        }
    }

    // 12. Equal Matrix
    printf("\nEnter rows and columns of the second matrix:\n");
    scanf("%d %d", &rows2, &cols2);

    if (rows2 < 1 || rows2 > 5 || cols2 < 1 || cols2 > 5) {
        printf("Invalid second matrix size.\n");
        return 0;
    }

    printf("Enter elements of the second matrix:\n");

    for (i = 0; i < rows2; i++) {
        for (j = 0; j < cols2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    equal = 1;

    if (rows != rows2 || cols != cols2) {
        equal = 0;
    }

    if (rows == rows2 && cols == cols2) {
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                if (a[i][j] != b[i][j]) {
                    equal = 0;
                }
            }
        }
    }

    if (equal == 1) {
        printf("12. Both matrices are Equal\n");
    }

    if (equal == 0) {
        printf("12. Both matrices are Not Equal\n");
    }

    // 13. Row Matrix
    if (rows == 1) {
        printf("13. Row Matrix\n");
    }

    // 14. Column Matrix
    if (cols == 1) {
        printf("14. Column Matrix\n");
    }

    // 16. Idempotent Matrix (A * A = A)
    idempotent = 1;

    if (rows != cols) {
        idempotent = 0;
    }

    if (rows == cols) {
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                product[i][j] = 0;

                for (k = 0; k < rows; k++) {
                    product[i][j] =
                        product[i][j] + a[i][k] * a[k][j];
                }
            }
        }

        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                if (product[i][j] != a[i][j]) {
                    idempotent = 0;
                }
            }
        }
    }

    if (idempotent == 1) {
        printf("16. Idempotent Matrix\n");
    }

    // 17. Nilpotent Matrix
    nilpotent = 0;

    if (rows == cols) {
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                power[i][j] = a[i][j];
            }
        }

        for (m = 2; m <= rows; m++) {
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    temp[i][j] = 0;

                    for (k = 0; k < rows; k++) {
                        temp[i][j] =
                            temp[i][j] + power[i][k] * a[k][j];
                    }
                }
            }

            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    power[i][j] = temp[i][j];
                }
            }

            isNilpotent = 1;

            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    if (power[i][j] != 0) {
                        isNilpotent = 0;
                    }
                }
            }

            if (isNilpotent == 1) {
                nilpotent = 1;
            }
        }
    }

    if (nilpotent == 1) {
        printf("17. Nilpotent Matrix\n");
    }

    return 0;
}