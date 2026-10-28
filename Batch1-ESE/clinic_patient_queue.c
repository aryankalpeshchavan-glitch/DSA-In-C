#include <stdio.h>
#include <string.h>

#define MAX 100
#define SIZE 100

int main() {
    char patients[MAX][SIZE], name[SIZE];
    int front = 0, rear = -1, choice, i;

    while (1) {
        printf("\n1. Register patient\n2. Call next patient\n3. Display first waiting patient\n4. Show waiting list\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            if (rear == MAX - 1) {
                printf("Queue is full.\n");
            } else {
                printf("Enter patient name: ");
                fgets(name, SIZE, stdin);
                name[strcspn(name, "\n")] = '\0';
                strcpy(patients[++rear], name);
                printf("Patient registered.\n");
            }
        } else if (choice == 2) {
            if (front > rear)
                printf("No patients waiting.\n");
            else
                printf("Calling patient: %s\n", patients[front++]);
        } else if (choice == 3) {
            if (front > rear)
                printf("No patients waiting.\n");
            else
                printf("First waiting patient: %s\n", patients[front]);
        } else if (choice == 4) {
            if (front > rear)
                printf("No patients waiting.\n");
            else
                for (i = front; i <= rear; i++)
                    printf("%s\n", patients[i]);
        } else if (choice == 5) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}