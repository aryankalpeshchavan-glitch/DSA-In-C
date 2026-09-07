#include <stdio.h>
#include <stdlib.h>

struct Node {
    int id;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int id) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->id = id;
    newNode->next = head;
    head = newNode;
}

void displayDuplicates() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* ptr1 = head;
    int found = 0;
    printf("Duplicate IDs: ");
    while (ptr1 != NULL) {
        struct Node* ptr2 = ptr1->next;
        while (ptr2 != NULL) {
            if (ptr1->id == ptr2->id) {
                printf("%d ", ptr1->id);
                found = 1;
                break;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    if (!found)
        printf("None");
    printf("\n");
}

void displayList() {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->id);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, id;
    printf("Enter number of IDs: ");
    scanf("%d", &n);
    printf("Enter %d IDs:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &id);
        insert(id);
    }
    displayList();
    displayDuplicates();
    return 0;
}