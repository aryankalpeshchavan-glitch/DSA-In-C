#include <stdio.h>
#include <string.h>

#define MAX 100

char queue[MAX][50];
int front = 0;
int rear = -1;

void enqueue(char order[]) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        rear++;
        strcpy(queue[rear], order);
        printf("Order added successfully.\n");
    }
}

void dequeue() {
    if (front > rear) {
        printf("No pending orders.\n");
    } else {
        printf("Dispatched Order: %s\n", queue[front]);
        front++;
    }
}

void peek() {
    if (front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("First Order: %s\n", queue[front]);
    }
}

void display() {
    int i;

    if (front > rear) {
        printf("No pending dispatches.\n");
    } else {
        printf("\nPending Orders:\n");

        for (i = front; i <= rear; i++) {
            printf("%s\n", queue[i]);
        }
    }
}

int main() {
    int choice;
    char order[50];

    while (1) {
        printf("\n--- Online Shopping Order Dispatch ---\n");
        printf("1. Add Confirmed Order\n");
        printf("2. Dispatch Next Order\n");
        printf("3. Show First Order\n");
        printf("4. Display Pending Orders\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter order ID: ");
                scanf("%s", order);
                enqueue(order);
                break;

            case 2:
                dequeue();
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