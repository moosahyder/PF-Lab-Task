#include <stdio.h>
#include <string.h>

int main(){

    char cities[5][50];
    int maxlength = 0;
    int maxindex = 0;

    for(int i=0; i<5; i++){
        printf("Enter city %d: ", i+1);
        fgets(cities[i], sizeof(cities[i]), stdin);
    }

    for(int i=0; i<5; i++){

        for(int j=0; cities[i][j]!= 0; j++){

            if(cities[i][j]== '\n'){

                cities[i][j] = '\0';
                break;
            }
        }
    }

    for(int i=0; i<5; i++){
        int max = strlen(cities[i]);
        if(max > maxlength){
            maxlength = max;
            maxindex = i;
        }
    }

    printf("\nAll Cities:\n");
    for (int i = 0; i < 5; i++){
        printf("%s\n", cities[i]);
    }

    printf("Longest City: %s\n", cities[maxindex]);
    printf("Length: %d\n", maxlength);

    return 0;
}