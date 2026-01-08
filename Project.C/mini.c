#include <stdio.h>

#define TOTAL_SEATS 10

// Function prototypes
void displaySeats(int seats[]);
void bookSeat(int seats[]);
void cancelSeat(int seats[]);

int main() {
    int seats[TOTAL_SEATS] = {0}; // Step 1 & 2: Initialize all 10 seats to 0 (Available)
    int choice;

    printf("--- Welcome to Railway Seat Reservation System ---\n");

    do {
        // Step 3 & 4: Menu display and user choice
        printf("\n1. View Seats\n2. Book a Seat\n3. Cancel Booking\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats(seats);
                break;
            case 2:
                bookSeat(seats);
                break;
            case 3:
                cancelSeat(seats);
                break;
            case 4:
                printf("Exiting system. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4); // Step 9 & 10: Repeat until exit

    return 0;
}

// Step 8: Display the current status of all seats
void displaySeats(int seats[]) {
    printf("\nSeat Status (0 = Available, 1 = Booked):\n");
    for (int i = 0; i < TOTAL_SEATS; i++) {
        printf("Seat %d: [%d]  ", i + 1, seats[i]);
        if ((i + 1) % 5 == 0) printf("\n"); // Format into rows
    }
}

// Step 5: Booking logic
void bookSeat(int seats[]) {
    int seatNum;
    printf("Enter seat number to book (1-%d): ", TOTAL_SEATS);
    scanf("%d", &seatNum);

    // Array index is seatNum - 1
    if (seatNum < 1 || seatNum > TOTAL_SEATS) {
        printf("Invalid seat number!\n");
    } else if (seats[seatNum - 1] == 1) {
        printf("Sorry, Seat %d is already booked.\n", seatNum);
    } else {
        seats[seatNum - 1] = 1; // Mark as booked
        printf("Seat %d successfully booked!\n", seatNum);
    }
}

// Step 6: Cancellation logic
void cancelSeat(int seats[]) {
    int seatNum;
    printf("Enter seat number to cancel (1-%d): ", TOTAL_SEATS);
    scanf("%d", &seatNum);

    if (seatNum < 1 || seatNum > TOTAL_SEATS) {
        printf("Invalid seat number!\n");
    } else if (seats[seatNum - 1] == 0) {
        printf("Seat %d is not currently booked.\n", seatNum);
    } else {
        seats[seatNum - 1] = 0; // Mark as available
        printf("Booking for Seat %d has been cancelled.\n", seatNum);
    }
}