#include <stdio.h>

int main() {
    int days, i, orders, total = 0, bestDay = 1, bestOrders = -1;
    float average;

    printf("Enter number of days: ");
    scanf("%d", &days);

    if (days <= 0) {
        printf("Invalid number of days.\n");
        return 0;
    }

    for (i = 1; i <= days; i++) {
        printf("Enter orders for day %d: ", i);
        scanf("%d", &orders);

        if (orders < 0) {
            printf("Orders cannot be negative.\n");
            i--;
            continue;
        }

        total += orders;
        if (orders > bestOrders) {
            bestOrders = orders;
            bestDay = i;
        }
    }

    average = (float)total / days;

    printf("Busiest Day: Day %d\n", bestDay);
    printf("Average Daily Orders: %.2f\n", average);
    printf("Total Monthly Orders: %d\n", total);

    return 0;
}