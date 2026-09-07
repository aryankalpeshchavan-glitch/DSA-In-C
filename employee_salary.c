#include <stdio.h>

#define MAX 100

float queue[MAX];
int front = 0;
int rear = -1;

void enqueue(float salary) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        queue[++rear] = salary;
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
    int n, i;
    float salary;
    float total = 0;
    float average;
    float highest, lowest;
    int highestEmployee = 1;
    int lowestEmployee = 1;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    printf("Enter employee salaries:\n");

    for (i = 0; i < n; i++) {
        printf("Employee %d: ", i + 1);
        scanf("%f", &salary);
        enqueue(salary);
    }

    highest = queue[0];
    lowest = queue[0];

    for (i = 0; i < n; i++) {
        total += queue[i];

        if (queue[i] > highest) {
            highest = queue[i];
            highestEmployee = i + 1;
        }

        if (queue[i] < lowest) {
            lowest = queue[i];
            lowestEmployee = i + 1;
        }
    }

    average = total / n;

    printf("\nTotal Salary Expenditure = %.2f", total);
    printf("\nAverage Salary = %.2f", average);
    printf("\nHighest-Paid Employee = Employee %d", highestEmployee);
    printf("\nHighest Salary = %.2f", highest);
    printf("\nLowest-Paid Employee = Employee %d", lowestEmployee);
    printf("\nLowest Salary = %.2f\n", lowest);

    return 0;
}