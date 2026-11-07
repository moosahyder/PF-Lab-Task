
#include <stdio.h>

int main()
{
    FILE *fp;
    char name[50];

    fp = fopen("students.txt", "w");

    if(fp == NULL){
        printf("File could not be opened.");
        return 1;
    }

    printf("Enter 3 student names:\n");

    for(int i = 0; i < 3; i++){
        scanf("%49s", name);
        fprintf(fp, "%s\n", name);
    }

    fclose(fp);

    fp = fopen("students.txt", "r");

    if(fp == NULL){
        printf("File could not be opened.");
        return 1;
    }

    printf("\nNames read from students.txt:\n");

    int count = 0;

    while(fgets(name, sizeof(name), fp) != NULL){
        count++;
        printf("%d. %s", count, name);
    }

    printf("\nTotal students in file: %d\n", count);
    fclose(fp);

    return 0;
}
