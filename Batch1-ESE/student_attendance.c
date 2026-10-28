#include <stdio.h>

int main() {
    int days, attendance, present = 0, absent = 0;
    float percentage;

    printf("Enter total number of days: ");
    scanf("%d", &days);

    if (days <= 0) {
        printf("Invalid number of days\n");
        return 0;
    }

    printf("Enter attendance for each day (1 = Present, 0 = Absent):\n");
    for (int i = 0; i < days; i++) {
        scanf("%d", &attendance);
        if (attendance == 1)
            present++;
        else if (attendance == 0)
            absent++;
        else {
            printf("Invalid input. Enter 1 or 0.\n");
            i--;
        }
    }

    percentage = (float)present / days * 100;
    printf("Attendance Percentage: %.2f%%\n", percentage);
    printf("Total Absences: %d\n", absent);

    return 0;
}