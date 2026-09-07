#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX][50];
int top = -1;

void push(char tray[]) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        strcpy(stack[top], tray);
        printf("Tray added successfully.\n");
    }
}

void pop() {
    if (top == -1) {
        printf("No trays available.\n");
    } else {
        printf("Issued Tray: %s\n", stack[top]);
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("No trays available.\n");
    } else {
        printf("Top Tray: %s\n", stack[top]);
    }
}

void display() {
    int i;

    if (top == -1) {
        printf("No trays available.\n");
    } else {
        printf("\nAvailable Trays:\n");

        for (i = top; i >= 0; i--) {
            printf("%s\n", stack[i]);
        }
    }
}

int main() {
    int choice;
    char tray[50];

    while (1) {
        printf("\n--- Cafeteria Tray Management ---\n");
        printf("1. Add Clean Tray\n");
        printf("2. Issue Top Tray\n");
        printf("3. Display Top Tray\n");
        printf("4. Display All Trays\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter tray name/number: ");
                scanf("%s", tray);
                push(tray);
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