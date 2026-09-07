#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX][50];
int top = -1;

void push(char box[]) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        strcpy(stack[top], box);
        printf("Box added successfully.\n");
    }
}

void pop() {
    if (top == -1) {
        printf("No boxes available.\n");
    } else {
        printf("Removed Box: %s\n", stack[top]);
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("No boxes available.\n");
    } else {
        printf("Top Box: %s\n", stack[top]);
    }
}

void display() {
    int i;

    if (top == -1) {
        printf("Warehouse stack is empty.\n");
    } else {
        printf("\nStored Boxes:\n");

        for (i = top; i >= 0; i--) {
            printf("%s\n", stack[i]);
        }
    }
}

int main() {
    int choice;
    char box[50];

    while (1) {
        printf("\n--- Warehouse Box Storage ---\n");
        printf("1. Add Box\n");
        printf("2. Remove Top Box\n");
        printf("3. Display Top Box\n");
        printf("4. Display All Boxes\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter box number/name: ");
                scanf("%s", box);
                push(box);
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