
#include <stdio.h>

int add(int a, int b, int *result) {
    *result = a + b;
    return 1;
}

int subtract(int a, int b, int *result) {
    *result = a - b;
    return 1;
}

int multiply(int a, int b, int *result) {
    *result = a * b;
    return 1;
}

int divide(int a, int b, int *result) {
    if (b == 0) {
        return 0;
    }

    *result = a / b;
    return 1;
}

int main(void) {
    int (*ops[])(int, int, int *) = {
        add, subtract, multiply, divide
    };

    const char *names[] = {
        "Add", "Subtract", "Multiply", "Divide"
    };

    int choice, a, b, result;
    int success;

    while (1) {
        printf("\n1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Exit\n");
        printf("Choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            return 1;
        }

        if (choice == 5) {
            printf("Goodbye.\n");
            break;
        }

        if (choice < 1 || choice > 5) {
            printf("Invalid choice\n");
            continue;
        }

        printf("Enter a and b: ");
        if (scanf("%d %d", &a, &b) != 2) {
            printf("Invalid input\n");
            return 1;
        }

        success = ops[choice - 1](a, b, &result);

        if (!success) {
            printf("Error: division by zero\n");
        } else {
            printf("%s result: %d\n",
                   names[choice - 1], result);
        }
    }

    return 0;
}