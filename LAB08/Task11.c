#include <stdio.h>

int square(int x) {
    return x * x;
}

int negate(int x) {
    return -x;
}

int isEven(int x) {
    return x % 2 == 0;
}

int isPositive(int x) {
    return x > 0;
}

void applyToArray(int *arr, int n, int (*fn)(int)) {
    for (int i = 0; i < n; i++) {
        arr[i] = fn(arr[i]);
    }
}

int countIf(const int *arr, int n, int (*pred)(int)) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (pred(arr[i])) {
            count++;
        }
    }

    return count;
}

void printGeneric(void *data, char type, int n) {
    int i;

    switch (type) {
        case 'i': {
            int *arr = (int *)data;

            for (i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        }

        case 'f': {
            float *arr = (float *)data;

            for (i = 0; i < n; i++) {
                printf("%.2f ", arr[i]);
            }
            printf("\n");
            break;
        }

        case 'c': {
            char *arr = (char *)data;

            for (i = 0; i < n; i++) {
                printf("%c ", arr[i]);
            }
            printf("\n");
            break;
        }

        default:
            printf("Invalid type '%c' for printGeneric\n", type);
    }
}

int main(void) {
    int arr[] = {3, -2, 8, -5, 6};
    int n, i;

    printf("Enter n (1-50): ");

    if (scanf("%d", &n) != 1 || n < 1 || n > 50) {
        printf("Invalid value of n!\n");
        return 1;
    }

    if (n > (int)(sizeof(arr) / sizeof(arr[0]))) {
        printf("n cannot exceed the array size of 5!\n");
        return 1;
    }

    printf("Original: ");
    printGeneric(arr, 'i', n);
    applyToArray(arr, n, negate);
    printf("After negate: ");
    printGeneric(arr, 'i', n);
    printf("Positive values after negate: %d\n",
           countIf(arr, n, isPositive));
    printf("Even values after negate: %d\n",
           countIf(arr, n, isEven));
    float values[] = {1.50f, 2.25f};
    printf("Float print (type f): ");
    printGeneric(values, 'f', 2);
    printGeneric(arr, 'x', n);

    return 0;
}