#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int attendance) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = attendance;
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
    int attendance;
    int present = 0;
    int absent = 0;
    float percentage;

    printf("Enter number of days: ");
    scanf("%d", &n);

    printf("Enter attendance (1 = Present, 0 = Absent):\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &attendance);
        push(attendance);
    }

    for (i = 0; i < n; i++) {
        if (stack[i] == 1)
            present++;
        else if (stack[i] == 0)
            absent++;
    }

    percentage = ((float)present / n) * 100;

    printf("\nAttendance Percentage = %.2f%%", percentage);
    printf("\nTotal Number of Absences = %d\n", absent);

    return 0;
}