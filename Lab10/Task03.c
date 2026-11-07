#include <stdio.h>
#include <string.h>

int main(){

    char correctPassword[] = "lab10pass";
    char password[50];

    printf("Enter password: ");
    scanf("%49s", password);
    
    if(strcmp(password, correctPassword) == 0){
        printf("Access Granted\n");
    }else{
        printf("Access denied\n");
    }

    if(strncmp(password, correctPassword, 3) == 0){
        printf("First 3 characters match.");
    }else{
        printf("First 3 characters do not match.");
    }

    return 0;

}