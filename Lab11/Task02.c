
#include <stdio.h>

struct Movie {
    char title[50];
    char genre[30];
    char director[50];
    int releaseYear;
    float rating;
};

int main() {
    struct Movie movies[100];
    int count = 0;
    int choice;
    int i;
    char searchGenre[30];
    int found;

    do {
        printf("\n===== MOVIE MANAGEMENT SYSTEM =====\n");
        printf("1. Add New Movie\n");
        printf("2. Search Movie by Genre\n");
        printf("3. Display All Movies\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                if (count < 100) {

                    printf("\nEnter Movie Title: ");
                    scanf(" %[^\n]", movies[count].title);

                    printf("Enter Genre: ");
                    scanf(" %[^\n]", movies[count].genre);

                    printf("Enter Director: ");
                    scanf(" %[^\n]", movies[count].director);

                    printf("Enter Release Year: ");
                    scanf("%d", &movies[count].releaseYear);

                    printf("Enter Rating: ");
                    scanf("%f", &movies[count].rating);

                    count++;

                    printf("\nMovie Added Successfully!\n");
                }
                else {
                    printf("\nMovie Storage is Full!\n");
                }
                break;

            case 2:
                printf("\nEnter Genre to Search: ");
                scanf(" %[^\n]", searchGenre);

                found = 0;

                for (i = 0; i < count; i++) {

                    if (strcmp(movies[i].genre,
                               searchGenre) == 0) {

                        printf("\nMovie Found!\n");
                        printf("Title: %s\n", movies[i].title);
                        printf("Genre: %s\n", movies[i].genre);
                        printf("Director: %s\n", movies[i].director);
                        printf("Release Year: %d\n",
                               movies[i].releaseYear);
                        printf("Rating: %.1f\n", movies[i].rating);

                        found = 1;
                    }
                }

                if (found == 0) {
                    printf("\nNo Movie Found in This Genre.\n");
                }
                break;

            case 3:
                if (count == 0) {
                    printf("\nNo Movies Available.\n");
                }
                else {
                    for (i = 0; i < count; i++) {

                        printf("\nMovie %d\n", i + 1);
                        printf("Title: %s\n", movies[i].title);
                        printf("Genre: %s\n", movies[i].genre);
                        printf("Director: %s\n", movies[i].director);
                        printf("Release Year: %d\n",
                               movies[i].releaseYear);
                        printf("Rating: %.1f\n", movies[i].rating);
                    }
                }
                break;

            case 4:
                printf("\nExiting Program...\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while (choice != 4);

    return 0;
}
