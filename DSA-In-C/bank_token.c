#include <stdio.h>
#include <string.h>

#define MAX 100

char queue[MAX][50];
int front = 0;
int rear = -1;

void enqueue(char customer[]) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        rear++;
        strcpy(queue[rear], customer);
        printf("Customer added to queue.\n");
    }
}

void dequeue() {
    if (front > rear) {
        printf("No customers waiting.\n");
    } else {
        printf("Serving Customer: %s\n", queue[front]);
        front++;
    }
}

void peek() {
    if (front > rear) {
        printf("No customer waiting.\n");
    } else {
        printf("Next Customer: %s\n", queue[front]);
    }
}

void display() {
    int i;

    if (front > rear) {
        printf("No customers waiting.\n");
    } else {
        printf("\nWaiting Customers:\n");

        for (i = front; i <= rear; i++) {
            printf("%s\n", queue[i]);
        }
    }
}

int main() {
    int choice;
    char customer[50];

    while (1) {
        printf("\n--- Bank Token Management System ---\n");
        printf("1. Add Customer\n");
        printf("2. Serve Customer\n");
        printf("3. Display Next Customer\n");
        printf("4. Display All Waiting Customers\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer/token number: ");
                scanf("%s", customer);
                enqueue(customer);
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