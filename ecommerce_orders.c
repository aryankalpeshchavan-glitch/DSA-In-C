#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0;
int rear = -1;

void enqueue(int orders) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        queue[++rear] = orders;
    }
}

int dequeue() {
    if (front > rear) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        return queue[front++];
    }
}

int main() {
    int n, i;
    int orders;
    int total = 0;
    int busiestDay = 1;
    float average;

    printf("Enter number of days: ");
    scanf("%d", &n);

    printf("Enter number of orders for each day:\n");

    for (i = 0; i < n; i++) {
        printf("Day %d: ", i + 1);
        scanf("%d", &orders);
        enqueue(orders);
    }

    for (i = 0; i < n; i++) {
        total += queue[i];

        if (queue[i] > queue[busiestDay - 1])
            busiestDay = i + 1;
    }

    average = (float)total / n;

    printf("\nBusiest Day = Day %d", busiestDay);
    printf("\nAverage Daily Orders = %.2f", average);
    printf("\nTotal Monthly Orders = %d\n", total);

    return 0;
}