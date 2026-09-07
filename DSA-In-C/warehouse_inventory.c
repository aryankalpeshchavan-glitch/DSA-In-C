#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int id;
    char name[50];
    int quantity;
    struct Product* next;
};

struct Product* head = NULL;

void insert() {
    struct Product* newNode = (struct Product*)malloc(sizeof(struct Product));
    printf("Enter Product ID: ");
    scanf("%d", &newNode->id);
    printf("Enter Product Name: ");
    scanf(" %[^\n]", newNode->name);
    printf("Enter Quantity: ");
    scanf("%d", &newNode->quantity);
    newNode->next = head;
    head = newNode;
    printf("Product inserted!\n");
}

void deleteProduct() {
    int id;
    printf("Enter Product ID to delete: ");
    scanf("%d", &id);
    struct Product *temp = head, *prev = NULL;
    if (temp != NULL && temp->id == id) {
        head = temp->next;
        free(temp);
        printf("Deleted!\n");
        return;
    }
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Not found!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Deleted!\n");
}

void display() {
    if (head == NULL) {
        printf("Inventory empty!\n");
        return;
    }
    struct Product* temp = head;
    printf("\nID\tName\t\tQuantity\n");
    printf("----------------------------\n");
    while (temp != NULL) {
        printf("%d\t%-15s\t%d\n", temp->id, temp->name, temp->quantity);
        temp = temp->next;
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert(); break;
            case 2: deleteProduct(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid!\n");
        }
    }
    return 0;
}