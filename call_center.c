#include <stdio.h>
#include <string.h>

#define MAX 100

char queue[MAX][50];
int front = 0;
int rear = -1;

void enqueue(char caller[]) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        rear++;
        strcpy(queue[rear], caller);
        printf("Call added successfully.\n");
    }
}

void dequeue() {
    if (front > rear) {
        printf("No callers waiting.\n");
    } else {
        printf("Answered Call: %s\n", queue[front]);
        front++;
    }
}

void display() {
    int i;

    if (front > rear) {
        printf("No callers waiting.\n");
    } else {
        printf("\nCallers Waiting:\n");

        for (i = front; i <= rear; i++) {
            printf("%s\n", queue[i]);
        }
    }
}

void count() {
    if (front > rear) {
        printf("Total Waiting Callers = 0\n");
    } else {
        printf("Total Waiting Callers = %d\n", rear - front + 1);
    }
}

int main() {
    int choice;
    char caller[50];

    while (1) {
        printf("\n--- Call Center Support ---\n");
        printf("1. Add Incoming Call\n");
        printf("2. Answer Next Call\n");
        printf("3. Display Callers Waiting\n");
        printf("4. Count Waiting Callers\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter caller name/ID: ");
                scanf("%s", caller);
                enqueue(caller);
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