#include <stdio.h>
#include <string.h>

#define MAX 100
#define SIZE 100

int main() {
    char callers[MAX][SIZE], name[SIZE];
    int front = 0, rear = -1, choice, i;

    while (1) {
        printf("\n1. Add incoming call\n2. Answer next call\n3. Display waiting callers\n4. Count waiting callers\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            if (rear == MAX - 1) {
                printf("Queue is full.\n");
            } else {
                printf("Enter caller name: ");
                fgets(name, SIZE, stdin);
                name[strcspn(name, "\n")] = '\0';
                strcpy(callers[++rear], name);
                printf("Call added.\n");
            }
        } else if (choice == 2) {
            if (front > rear)
                printf("No calls waiting.\n");
            else
                printf("Answering call from: %s\n", callers[front++]);
        } else if (choice == 3) {
            if (front > rear)
                printf("No callers waiting.\n");
            else
                for (i = front; i <= rear; i++)
                    printf("%s\n", callers[i]);
        } else if (choice == 4) {
            printf("Waiting callers: %d\n", rear - front + 1);
        } else if (choice == 5) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}