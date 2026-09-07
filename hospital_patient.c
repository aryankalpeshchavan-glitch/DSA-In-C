#include <stdio.h>
#include <string.h>

#define MAX 100

char queue[MAX][50];
int front = 0;
int rear = -1;

void enqueue(char patient[]) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        rear++;
        strcpy(queue[rear], patient);
        printf("Patient registered successfully.\n");
    }
}

void dequeue() {
    if (front > rear) {
        printf("No patients waiting.\n");
    } else {
        printf("Calling Patient: %s\n", queue[front]);
        front++;
    }
}

void peek() {
    if (front > rear) {
        printf("No patients waiting.\n");
    } else {
        printf("First Patient: %s\n", queue[front]);
    }
}

void display() {
    int i;

    if (front > rear) {
        printf("Waiting list is empty.\n");
    } else {
        printf("\nWaiting Patients:\n");

        for (i = front; i <= rear; i++) {
            printf("%s\n", queue[i]);
        }
    }
}

int main() {
    int choice;
    char patient[50];

    while (1) {
        printf("\n--- Hospital Patient Registration ---\n");
        printf("1. Register New Patient\n");
        printf("2. Call Next Patient\n");
        printf("3. Display First Patient\n");
        printf("4. Display Waiting List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter patient name: ");
                scanf("%s", patient);
                enqueue(patient);
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