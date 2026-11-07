#include <stdio.h>
#include <string.h>

int main(){
    
    char sentence[200];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    char *p;
    p = strchr(sentence, 'a');
    printf("First 'a' found at index %ld\n", p - sentence);

    if (strstr(sentence, "good") != NULL){
        printf("Word 'good' found.\n");
        }else{
        printf("Word 'good' not found.\n");
    }
}