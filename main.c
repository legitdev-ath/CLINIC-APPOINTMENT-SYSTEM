#include <stdio.h>
#include <string.h>
#define MAX_APPTS 5
typedef struct {
    char name[20];
    char problem[50];
    char date[15];
} Appointment;
Appointment appts[MAX_APPTS];
int count = 0;
void requestAppointment() {
    char n[20], p[50], d[15];
    int isAvailable = 1;
    int year, month, day;
    int i;
    if (count >= MAX_APPTS) {
        printf("\nBooking Failed: Clinic is fully booked (Max %d).\n", MAX_APPTS);
        return;
    }
    printf("Enter patient name: ");
    scanf("%20s", n);
    printf("Enter problem (brief description): ");
    scanf("%50s", p);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%15s", d);

    if (sscanf(d, "%d-%d-%d", &year, &month, &day) != 3 || month < 1 || month > 12 || day < 1 || day > 31) {
        printf("Date Error: Check format (YYYY-MM-DD), Month (1-12), and Day (1-31).\n");
        return;
    }
    for (i = 0; i < count; i++) {
        if (strcmp(appts[i].date, d) == 0) {
            isAvailable = 0;
            break;
        }
    }
    if (isAvailable) {
        char confirm;
        printf("Confirm appointment? (y/n): ");
        scanf(" %c", &confirm);

        if (confirm == 'y' || confirm == 'Y') {
            // Book the appointment
            strcpy(appts[count].name, n);
            strcpy(appts[count].problem, p);
            strcpy(appts[count].date, d);
            count++;
            printf("Appointment booked for %s on %s.\n", n, d);
        } else {
            printf("Appointment cancelled.\n");
        }
    } else {
        printf("Date %s is already taken. Please choose another.\n", d);
    }
}
void viewAppointments() {
    int i;
    if (count == 0) {
        printf("\nNo appointments in the queue.\n");
        return;
    }
    printf("\n Appointments Queue (%d total) \n", count);
    for (i = 0; i < count; i++) {
        printf("%d. Patient: %s\n", i + 1, appts[i].name);
        printf("    Date: %s\n", appts[i].date);
        printf("    Problem: %s\n", appts[i].problem);
    }
}
int main() {
    int choice;
    while (1) {
        printf("\n Clinic Appointment System \n");
        printf("1. Request Appointment (Patient)\n");
        printf("2. View Appointments (Doctor)\n");
        printf("3. Exit\n");
        printf("Choose option: ");

        if (scanf("%d", &choice) != 1) {
             printf("Invalid input. Please enter a number.\n");
             while(getchar() != '\n');
             continue;
        }
        if (choice == 1) {
            requestAppointment();
        } else if (choice == 2) {
            viewAppointments();
        } else if (choice == 3) {
            printf("Bye, Get well soon!!\n");
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}