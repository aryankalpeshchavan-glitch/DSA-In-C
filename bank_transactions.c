#include <stdio.h>

#define MAX 100

float stack[MAX];
int top = -1;

void push(float deposit) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = deposit;
    }
}

float pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int main() {
    int n, i;
    float deposit;
    float total = 0;
    float average;
    float highest;
    int highestDay = 1;

    printf("Enter number of days: ");
    scanf("%d", &n);

    printf("Enter daily deposits:\n");

    for (i = 0; i < n; i++) {
        printf("Day %d: ", i + 1);
        scanf("%f", &deposit);
        push(deposit);
    }

    highest = stack[0];

    for (i = 0; i < n; i++) {
        total += stack[i];

        if (stack[i] > highest) {
            highest = stack[i];
            highestDay = i + 1;
        }
    }

    average = total / n;

    printf("\nTotal Deposits = %.2f", total);
    printf("\nAverage Deposit = %.2f", average);
    printf("\nHighest Deposit = %.2f", highest);
    printf("\nHighest Deposit Day = Day %d\n", highestDay);

    return 0;
}