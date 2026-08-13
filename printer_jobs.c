#include <stdio.h>
#include <string.h>

#define MAX 100

char queue[MAX][50];
int front = 0;
int rear = -1;

void enqueue(char job[]) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        rear++;
        strcpy(queue[rear], job);
        printf("Print job added successfully.\n");
    }
}

void dequeue() {
    if (front > rear) {
        printf("Printer queue is empty.\n");
    } else {
        printf("Processing Print Job: %s\n", queue[front]);
        front++;
    }
}

void display() {
    int i;

    if (front > rear) {
        printf("No pending print jobs.\n");
    } else {
        printf("\nPending Print Jobs:\n");

        for (i = front; i <= rear; i++) {
            printf("%s\n", queue[i]);
        }
    }
}

void isEmpty() {
    if (front > rear)
        printf("Printer Queue is Empty.\n");
    else
        printf("Printer Queue is Not Empty.\n");
}

int main() {
    int choice;
    char job[50];

    while (1) {
        printf("\n--- Printer Job Scheduling ---\n");
        printf("1. Add Print Job\n");
        printf("2. Process Next Print Job\n");
        printf("3. Display Pending Jobs\n");
        printf("4. Check Queue Empty\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter job name/ID: ");
                scanf("%s", job);
                enqueue(job);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                isEmpty();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}