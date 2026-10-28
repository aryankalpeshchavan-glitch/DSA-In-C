#include <stdio.h>

#define MAX 100

int main() {
    int boxes[MAX], top = -1, choice, box, i;

    while (1) {
        printf("\n1. Add box\n2. Remove top box\n3. Display top box\n4. Display all boxes\n5. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (top == MAX - 1) {
                printf("Stack is full.\n");
            } else {
                printf("Enter box ID: ");
                scanf("%d", &box);
                boxes[++top] = box;
                printf("Box added.\n");
            }
        } else if (choice == 2) {
            if (top == -1)
                printf("No boxes to remove.\n");
            else
                printf("Removed box: %d\n", boxes[top--]);
        } else if (choice == 3) {
            if (top == -1)
                printf("Stack is empty.\n");
            else
                printf("Top box: %d\n", boxes[top]);
        } else if (choice == 4) {
            if (top == -1)
                printf("Stack is empty.\n");
            else
                for (i = top; i >= 0; i--)
                    printf("%d\n", boxes[i]);
        } else if (choice == 5) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}