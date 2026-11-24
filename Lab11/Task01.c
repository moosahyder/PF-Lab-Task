
#include <stdio.h>

struct Flight {
    int flightNumber;
    char departureCity[50];
    char destinationCity[50];
    char date[20];
    int availableSeats;
};

int main() {
    struct Flight f;
    int choice;

    printf("Enter Flight Number: ");
    scanf("%d", &f.flightNumber);

    printf("Enter Departure City: ");
    scanf(" %[^\n]", f.departureCity);

    printf("Enter Destination City: ");
    scanf(" %[^\n]", f.destinationCity);

    printf("Enter Date: ");
    scanf(" %[^\n]", f.date);

    printf("Enter Available Seats: ");
    scanf("%d", &f.availableSeats);

    do {
        printf("\n===== FLIGHT MANAGEMENT SYSTEM =====\n");
        printf("1. Display Flight Details\n");
        printf("2. Book a Seat\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\nFlight Number: %d\n", f.flightNumber);
                printf("Departure City: %s\n", f.departureCity);
                printf("Destination City: %s\n", f.destinationCity);
                printf("Date: %s\n", f.date);
                printf("Available Seats: %d\n", f.availableSeats);
                break;

            case 2:
                if (f.availableSeats > 0) {
                    f.availableSeats--;
                    printf("\nSeat booked successfully!\n");
                    printf("Remaining Seats: %d\n",
                           f.availableSeats);
                }
                else {
                    printf("\nSorry! No seats available.\n");
                }
                break;

            case 3:
                printf("\nExiting Program...\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while (choice != 3);

    return 0;
}

