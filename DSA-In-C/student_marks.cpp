#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int mark) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = mark;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int main() {
    int n, i;
    int mark, highest, lowest;
    int sum = 0, count = 0;
    float average;

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter marks:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &mark);
        push(mark);
    }

    highest = stack[0];
    lowest = stack[0];

    for (i = 0; i <= top; i++) {
        if (stack[i] > highest)
            highest = stack[i];

        if (stack[i] < lowest)
            lowest = stack[i];

        sum += stack[i];
    }

    average = (float)sum / n;

    for (i = 0; i <= top; i++) {
        if (stack[i] > average)
            count++;
    }

    printf("\nHighest Marks = %d", highest);
    printf("\nLowest Marks = %d", lowest);
    printf("\nAverage Marks = %.2f", average);
    printf("\nStudents Above Average = %d\n", count);

    return 0;
}