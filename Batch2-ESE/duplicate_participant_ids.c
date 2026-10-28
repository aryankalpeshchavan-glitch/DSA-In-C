#include <stdio.h>
#include <stdlib.h>

struct Node {
    int id;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *tail = NULL, *node, *temp, *check;
    int n, i, id, found;

    printf("Enter number of participant IDs: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("No IDs entered.\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("Enter participant ID: ");
        scanf("%d", &id);

        node = malloc(sizeof(struct Node));
        if (node == NULL) {
            printf("Memory allocation failed.\n");
            while (head != NULL) {
                temp = head;
                head = head->next;
                free(temp);
            }
            return 1;
        }

        node->id = id;
        node->next = NULL;

        if (head == NULL)
            head = node;
        else
            tail->next = node;
        tail = node;
    }

    printf("Duplicate IDs: ");
    found = 0;

    for (node = head; node != NULL; node = node->next) {
        int earlier = 0;
        for (check = head; check != node; check = check->next) {
            if (check->id == node->id) {
                earlier = 1;
                break;
            }
        }

        if (earlier)
            continue;

        for (check = node->next; check != NULL; check = check->next) {
            if (check->id == node->id) {
                printf("%d ", node->id);
                found = 1;
                break;
            }
        }
    }

    if (!found)
        printf("None");
    printf("\n");

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}