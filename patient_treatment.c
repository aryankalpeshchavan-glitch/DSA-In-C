#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX][100];
int top = -1;

void push(char update[]) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        strcpy(stack[top], update);
        printf("Treatment update added.\n");
    }
}

void pop() {
    if (top == -1) {
        printf("No update available to undo.\n");
    } else {
        printf("Undoing update: %s\n", stack[top]);
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("No treatment record available.\n");
    } else {
        printf("Current Treatment Record: %s\n", stack[top]);
    }
}

void display() {
    int i;

    if (top == -1) {
        printf("Update history is empty.\n");
    } else {
        printf("\nTreatment Update History:\n");

        for (i = top; i >= 0; i--) {
            printf("%s\n", stack[i]);
        }
    }
}

int main() {
    int choice;
    char update[100];

    while (1) {
        printf("\n--- Patient Treatment Record ---\n");
        printf("1. Add Treatment Update\n");
        printf("2. Undo Latest Update\n");
        printf("3. Display Current Treatment\n");
        printf("4. Display Update History\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter treatment update: ");
                scanf(" %[^\n]", update);
                push(update);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}