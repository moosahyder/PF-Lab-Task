#include <stdio.h>
#include <string.h>

int main(){

    char firstName[50];
    char lastName[50];
    char fullName[100];

    printf("Enter first Name: ");
    scanf("%49s", &firstName);

    printf("Enter last Name: ");
    scanf("%49s", &lastName);

    strcat(fullName, firstName);
    strcat(fullName, " ");
    strcat(fullName, lastName);

    printf("Full name: %s", fullName);

    return 0;
}