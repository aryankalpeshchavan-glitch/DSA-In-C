#include <stdio.h>
#include <stdlib.h>

struct Product {
    int id;
    char name[50];
    int quantity;
    struct Product *next;
};

struct Product *head = NULL;

void addProduct() {
    struct Product *p = malloc(sizeof(struct Product));
    struct Product *temp;

    if (p == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter product ID: ");
    scanf("%d", &p->id);
    printf("Enter product name: ");
    scanf(" %49[^\n]", p->name);
    printf("Enter quantity: ");
    scanf("%d", &p->quantity);
    p->next = NULL;

    if (head == NULL)
        head = p;
    else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
    }
    printf("Product added.\n");
}

void deleteProduct() {
    int id;
    struct Product *temp = head, *prev = NULL;

    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Product not found.\n");
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Product deleted.\n");
}

void updateProduct() {
    int id, quantity;
    struct Product *temp = head;

    printf("Enter product ID: ");
    scanf("%d", &id);

    while (temp != NULL && temp->id != id)
        temp = temp->next;

    if (temp == NULL) {
        printf("Product not found.\n");
        return;
    }

    printf("Enter new quantity: ");
    scanf("%d", &quantity);
    temp->quantity = quantity;
    printf("Quantity updated.\n");
}

void displayInventory() {
    struct Product *temp = head;

    if (temp == NULL) {
        printf("Inventory is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("ID: %d, Name: %s, Quantity: %d\n", temp->id, temp->name, temp->quantity);
        temp = temp->next;
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add product\n2. Delete product\n3. Update quantity\n4. Display inventory\n5. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1)
            addProduct();
        else if (choice == 2)
            deleteProduct();
        else if (choice == 3)
            updateProduct();
        else if (choice == 4)
            displayInventory();
        else if (choice == 5)
            break;
        else
            printf("Invalid choice.\n");
    }

    while (head != NULL) {
        struct Product *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}