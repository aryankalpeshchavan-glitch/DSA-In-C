#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX][100];
int top = -1;

void push(char page[]) {
    if (top == MAX - 1) {
        printf("History is full.\n");
    } else {
        top++;
        strcpy(stack[top], page);
    }
}

void pop() {
    if (top <= 0) {
        printf("No previous webpage available.\n");
    } else {
        printf("Going back from: %s\n", stack[top]);
        top--;
        printf("Current webpage: %s\n", stack[top]);
    }
}

void peek() {
    if (top == -1) {
        printf("No webpage opened.\n");
    } else {
        printf("Current webpage: %s\n", stack[top]);
    }
}

void display() {
    int i;

    if (top == -1) {
        printf("Browsing history is empty.\n");
    } else {
        printf("\nBrowsing History:\n");

        for (i = top; i >= 0; i--) {
            printf("%s\n", stack[i]);
        }
    }
}

int main() {
    int choice;
    char page[100];

    while (1) {
        printf("\n--- Browser Navigation ---\n");
        printf("1. Visit New Webpage\n");
        printf("2. Display Current Webpage\n");
        printf("3. Back\n");
        printf("4. Display Browsing History\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter webpage: ");
                scanf("%s", page);
                push(page);
                printf("Webpage visited successfully.\n");
                break;

            case 2:
                peek();
                break;

            case 3:
                pop();
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