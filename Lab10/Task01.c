#include <stdio.h>
#include <string.h>

int main(){
    char name[100];
    char copy[100];

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    for (int i = 0; name[i] != '\0'; i++){
        if (name[i] == '\n'){
            name[i] = '\0';
            break;
        }
    }
    printf("Length of name: %lu", strlen(name));

    strcpy(copy, name);
    printf("\nCopied name: %s", copy);
    printf("\nSize of name array: %zu bytes", sizeof(name));

    return 0;
}