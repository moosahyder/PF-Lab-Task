#include <stdio.h>

int main() {
    int a[3][3][3];
    int i, j, k;
    int layerTotal;
    int overallTotal = 0;
    int largest, smallest;
    float average;

    printf("Enter 27 elements of the 3D array:\n");

    for (i = 0; i < 3; i++) {
        printf("\nEnter elements for Layer %d:\n", i + 1);

        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                scanf("%d", &a[i][j][k]);
            }
        }
    }

    largest = a[0][0][0];
    smallest = a[0][0][0];

    printf("\n--- Layer Analysis ---\n");

    for (i = 0; i < 3; i++) {
        layerTotal = 0;

        printf("\nLayer %d:\n", i + 1);

        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                printf("%d\t", a[i][j][k]);

                layerTotal = layerTotal + a[i][j][k];
                overallTotal = overallTotal + a[i][j][k];

                if (a[i][j][k] > largest) {
                    largest = a[i][j][k];
                }

                if (a[i][j][k] < smallest) {
                    smallest = a[i][j][k];
                }
            }

            printf("\n");
        }

        printf("Total of Layer %d = %d\n", i + 1, layerTotal);
    }

    average = overallTotal / 27.0;

    printf("\n--- Overall Data Analysis ---\n");
    printf("Overall Total = %d\n", overallTotal);
    printf("Overall Average = %.2f\n", average);
    printf("Largest Element = %d\n", largest);
    printf("Smallest Element = %d\n", smallest);

    return 0;
}