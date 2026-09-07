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
        printf("Food order accepted.\n");
    }
}

void dequeue() {
    if (front > rear) {
        printf("No pending orders.\n");
    } else {
        printf("Served Order: %s\n", queue[front]);
        front++;
    }
}

void display() {
    int i;

    if (front > rear) {
        printf("No pending orders.\n");
    } else {
        printf("\nPending Food Orders:\n");

        for (i = front; i <= rear; i++) {
            printf("%s\n", queue[i]);
        }
    }
}

void count() {
    if (front > rear)
        printf("Remaining Orders = 0\n");
    else
        printf("Remaining Orders = %d\n", rear - front + 1);
}

int main() {
    int choice;
    char order[50];

    while (1) {
        printf("\n--- Food Court Order Processing ---\n");
        printf("1. Accept Food Order\n");
        printf("2. Serve Completed Order\n");
        printf("3. Display Pending Orders\n");
        printf("4. Count Remaining Orders\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter order name/ID: ");
                scanf("%s", order);
                enqueue(order);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                count();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}