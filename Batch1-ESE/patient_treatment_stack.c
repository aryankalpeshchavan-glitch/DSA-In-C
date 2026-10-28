#include <stdio.h>
#include <string.h>

#define MAX 100
#define SIZE 100

int main() {
    char updates[MAX][SIZE], text[SIZE];
    int top = -1, choice, i;

    while (1) {
        printf("\n1. Add treatment update\n2. Undo latest update\n3. Display current record\n4. Display update history\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            if (top == MAX - 1) {
                printf("Update history is full.\n");
            } else {
                printf("Enter treatment update: ");
                fgets(text, SIZE, stdin);
                text[strcspn(text, "\n")] = '\0';
                strcpy(updates[++top], text);
            }
        } else if (choice == 2) {
            if (top == -1)
                printf("No update to undo.\n");
            else
                printf("Undone: %s\n", updates[top--]);
        } else if (choice == 3) {
            if (top == -1)
                printf("No treatment record.\n");
            else
                printf("Current record: %s\n", updates[top]);
        } else if (choice == 4) {
            if (top == -1)
                printf("No update history.\n");
            else
                for (i = top; i >= 0; i--)
                    printf("%s\n", updates[i]);
        } else if (choice == 5) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}