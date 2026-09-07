#include <stdio.h>

#define MAX 30

float queue[MAX];
int front = 0;
int rear = -1;

void enqueue(float temperature) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        queue[++rear] = temperature;
    }
}

float dequeue() {
    if (front > rear) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        return queue[front++];
    }
}

int main() {
    int i;
    float temperature;
    float hottest, coldest;
    float sum = 0, average;

    printf("Enter temperatures for 30 days:\n");

    for (i = 0; i < 30; i++) {
        printf("Day %d: ", i + 1);
        scanf("%f", &temperature);
        enqueue(temperature);
    }

    hottest = queue[0];
    coldest = queue[0];

    for (i = 0; i < 30; i++) {
        if (queue[i] > hottest)
            hottest = queue[i];

        if (queue[i] < coldest)
            coldest = queue[i];

        sum += queue[i];
    }

    average = sum / 30;

    printf("\nHottest Temperature = %.2f", hottest);
    printf("\nColdest Temperature = %.2f", coldest);
    printf("\nAverage Temperature = %.2f\n", average);

    return 0;
}