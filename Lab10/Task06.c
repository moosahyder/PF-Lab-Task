
#include <stdio.h>
#include <string.h>

int main()
{
    char names[5][50];
    char temp[50];

    for(int i = 0; i < 5; i++){
        printf("Enter student name %d: ", i + 1);
        scanf("%49s", names[i]);
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4 - i; j++){
            if(strcmp(names[j], names[j + 1]) > 0){
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    printf("\nSorted Student Names:\n");

    for(int i = 0; i < 5; i++){
        printf("%s\n", names[i]);
    }

    return 0;
}
