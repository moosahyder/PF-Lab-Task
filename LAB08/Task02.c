#include <stdio.h>

void swapValues(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int A, B;

    printf("Enter price A: ");
    scanf("%d", &A);

    printf("Enter price B: ");
    scanf("%d", &B);

    printf("Before swap: A = %d, B = %d\n", A, B);

    swapValues(&A, &B);

    printf("After swap:  A = %d, B = %d\n", A, B);

    return 0;
}