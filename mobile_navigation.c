#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX][50];
int top = -1;

void push(char screen[]) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        strcpy(stack[top], screen);
        printf("Screen opened successfully.\n");
    }
}

void pop() {
    if (top <= 0) {
        printf("No previous screen available.\n");
    } else {
        printf("Closing screen: %s\n", stack[top]);
        top--;
        printf("Current Screen: %s\n", stack[top]);
    }
}

void peek() {
    if (top == -1) {
        printf("No screen is open.\n");
    } else {
        printf("Current Screen: %s\n", stack[top]);
    }
}

int main() {
    int choice;
    char screen[50];

    while (1) {
        printf("\n--- Mobile Application Navigation ---\n");
        printf("1. Open New Screen\n");
        printf("2. Back\n");
        printf("3. Display Current Screen\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter screen name: ");
                scanf("%s", screen);
                push(screen);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}